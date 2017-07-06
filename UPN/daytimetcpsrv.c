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