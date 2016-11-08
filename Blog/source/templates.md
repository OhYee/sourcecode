---
layout: post
title: 模板
date: 2016-08-22 19:57:59
tags: 
---
# 模板
  
[OEIS 数列网站](http://oeis.org/)  

**建议使用 `CTRL + F` 快速定位**  

# 头文件部分

```cpp 头文件
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <bitset>
#include <functional>
```

```cpp 宏定义部分
#pragma comment(linker,"/STACK:1024000000,1024000000")//手动拓栈

const int INF = 0x7FFFFFFF;
const double eps = 1e-10;
```


# 函数部分

## double 浮点误差

### 转换为整数
```cpp 转换为整数
int toInte(double a){
    return (int)(a+0.001);
}
```

### 比较是否相等
```cpp 比较是否相等
bool equal(double a,double b) {
    return fabs(a - b) < eps;
}
```

## 位操作
### 设置第i位
```cpp 设置第i位
inline int SetI(int num,int i,bool flag) {
    if(flag)
        return num | (1 << i);
    else
        return num & (~(1 << i));
}
```

### 取第i位
```cpp 取第i位
inline bool GetI(int num,int i) {
    return num >> i & 1;
}
```

### 返回最小的不同的位
```cpp 返回最小的不同的位
int GetChange(int num1,int num2) {
    int n = num1 ^ num2;
    int i = 0;
    while(n) {
        if(n & 1)
            return i;
        n >>= 1;
        i++;
    }
    return 0;
}
```


## RMQ问题

### ST算法
```cpp 预处理
for(int k = 0;(1 << k) <= n;k++) {
    for(int i = 1;i + (1 << k) - 1 <= n;i++) {
        //dp[i][k] 为 (i,j)区间的最值
        if(k == 0) {
            Max[i][k] = Min[i][k] = num[i];
        } else {
            Max[i][k] = max(Max[i][k - 1],Max[i + (1 << (k-1))][k - 1]);
            Min[i][k] = min(Min[i][k - 1],Min[i + (1 << (k-1))][k - 1]);
        }
    }
}
```

```cpp 查询
int k = (int)(log(b - a + 1.0) / log(2.0));
cout << "Max: " << max(Max[a][k],Max[b - (2<<k) + 1][k]) << endl;
cout << "Min: " << min(Min[a][k],Min[b - (2<<k) + 1][k]) << endl;
```



## 二分
```二分
bool Could(long long n) {
    long long money = 0;
    for(int i = 0;i < maxn;i++) 
        if(n*need[i] > num[i])
            money += p[i] * (n*need[i]-num[i]);
    return money > r;
}
long long Division(long long l,long long r) {
    if(l == r) {
        return l;
    }
    long long mid = (l + r) / 2;
    if(Could(mid))
        return Division(l,mid);
    else
        return Division(mid + 1,r);
}
```

### 快速幂取模
```cpp 快速幂取模
LL exp_mod(LL a,LL n,LL b) {
    LL t;
    if(n == 0) return 1 % b;
    if(n == 1) return a % b;
    t = exp_mod(a,n / 2,b);
    t = t * t % b;
    if((n & 1) == 1) t = t * a % b;
    return t;
}
```


## 拓扑排序
```cpp 拓扑排序
bool G[maxn][maxn];
bool vis[maxn];
int n;
bool HasLoop() {
    //判断是否存在环
    for(int i = 1;i <= n;i++)
        if(!vis[i])
            return false;
    return true;
}
bool IsStart(int k) {
    //判断是否入度为0
    for(int i = 1;i <= n;i++)
        if(G[i][k])
            return false;
    return true;
}
bool TopoSort(int _n,int *ans) {
    //拓扑排序
    /*
    参数:
    邻接矩阵G[][]
    顶点数目n
    用于保存拓扑排序结果的数组 ans[]
    */
    //输出结果下标初始化
    int pos = 0;
    //已访问数组初始化
    memset(vis,false,sizeof(vis));
    //可被选择的数
    priority_queue<int> Q;
    //判断i是否为源
    for(int i = 1;i <= n;i++) {
        if(IsStart(i))
            Q.push(i);
    }
    while(!Q.empty()) {
        int k = Q.top();
        Q.pop();
        if(vis[k])
            continue;
        else
            vis[k] = true;
        //记录到结果中
        ans[pos++] = k;
        for(int i = 1;i <= n;i++) {
            if(G[k][i]) {
                //路径k~i存在
                //删除路径
                G[k][i] = false;
                //如果成为入度为0的点
                if(IsStart(i))
                    Q.push(i);
            }
        }
    }
    //判断是否有环
    return HasLoop();
}
```

## 动态规划
### 最大上升子序列
```cpp 最大上升子序列
int Max = 0;
a[0] = 0;
for(int i = 0;i <= n;i++) {
    dp[i] = 0;
    for(int j = 0;j < i;j++) 
        if(a[i] > a[j])
            dp[i] = max(dp[i],dp[j] + a[i]);
    Max = max(Max,dp[i]);
}
```
### 最大不连续子序列
```cpp 最大不连续子序列
void MUS(int *dp,int *num,int n){
    dp[1] = num[1];
    dp[2] = max(num[1],num[2]);
    for(int i=3;i<=n;i++){
        dp[i] = max(dp[i-1],dp[i-2]+num[i]);
    }
}
```
### 最大连续子序列
```cpp 最大连续子序列
for(int i = 1;i <= n;i++) {
        dp[i] = max(dp[i - 1] + a[i],a[i]);
}
```

### 最长上升子序列
```cpp 最长上升子序列 O(n^2)
int Max = 0;
for(int i = 1;i <= 3 * n;i++) {
    dp[i] = 0;
    for(int j = 0;j < i;j++) {
        if(Node::cmp(S[j],S[i])) {
            dp[i] = max(dp[i],dp[j] + S[i].h);
        }
    }
    Max = max(Max,dp[i]);
}
```

```cpp 最长上升子序列 O(nlogn)
int len = 1;
for(int i = 2; i <= n; ++i) {
    if(node[i] > ans[len])
        ans[++len] = node[i];
    else {
        Node *t = lower_bound(ans + 1,ans + 1 + len,node[i]);
        *(t) = node[i];
    }
}
```

### 背包
```cpp 背包问题
void ZeroOnePack(int cost,int weight) {
     for (int i = v; i >= cost; i--)
         dp[i] = max(dp[i],dp[i - cost] + weight);
 }
 void CompletePack(int cost,int weight) {
     for (int i = cost; i <= v; i++)
         dp[i] = max(dp[i],dp[i - cost] + weight);
 }
 void MultiplePack(int cost,int weight,int n) {
    if (cost * n > v) {
        CompletePack(cost,weight);
    } else {
        int k = 1;
        while (k < n) {
            ZeroOnePack(cost * k,weight * k);
            n -= k;
            k *= 2;
        }
        ZeroOnePack(cost * n,weight * n);
    }
}
```

### 最长公共子序列
```cpp 最长公共子序列
//最长公共子序列
//输入字符串a 及其长度 字符串b 及其长度 保存最长公共子序列的数组
//字符从0开始
int LCS(char *a,char *b,char s[] = NULL) {
    int len1 = strlen(a);
    int len2 = strlen(b);
    char *aa = a - 1;
    char *bb = b - 1;
    //声明二维数组
    int * m = new int[(len1 + 1)*(len2 + 1)];
    int **dp = new int *[len1 + 1];
    for(int i = 0;i <= len1;i++)
        dp[i] = m + i*(len2 + 1);
    //初始化
    for(int i = 0;i <= len1;i++)
        dp[i][0] = 0;
    for(int i = 0;i <= len2;i++)
        dp[0][i] = 0;
    //动态规划
    for(int i = 1;i <= len1;i++)
        for(int j = 1;j <= len2;j++)
            if(aa[i] == bb[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j],dp[i][j - 1]);
    /*for(int i = 0;i <= len1;i++){
        for(int j = 0;j <= len2;j++)
            printf("%d\t",dp[i][j]);
        printf("\n");
    }*/
    //如果c未传值
    if(s == NULL)
        return dp[len1][len2];
    //逆序推出一条符合串
    int ans = dp[len1][len2];
    int x = len1;
    int y = len2;
    int it = ans;
    s[it] = '\0';
    while(it) {
        if(dp[x - 1][y] == it) {
            x--;
            continue;
        }
        if(dp[x][y - 1] == it) {
            y--;
            continue;
        }
        s[--it] = aa[x];
        x--;
        y--;
    }
    return ans;
}
```

### 最大矩形
```cpp 最大矩形
int H[maxn][maxn];
int Left[maxn];
int Right[maxn];
int MaxMatrix(bool Matrix[maxn][maxn],int n,int m,bool target) {
    memset(H,0,sizeof(H));
    memset(Left,0,sizeof(Left));
    memset(Right,0,sizeof(Right));
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++) {
            if(Matrix[i][j] == target) {
                if(Matrix[i - 1][j])
                    H[i][j] = H[i - 1][j] + 1;
                else
                    H[i][j] = 1;
            }
        }
    int Max = 0;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            if(Matrix[i][j] == target) {
                int t = j;
                while(t > 1 && H[i][j] <= H[i][t - 1])
                    t = Left[t - 1];
                Left[j] = t;
            }
        }
        for(int j = m;j >= 1;j--) {
            if(Matrix[i][j] == target) {
                int t = j;
                while(t < m && H[i][j] <= H[i][t + 1])
                    t = Right[t + 1];
                Right[j] = t;
            }
        }
        for(int j = 1;j <= m;j++) {
            if(Matrix[i][j] == target) {
                int S = H[i][j] * (Right[j] - Left[j] + 1);
                Max = max(Max,S);
            }
        }
    }
    return Max;
}
```

## 数学
### 欧几里得算法
```cpp 欧几里得算法
int gcd(int a,int b) {
    return b == 0 ? a : gcd(b,a%b);
}
```

### 约瑟夫环问题
```cpp 约瑟夫环问题
int ans = 0;
for(int i = 2; i <= n; i++)
    ans = (ans + k) % i;
ans = (m - k + 1 + ans) % n;
if(ans <= 0)
    ans += n;
```

### Eratosthenes筛法
```cpp Eratosthenes筛法
int prime[maxn]={0},num_prime=0;
bool isNotPrime[maxn]={1,1};
for(long i=2;i<maxn;i++){
    if(!isNotPrime[i])prime[num_prime++]=i;
    for(int j=0;j<num_prime&&i*prime[j]<maxn;j++){
        isNotPrime[i*prime[j]]=true;
        count[i*prime[j]]++;
        if(!(i%prime[j]))break;
    }
}
```

### 高精度计算
```cpp 高精度计算
/*
* 完全大数模板 修改版
* 输出cin>>a
* 输出a.print();
* 注意这个输入不能自动去掉前导0的，可以先读入到char数组，去掉前导0，再用构造函数。
* by kuangbin GG.
*/
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
    BigNum(const long long); //将一个int类型的变量转化成大数  
    BigNum(const char*); //将一个字符串类型的变量转化为大数  
    BigNum(const BigNum &); //拷贝构造函数  
    BigNum &operator=(const BigNum &); //重载赋值运算符，大数之间进行赋值运算  
    friend istream& operator >> (istream&,BigNum&); //重载输入运算符  
    friend ostream& operator<<(ostream&,BigNum&); //重载输出运算符  
    BigNum operator+(const BigNum &)const; //重载加法运算符，两个大数之间的相加运算  
    BigNum operator-(const BigNum &)const; //重载减法运算符，两个大数之间的相减运算  
    BigNum operator*(const BigNum &)const; //重载乘法运算符，两个大数之间的相乘运算  
    BigNum operator/(const int &)const; //重载除法运算符，大数对一个整数进行相除运算  

    BigNum operator^(const int &)const; //大数的n次方运算  
    int operator%(const int &)const; //大数对一个int类型的变量进行取模运算  
    bool operator>(const BigNum &T)const; //大数和另一个大数的大小比较  
    bool operator>(const int &t)const; //大数和一个int类型的变量的大小比较  
    void print(); //输出大数  

    void read(const char *s); //从字符串读入  
    void pre0(char *s); //取出字符串的前导0;  
};
BigNum::BigNum(const long long b) //将一个int类型的变量转化为大数  
{
    long long c,d = b;
    len = 0;
    memset(a,0,sizeof(a));
    while(d>MAXN) {
        c = d - (d / (MAXN + 1))*(MAXN + 1);
        d = d / (MAXN + 1);
        a[len++] = c;
    }
    a[len++] = d;
}
BigNum::BigNum(const char *s) //将一个字符串类型的变量转化为大数  
{
    int t,k,index,L,i;
    memset(a,0,sizeof(a));
    L = strlen(s);
    len = L / DLEN;
    if(L%DLEN)len++;
    index = 0;
    for(i = L - 1;i >= 0;i -= DLEN) {
        t = 0;
        k = i - DLEN + 1;
        if(k<0)k = 0;
        for(int j = k;j <= i;j++)
            t = t * 10 + s[j] - '0';
        a[index++] = t;
    }
}
BigNum::BigNum(const BigNum &T):len(T.len) //拷贝构造函数  
{
    int i;
    memset(a,0,sizeof(a));
    for(i = 0;i<len;i++)
        a[i] = T.a[i];
}
BigNum & BigNum::operator=(const BigNum &n) //重载赋值运算符，大数之间赋值运算  
{
    int i;
    len = n.len;
    memset(a,0,sizeof(a));
    for(i = 0;i<len;i++)
        a[i] = n.a[i];
    return *this;
}
istream& operator >> (istream &in,BigNum &b) {
    char ch[MAXSIZE * 4];
    int i = -1;
    in >> ch;
    int L = strlen(ch);
    int count = 0,sum = 0;
    for(i = L - 1;i >= 0;) {
        sum = 0;
        int t = 1;
        for(int j = 0;j<4 && i >= 0;j++,i--,t *= 10) {
            sum += (ch[i] - '0')*t;
        }
        b.a[count] = sum;
        count++;
    }
    b.len = count++;
    return in;
}
ostream& operator<<(ostream& out,BigNum& b) //重载输出运算符  
{
    int i;
    cout << b.a[b.len - 1];
    for(i = b.len - 2;i >= 0;i--) {
        printf("%04d",b.a[i]);
    }
    return out;
}
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
BigNum BigNum::operator-(const BigNum &T)const //两个大数之间的相减运算  
{
    int i,j,big;
    bool flag;
    BigNum t1,t2;
    if(*this>T) {
        t1 = *this;
        t2 = T;
        flag = 0;
    } else {
        t1 = T;
        t2 = *this;
        flag = 1;
    }
    big = t1.len;
    for(i = 0;i<big;i++) {
        if(t1.a[i]<t2.a[i]) {
            j = i + 1;
            while(t1.a[j] == 0)
                j++;
            t1.a[j--]--;
            while(j>i)
                t1.a[j--] += MAXN;
            t1.a[i] += MAXN + 1 - t2.a[i];
        } else t1.a[i] -= t2.a[i];
    }
    t1.len = big;
    while(t1.a[len - 1] == 0 && t1.len>1) {
        t1.len--;
        big--;
    }
    if(flag)
        t1.a[big - 1] = 0 - t1.a[big - 1];
    return t1;
}
BigNum BigNum::operator*(const BigNum &T)const //两个大数之间的相乘  
{
    BigNum ret;
    int i,j,up;
    int temp,temp1;
    for(i = 0;i<len;i++) {
        up = 0;
        for(j = 0;j<T.len;j++) {
            temp = a[i] * T.a[j] + ret.a[i + j] + up;
            if(temp>MAXN) {
                temp1 = temp - temp / (MAXN + 1)*(MAXN + 1);
                up = temp / (MAXN + 1);
                ret.a[i + j] = temp1;
            } else {
                up = 0;
                ret.a[i + j] = temp;
            }
        }
        if(up != 0)
            ret.a[i + j] = up;
    }
    ret.len = i + j;
    while(ret.a[ret.len - 1] == 0 && ret.len>1)ret.len--;
    return ret;
}
BigNum BigNum::operator/(const int &b)const //大数对一个整数进行相除运算  
{
    BigNum ret;
    int i,down = 0;
    for(i = len - 1;i >= 0;i--) {
        ret.a[i] = (a[i] + down*(MAXN + 1)) / b;
        down = a[i] + down*(MAXN + 1) - ret.a[i] * b;
    }
    ret.len = len;
    while(ret.a[ret.len - 1] == 0 && ret.len>1)
        ret.len--;
    return ret;
}
int BigNum::operator%(const int &b)const //大数对一个 int类型的变量进行取模  
{
    int i,d = 0;
    for(i = len - 1;i >= 0;i--)
        d = ((d*(MAXN + 1)) % b + a[i]) % b;
    return d;
}
BigNum BigNum::operator^(const int &n)const //大数的n次方运算  
{
    BigNum t,ret(1);
    int i;
    if(n<0)exit(-1);
    if(n == 0)return 1;
    if(n == 1)return *this;
    int m = n;
    while(m>1) {
        t = *this;
        for(i = 1;(i << 1) <= m;i <<= 1)
            t = t*t;
        m -= i;
        ret = ret*t;
        if(m == 1)ret = ret*(*this);
    }
    return ret;
}
bool BigNum::operator>(const BigNum &T)const //大数和另一个大数的大小比较  
{
    int ln;
    if(len>T.len)return true;
    else if(len == T.len) {
        ln = len - 1;
        while(a[ln] == T.a[ln] && ln >= 0)
            ln--;
        if(ln >= 0 && a[ln]>T.a[ln])
            return true;
        else
            return false;
    } else
        return false;
}
bool BigNum::operator>(const int &t)const //大数和一个int类型的变量的大小比较  
{
    BigNum b(t);
    return *this>b;
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
void BigNum::pre0(char *s) {
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
}

```

## 读入输出

```cpp 读入输出
//优化输入
inline int read_int() {
    char c;
    int ans = 0;
    while(c = getchar(),!(c >= '0'&&c <= '9'));
    while(c >= '0'&&c <= '9') {
        ans *= 10;
        ans += (int)c - '0';
        c = getchar();
    }
    return ans;
}

inline int read_string(char s[]){
    char c;
    int i=0;
    while(!(((c=getchar())>='A'&&c<='Z')||(c>='a'&&c<='z')))
        if(c==EOF)
            return 0;
    while((c>='A'&&c<='Z')||(c>='a'&&c<='z')){
        s[i++]=c;
        c=getchar();
    }
    s[i]='\0';
    return i;
}
 
//优化输出
inline void write_int(long long n) {
    char str[50];
    int len = 0;
    if(n < 0) {
        n = -n;
        putchar('-');
    }
    if(n == 0)
        putchar('0');
    while(n) {
        str[len++] = (int)(n % 10) + '0';
        n /= 10;
    }
    while(len)
        putchar(str[--len]);
    return;
}
```

## 图
### 通用部分
```cpp 边
struct Edge {
    int u,v,w;
    Edge():u(0),v(0),w(0) {}
    Edge(int a,int b,int c):u(a),v(b),w(c) {}
};

int pos;
Edge edge[maxm];
list<int> L[maxn];

queue<int> Q;
int dist[maxn];

inline void add(int u,int v,int w) {
    edge[pos] = Edge(u,v,w);

    L[u].push_back(pos);
    pos++;
}
```

### 强连通分量
#### Kosaraju
```cpp Kosaraju
//Kosaraju 返回强连通分量个数
//节点从0开始,记得初始化变量

struct Edge {
    int u,v;
    Edge():u(0),v(0) {}
    Edge(int a,int b):u(a),v(b) {}
};
int pos;
Edge edge[maxm];
list<int> L[maxn];
list<int> L2[maxn];

stack<int> s;
bool vis[maxn];
vector<int> SCC[maxn];//得到的强连通分量链表

inline void add(int u,int v) {
    edge[pos] = Edge(u,v);
    L[u].push_back(pos);
    L2[v].push_back(pos);//逆图

    pos++;
}

void DFS1(int t) {
    if(!vis[t]) {
        vis[t] = true;
        for(list<int>::iterator i = L[t].begin();i != L[t].end();i++)
            DFS1(edge[*i].v);
        s.push(t);
    }
    return;
}

void DFS2(int p,int t) {
    if(vis[t]) {
        vis[t] = false;
        SCC[p].push_back(t);
        for(list<int>::iterator i = L2[t].begin();i != L2[t].end();i++)
            DFS2(p,edge[*i].u);
    }
    return;
}

int Kosaraju(int n) {
    //第一次DFS
    for(int i = 0;i < n;i++)
        DFS1(i);

    //第二次DFS
    int p = 0;
    while(!s.empty()) {
        int t = s.top();
        s.pop();
        list< list<int> >::iterator it;
        if(vis[t])
            DFS2(p++,t);
    }
    return p;
}
```

#### Tarjan
```cpp Tarjan
//Tarjan 返回强连通分量个数
//节点从0开始,记得初始化变量

struct Edge {
    int u,v;
    Edge():u(0),v(0) {}
    Edge(int a,int b):u(a),v(b) {}
};
int pos;
Edge edge[maxm];
list<int> L[maxn];

stack<int> s;
bool inStack[maxn];
vector<int> SCC[maxn];//得到的强连通分量链表
int cnt,Index;
int DFN[maxn],Low[maxn];

inline void add(int u,int v) {
    edge[pos] = Edge(u,v);
    L[u].push_back(pos);
    pos++;
}

void tarjan(int u) {
    if(DFN[u] != -1)
        return;

    DFN[u] = Low[u] = ++Index;
    s.push(u);
    inStack[u] = true;

    for(list<int>::iterator it = L[u].begin();it != L[u].end();it++) {
        int v = edge[*it].v;

        if(DFN[v] == -1) {
            tarjan(v);
            Low[u] = min(Low[u],Low[v]);
        } else if(inStack[v]) {
            Low[u] = min(Low[u],DFN[v]);
        }

    }
    if(DFN[u] == Low[u]) {
        int v = s.top();
        s.pop();
        inStack[v] = false;

        SCC[cnt++].push_back(v);

        while(u != v) {
            v = s.top();
            s.pop();
            inStack[v] = false;

            SCC[cnt - 1].push_back(v);
        }
    }
}

int Tarjan(int n) {
    cnt = 0;
    Index = 0;
    while(!s.empty())s.pop();
    memset(inStack,false,sizeof(inStack));
    memset(DFN,-1,sizeof(DFN));
    memset(Low,-1,sizeof(Low));

    for(int i = 0;i < n;i++)
        tarjan(i);
    return cnt;
}

```

### 网络流
#### Dinic算法
```cpp Dinic 
bool bfs(int s,int t) {
    memset(dist,0,sizeof(dist));
    while(!Q.empty())
        Q.pop();

    Q.push(s);
    dist[s] = 1;
    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();

        for(list<int>::iterator it = L[u].begin();it != L[u].end();it++) {
            int v = edge[*it].v;
            if(!dist[v] && edge[*it].w) {
                dist[v] = dist[u] + 1;
                if(v == t)
                    return true;
                Q.push(v);
            }
        }
    }
    return false;
}
int dfs(int u,int t,int flow) {
    if(u == t)
        return flow;
    int remain = flow;
    for(list<int>::iterator it = L[u].begin();it != L[u].end() && remain;it++) {
        int v = edge[*it].v;
        if(dist[v] == dist[u] + 1 && edge[*it].w) {
            int k = dfs(v,t,min(remain,edge[*it].w));
            if(!k)
                dist[v] = 0;
            edge[*it].w -= k;
            edge[(*it) ^ 1].w += k;
            remain -= k;
        }
    }
    return flow - remain;
}
int Dinic(int u,int v) {
    int ans = 0;
    while(bfs(u,v))
        ans += dfs(u,v,INF);
    return ans;
}
```

### 最短路
#### floyed
```cpp floyed
for(int k = 1;k <= p;k++)
        for(int i = 1;i <= p;i++)
            for(int j = 1;j <= p;j++){

            }
```

#### spfa
```cpp spfa

void spfa(int s) {
    while(!Q.empty())
        Q.pop();
    for(int i = 1;i <= n;i++)
        dist[i] = INF;

    Q.push(s);
    dist[s] = 0;
    vis[s] = true;

    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();
        vis[u] = false;

        for(list<int>::iterator it = L[u].begin();it != L[u].end();it++) {
            int v = edge[*it].v;
            if(dist[v] > dist[u] + edge[*it].w) {
                dist[v] = dist[u] + edge[*it].w;
                if(!vis[v]) {
                    Q.push(v);
                    vis[v] = true;
                }
            }
        }
    }
}
```


### 最小生成树
#### Kruskal+ufs
``` Kruskal+ufs
int ufs(int x){
    return f[x] == x ? x : f[x] = ufs(f[x]); 
} 
int Kruskal(int n,int m) {
    int w = 0;
    for(int i = 0; i < n; i++)
        f[i] = i;
    sort(e,e + m);
    for(int i = 0; i < m; i++) {
        int x = ufs(e[i].u),y = ufs(e[i].v);
        if(x != y) {
            f[x] = y;
            w += e[i].w;
        }
    }
    return w;
}
```

#### prim
```cpp prim
int Prim() {
    int w = 0;
    priority_queue<pair<int, int> > q;
    bool l[N] = {0};
    l[1] = 1; q.push(make_pair(0, 1));
    for(int k=1; k<n; k++) {
        int u = q.top().second; q.pop();
        for(int i=0; i<G[u].size(); i++)
            if(!l[G[u][i]])
                q.push(make_pair(-c[u][i], G[u][i]));
        while(!q.empty() && l[q.top().second])
            q.pop();
        l[q.top().second] = 1;
        w += -q.top().first;
        q.pop();
    } return w;
}
```