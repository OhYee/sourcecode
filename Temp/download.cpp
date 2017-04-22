#include <stdio.h>
#include <windows.h>
#include <wininet.h>
#define MAXBLOCKSIZE 1024
#pragma comment(lib, "wininet.lib")

void download(const char *Url, const char *save_as) {
    /*将Url指向的地址的文件下载到save_as指向的本地文件*/
    byte Temp[MAXBLOCKSIZE];
    ULONG Number = 1;

    FILE *stream;
    HINTERNET hSession =
        InternetOpen("RookIE/1.0", INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, 0);
    if (hSession != NULL) {
        HINTERNET handle2 = InternetOpenUrl(hSession, Url, NULL, 0,
                                            INTERNET_FLAG_DONT_CACHE, 0);
        if (handle2 != NULL) {
            if ((stream = fopen(save_as, "wb")) != NULL) {
                while (Number > 0) {
                    InternetReadFile(handle2, Temp, MAXBLOCKSIZE - 1, &Number);
                    fwrite(Temp, sizeof(char), Number, stream);
                }
                fclose(stream);
            }
            InternetCloseHandle(handle2);
            handle2 = NULL;
        }
        InternetCloseHandle(hSession);
        hSession = NULL;
    }
}

void lf2crlf(const char *file_in, const char *file_out) {
    FILE *in, *out;
    if ((in = fopen(file_in, "rb")) != NULL &&
        (out = fopen(file_out, "wb")) != NULL) {
        char c;
        while ((c = fgetc(in)) != EOF) {
            if (c == '\n') {
                fputc('\r', out);
            }
            fputc(c, out);
        }
        fclose(in);
        fclose(out);
    }
}

int main(int argc, char *argv[]) {
    printf("从网络下载 hosts 文件...\n");
    download("https://raw.githubusercontent.com/racaljk/hosts/master/hosts",
             ".\\hosts.temp");
    printf("hosts 文件下载完成.\n");

    printf("开始转码 hosts 文件...\n");
    lf2crlf(".\\hosts.temp", ".\\hosts");
    printf("hosts 文件完成.\n");

    printf("删除临时文件...\n");
    system("del hosts.temp");
    printf("删除完成...\n");

    printf("请手动移动到系统目录.\n");
    system("explorer.exe /select,.\\");
    system("explorer.exe /select,%SystemRoot%\\System32\\drivers\\etc\\hosts");

    
    return 0;
}