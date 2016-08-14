/*
By:OhYee
Github:OhYee
Blog:http://www.oyohyee.com/
Email:oyohyee@oyohyee.com

かしこいかわいい？
エリ0隶�
要写出来Хорошо的代码哦~
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <bitset>
#include <iomanip> 
using namespace std;

const int maxn = 10000005;
int kase = 0;

/*
* 完全大数模板
* 输出cin>>a
* 输出a.print();
* 注意这个输入不能自动去掉前导0的，可以先读入到char数组，去掉前导0，再用构造函数。
*/
#define MAXN 9999
#define MAXSIZE 1010
#define DLEN 4
struct BigInter {
    int a[maxn]; //可以控制大数的位数
    int len;
    BigInter() {
        len = 1; memset(a,0,sizeof(a));
    } //构造函数
    BigInter(const char*); //将一个字符串类型的变量转化为大数
    int operator % (const int &)const; //大数对一个int类型的变量进行取模运算
    void print(); //输出大数
    void read(const char *s);
};
BigInter::BigInter(const char *s) //将一个字符串类型的变量转化为大数
{
    int t,k,index,L,i;
    memset(a,0,sizeof(a));
    L = strlen(s);
    len = L / DLEN;
    if(L%DLEN)len++;
    index = 0;
    for(i = L - 1; i >= 0; i -= DLEN) {
        t = 0;
        k = i - DLEN + 1;
        if(k < 0)k = 0;
        for(int j = k; j <= i; j++)
            t = t * 10 + s[j] - '0';
        a[index++] = t;
    }
}
int BigInter::operator % (const int &b)const //大数对一个 int类型的变量进行取模
{
    int i,d = 0;
    for(i = len - 1; i >= 0; i--)
        d = ((d*(MAXN + 1)) % b + a[i]) % b;
    return d;
}
void BigInter::print() //输出大数
{
    int i;
    printf("%d",a[len - 1]);
    for(i = len - 2; i >= 0; i--)
        printf("%04d",a[i]);
    printf("\n");
}
void BigInter::read(const char *s) {
    int t,k,index,L,i;
    memset(a,0,sizeof(a));
    L = strlen(s);
    len = L / DLEN;
    if(L%DLEN)len++;
    index = 0;
    for(i = L - 1; i >= 0; i -= DLEN) {
        t = 0;
        k = i - DLEN + 1;
        if(k < 0)k = 0;
        for(int j = k; j <= i; j++)
            t = t * 10 + s[j] - '0';
        a[index++] = t;
    }
}

BigInter ans;
char s[maxn];

bool Do() {
    if(scanf("%s",s) == EOF)
        return false;
    
    printf("Case #%d: ",++kase);
    
    int pos = 0;
    int len = strlen(s);
    for(int i = 0;i < len;i++) {
        if(s[i] != '0') {
            pos = i;
            break;
        }
    }
    for(int i = pos;i < len;i++)
        s[i - pos] = s[i];
    s[len - pos] = '\0';
    
    ans.read(s);
    
    if(ans % 73 == 0 && 0 == ans % 137)
        printf("YES\n");
    else
        printf("NO\n");


    return true;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(false);
    while(Do());
    return 0;
}