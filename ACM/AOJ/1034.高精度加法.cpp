#include <cstdio>
#include <cstring>


#define MAXN 9999
#define MAXSIZE 1010
#define DLEN 4
class BigNum {
private:
    int a[5000]; //可以控制大数的位数
    int len;
public:
    BigNum() {
        len = 1;memset(a,0,sizeof(a));
    } //构造函数
    BigNum operator+(const BigNum &)const; //重载加法运算符，两个大数之间的相加运算
    void print(); //输出大数
    void read(const char *s); //从字符串读入

};

BigNum BigNum::operator+(const BigNum &T)const //两个大数之间的相加运算
{
    BigNum t(*this);
    int i,big;
    big = T.len>len ? T.len : len;
    for(i = 0;i<big;i++) {
        t.a[i] += T.a[i];
        if(t.a[i]>MAXN) {
            t.a[i + 1]++;
            t.a[i] -= MAXN + 1;
        }
    }
    if(t.a[big] != 0)
        t.len = big + 1;
    else t.len = big;
    return t;
}
void BigNum::print() //输出大数
{
    int i;
    printf("%d",a[len - 1]);
    for(i = len - 2;i >= 0;i--)
        printf("%04d",a[i]);
    printf("\n");
}
void BigNum::read(const char *s) {
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

const int maxn = 105;
char s1[maxn],s2[maxn];

BigNum a,b,c;

int main(){
    //freopen("in.txt","r",stdin);
    scanf("%s%s",s1,s2);

    a.read(s1);
    b.read(s2);
    (a+b).print();

    return 0;
}
