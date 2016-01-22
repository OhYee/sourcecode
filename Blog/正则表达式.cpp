#include <regex>
#include <iostream>
#include <sys/types.h>
#include <stdio.h>
#include <cstring>
#include <sys/time.h>

using namespace std;
const int times = 1000000;

int main(int argc,char** argv)
{
    char pattern[512]="finance\.sina\.cn|stock1\.sina\.cn|3g\.sina\.com\.cn.*(channel=finance|_finance$|ch=stock|/stock/)|dp.sina.cn/.*ch=9&";
    const size_t nmatch = 10;
    regmatch_t pm[10];
    int z ;
    regex_t reg;
    char lbuf[256]="set",rbuf[256];
    char buf[3][256] = {"finance.sina.cn/google.com/baidu.com.google.sina.cndddddddddddddddddddddda.sdfasdfeoasdfnahsfonadsdf",
                    "3g.com.sina.cn.google.com.dddddddddddddddddddddddddddddddddddddddddddddddddddddbaidu.com.sina.egooooooooo",
                    "http://3g.sina.com.cn/google.baiduchannel=financegogo.sjdfaposif;lasdjf.asdofjas;dfjaiel.sdfaosidfj"};
    printf("input strings:\n");
    timeval end,start;
    gettimeofday(&start,NULL);
    regcomp(&reg,pattern,REG_EXTENDED|REG_NOSUB);
    for(int i = 0 ; i < times; ++i)
    {
        for(int j = 0 ; j < 3; ++j)
        {
            z = regexec(&reg,buf[j],nmatch,pm,REG_NOTBOL);
/*          if(z==REG_NOMATCH)
                printf("no match\n");
            else
                printf("ok\n");
                */
        }
    }
    gettimeofday(&end,NULL);
    uint time = (end.tv_sec-start.tv_sec)*1000000 + end.tv_usec - start.tv_usec;
    cout<<time/1000000<<" s and "<<time%1000000<<" us."<<endl;
    return 0 ;
}
/*
1.编译正则表达式

2.执行匹配

3.释放内存

首先，编译正则表达式

int regcomp(regex_t *preg, const char *regex, int cflags);

reqcomp()函数用于把正则表达式编译成某种格式，可以使后面的匹配更有效。

preg： regex_t结构体用于存放编译后的正则表达式；

regex： 指向正则表达式指针；

cflags：编译模式

共有如下四种编译模式：

REG_EXTENDED：使用功能更强大的扩展正则表达式

REG_ICASE：忽略大小写

REG_NOSUB：不用存储匹配后的结果

REG_NEWLINE：识别换行符，这样‘$’就可以从行尾开始匹配，‘^’就可以从行的开头开始匹配。否则忽略换行符，把整个文本串当做一个字符串处理。

其次，执行匹配

int regexec(const regex_t *preg, const char *string, size_t nmatch, regmatch_t pmatch[], int eflags);

preg： 已编译的正则表达式指针；

string：目标字符串；

nmatch:pmatch数组的长度；

pmatch：结构体数组，存放匹配文本串的位置信息；

eflags：匹配模式

共两种匹配模式：

REG_NOTBOL：The match-beginning-of-line operator always fails to match  (but see  the  compilation  flag  REG_NEWLINE above). This flag may be used when different portions of a string are passed  to  regexec and the beginning of the string should not be interpreted as the beginning of the line.

REG_NOTEOL:The match-end-of-line operator always fails to  match  (but  see the compilation flag REG_NEWLINE above)

最后，释放内存
void regfree(regex_t *preg);
当使用完编译好的正则表达式后，或者需要重新编译其他正则表达式时，一定要使用这个函数清空该变量。


其他，处理错误
size_t regerror(int errcode, const regex_t *preg, char *errbuf, size_t errbuf_size);
当执行regcomp 或者regexec 产生错误的时候，就可以调用这个函数而返回一个包含错误信息的字符串。
errcode： 由regcomp 和 regexec 函数返回的错误代号。
preg： 已经用regcomp函数编译好的正则表达式，这个值可以为NULL。
errbuf： 指向用来存放错误信息的字符串的内存空间。
errbuf_size： 指明buffer的长度，如果这个错误信息的长度大于这个值，则regerror 函数会自动截断超出的字符串，但他仍然会返回完整的字符串的长度。所以我们可以用如下的方法先得到错误字符串的长度。
*/