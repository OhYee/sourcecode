---
title: UPN第一个样例
date: 2017-07-05 16:55:09
categories: 
    - 笔记
    - UNIX网络编程
tags:
    - Linux
    - socket
---

一般情况下第一个样例都应该是简单并且容易让人产生兴趣的，但是UPN的第一个样例对于没有写过的人而言是第一个考验  

<!--more-->


由于官方代码大量使用 `upn.h` 头文件，经常会导致不知道函数从何而来  
因此建议还是自己徒手编译  

本样例需要用到的头文件如下(包括简单的说明):

```cpp
#include <arpa/inet.h>  //inet_ntop()、inet_ntoa()等
#include <memory.h>     //memset
#include <netinet/in.h> //struct sockaddr_in、PROTO_ICMP、INADDR_ANY等
#include <stdio.h>      //printf
#include <stdlib.h>     //exit
#include <sys/socket.h> //socket、bind、connect、struct sockaddr
#include <sys/types.h>  //类型定义
#include <time.h>       //time
#include <unistd.h>     //read
```

本样例由两部分组成:服务端和用户端  
尽管按照书上有 `206.168.112.96` 这个IP地址，不过在我的测试中并不能成功连接  
因此，可以使用P5的代码实现客户端，用P10的代码实现服务端  

由于服务端需要监听端口，因此该部分<span style="color:red">**需要root权限**</span>  

另外，服务端和客户端都应该是 `htons(13)`  (`htons`和`htonl`存在区别)

设计到的几个函数定义如下


