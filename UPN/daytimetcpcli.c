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