# 函数定义
> [百度百科-socket](http://baike.baidu.com/item/socket/281150)
> {% fold %}
## 创建
- 函数原型：
`int socket(int domain, int type, int protocol);`
- 参数说明：
    - domain：协议域，又称协议族（family）。常用的协议族有AF_INET、AF_INET6、AF_LOCAL（或称AF_UNIX，Unix域Socket）、AF_ROUTE等。协议族决定了socket的地址类型，在通信中必须采用对应的地址，如AF_INET决定了要用ipv4地址（32位的）与端口号（16位的）的组合、AF_UNIX决定了要用一个绝对路径名作为地址。
    - type：指定Socket类型。常用的socket类型有SOCK_STREAM、SOCK_DGRAM、SOCK_RAW、SOCK_PACKET、SOCK_SEQPACKET等。流式Socket（SOCK_STREAM）是一种面向连接的Socket，针对于面向连接的TCP服务应用。数据报式Socket（SOCK_DGRAM）是一种无连接的Socket，对应于无连接的UDP服务应用。
    - protocol：指定协议。常用协议有IPPROTO_TCP、IPPROTO_UDP、IPPROTO_STCP、IPPROTO_TIPC等，分别对应TCP传输协议、UDP传输协议、STCP传输协议、TIPC传输协议。
- 注意：
    1. type和protocol不可以随意组合，如SOCK_STREAM不可以跟IPPROTO_UDP组合。当第三个参数为0时，会自动选择第二个参数类型对应的默认协议。
    2. WindowsSocket下protocol参数中不存在IPPROTO_STCP
- 返回值：
    如果调用成功就返回新创建的套接字的描述符，如果失败就返回INVALID_SOCKET（Linux下失败返回-1）。
    套接字描述符是一个整数类型的值。
    每个进程的进程空间里都有一个套接字描述符表，该表中存放着套接字描述符和套接字数据结构的对应关系。该表中有一个字段存放新创建的套接字的描述符，另一个字段存放套接字数据结构的地址，因此根据套接字描述符就可以找到其对应的套接字数据结构。
    每个进程在自己的进程空间里都有一个套接字描述符表但是套接字数据结构都是在操作系统的内核缓冲里。

## 绑定
- 函数原型：
    `int bind(SOCKET socket, const struct sockaddr* address, socklen_t address_len);`
- 参数说明：
    - socket：是一个套接字描述符。
    - address：是一个sockaddr结构指针，该结构中包含了要结合的地址和端口号。
    - address_len：确定address缓冲区的长度。
- 返回值：
    如果函数执行成功，返回值为0，否则为SOCKET_ERROR。

## 接收
- 函数原型：
    `int recv(SOCKET socket, char FAR* buf, int len, int flags);`
- 参数说明：
    - socket：一个标识已连接套接口的描述字。
    - buf：用于接收数据的缓冲区。
    - len：缓冲区长度。
    - flags：指定调用方式。取值：MSG_PEEK 查看当前数据，数据将被复制到缓冲区中，但并不从输入队列中删除；MSG_OOB 处理带外数据。
- 返回值：
若无错误发生，recv()返回读入的字节数。如果连接已中止，返回0。否则的话，返回SOCKET_ERROR错误，应用程序可通过WSAGetLastError()获取相应错误代码。
  

- 函数原型：
    `ssize_t recvfrom(int sockfd, void buf, int len, unsigned int flags, struct socketaddr* from, socket_t* fromlen);`
- 参数说明：
    - sockfd：标识一个已连接套接口的描述字。
    - buf：接收数据缓冲区。
    - len：缓冲区长度。
    - flags：调用操作方式。是以下一个或者多个标志的组合体，可通过or操作连在一起：
        1. MSG_DONTWAIT：操作不会被阻塞；
        2. MSG_ERRQUEUE： 指示应该从套接字的错误队列上接收错误值，依据不同的协议，错误值以某种辅佐性消息的方式传递进来，使用者应该提供足够大的缓冲区。导致错误的原封包通过msg_iovec作为一般的数据来传递。导致错误的数据报原目标地址作为msg_name被提供。错误以sock_extended_err结构形态被使用。
        3. MSG_PEEK：指示数据接收后，在接收队列中保留原数据，不将其删除，随后的读操作还可以接收相同的数据。
        4. MSG_TRUNC：返回封包的实际长度，即使它比所提供的缓冲区更长， 只对packet套接字有效。
        5. MSG_WAITALL：要求阻塞操作，直到请求得到完整的满足。然而，如果捕捉到信号，错误或者连接断开发生，或者下次被接收的数据类型不同，仍会返回少于请求量的数据。
        6. MSG_EOR：指示记录的结束，返回的数据完成一个记录。
        7. MSG_CTRUNC：指明由于缓冲区空间不足，一些控制数据已被丢弃。
        8. MSG_OOB：指示接收到out-of-band数据(即需要优先处理的数据)。
        9. MSG_ERRQUEUE：指示除了来自套接字错误队列的错误外，没有接收到其它数据。
    - from：（可选）指针，指向装有源地址的缓冲区。
    - fromlen：（可选）指针，指向from缓冲区长度值。
## 发送
- 函数原型：
    `int sendto( SOCKET s, const char FAR* buf, int size, int flags, const struct sockaddr FAR* to, int tolen);`
- 参数说明：
    - s：套接字
    - buf：待发送数据的缓冲区
    - size：缓冲区长度
    - flags：调用方式标志位, 一般为0, 改变Flags，将会改变Sendto发送的形式
    - addr：（可选）指针，指向目的套接字的地址
    - tolen：addr所指地址的长度
- 返回值：
    如果成功，则返回发送的字节数，失败则返回SOCKET_ERROR。

## 接收连接请求
- 函数原型：
    `int accept( int fd, struct socketaddr* addr, socklen_t* len);`
- 参数说明：
    - fd：套接字描述符。
    - addr：返回连接着的地址
    - len：接收返回地址的缓冲区长度
- 返回值：
    成功返回客户端的文件描述符，失败返回-1。
{% endfold %}

# 代码
## 服务端
{% fold 点击现/隐代码 %}```c 服务端(需要管理员权限)
#include <arpa/inet.h>  //inet_ntop()、inet_ntoa()等
#include <memory.h>     //memset
#include <netinet/in.h> //struct sockaddr_in、PROTO_ICMP、INADDR_ANY等
#include <stdio.h>      //printf
#include <stdlib.h>     //exit
#include <sys/socket.h> //socket、bind、connect、struct sockaddr
#include <sys/types.h>  //类型定义
#include <time.h>       //time
#include <unistd.h>     //read

#define MAXLINE 100
#define LISTENQ 1024
#define bzero(a, b) memset(a, 0, b)

void err(const char *_information) {
    printf("%s\r\n", _information);
    exit(0);
}

int main(int argc, char **argv) {
    int listenfd, connfd;
    struct sockaddr_in servaddr;
    char buff[MAXLINE];
    time_t ticks;

    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
        err("socket error.");

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(13);

    if (bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1)
        err("bind error.");

    if (listen(listenfd, LISTENQ) == -1)
        err("Listen error.");

    while (1) {
        if ((connfd = accept(listenfd, (struct sockaddr *)NULL, NULL)) == -1)
            err("accept error.");

        ticks = time(NULL);

        snprintf(buff, sizeof(buff), "%.24s\r\n", ctime(&ticks));

        if (write(connfd, buff, strlen(buff)) == -1)
            err("write error.");

        if (close(connfd) == -1)
            err("close error.");
    }
}
```
{% endfold %}

## 客户端
{% fold 点击现/隐代码 %}```c 客户端
#include <arpa/inet.h>  //inet_ntop()、inet_ntoa()等
#include <memory.h>     //memset
#include <netinet/in.h> //struct sockaddr_in、PROTO_ICMP、INADDR_ANY等
#include <stdio.h>      //printf
#include <stdlib.h>     //exit
#include <sys/socket.h> //socket、bind、connect、struct sockaddr
#include <sys/types.h>  //类型定义
#include <time.h>       //time
#include <unistd.h>     //read

#define MAXLINE 100
#define bzero(a, b) memset(a, 0, b)

void err(const char *_information) {
    printf("%s\r\n", _information);
    exit(0);
}

int main(int argc, char **argv) {
    int sockfd, n;
    char recvline[MAXLINE + 1];
    struct sockaddr_in servaddr;

    //判断参数数目
    if (argc != 2)
        err("usage: a.out <IPaddress>");

    //创建socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        err("socket error");

    bzero(&servaddr, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(13);

    //转换地址
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0)
        err("inet_pton error");

    //连接
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
        err("connect error");

    //读取
    while ((n = read(sockfd, recvline, MAXLINE)) > 0) {
        recvline[n] = 0;
        if (fputs(recvline, stdout) == EOF)
            err("fputs error");
    }
    if (n < 0)
        err("read error");

    exit(0);
}
```
{% endfold %}