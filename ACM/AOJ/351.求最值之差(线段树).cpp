/*
By:OhYee
Github:OhYee
Blog:http://www.oyohyee.com/
Email:oyohyee@oyohyee.com

かしこいかわいい？
エリーチカ！
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
using namespace std;

const int maxn = 100005;

struct Tree {
    int l,r;
    int Max,Min;
};

int num[maxn];
Tree T[maxn * 4];

int max(int a,int b) {
    return a > b ? a : b;
}
int min(int a,int b) {
    return a < b ? a : b;
}

void BuildTree(int a,int b,int* num,Tree *T,int pos = 1) {
    //根据数组 num[] a ~ b 下标区域 compare() 函数返回 true 建树
    T[pos].l = a;
    T[pos].r = b;
    if(b - a == 1) {
        T[pos].Max = max(num[a],num[b]);
        T[pos].Min = min(num[a],num[b]);
        return;
    }

    int mid = (a + b) / 2;
    int leftchild = 2 * pos;
    int rightchild = 2 * pos + 1;

    BuildTree(a,mid,num,T,leftchild);
    BuildTree(mid,b,num,T,rightchild);

    T[pos].Max = max(T[leftchild].Max,T[rightchild].Max);
    T[pos].Min = min(T[leftchild].Min,T[rightchild].Min);
    return;
}

void GetNum(int a,int b,int* num,Tree *T,int &Max,int &Min,int pos = 1) {
    //根据数组 num[] a ~ b 下标区域 compare() 函数返回 true 建树
    if(a == b) {
        Max = a;
        Min = a;
        return;
    }

    int &l = T[pos].l;
    int &r = T[pos].r;

    if(a == l && b == r) {
        Max = T[pos].Max;
        Min = T[pos].Min;
        return;
    }

    int mid = (l + r) / 2;
    int leftchild = 2 * pos;
    int rightchild = 2 * pos + 1;

    if(b <= mid) {
        GetNum(a,b,num,T,Max,Min,leftchild);
        return;
    }

    if(a >= mid) {
        GetNum(a,b,num,T,Max,Min,rightchild);
        return;
    }

    int Max1,Max2,Min1,Min2;
    GetNum(a,mid,num,T,Max1,Min1,leftchild);
    GetNum(mid,b,num,T,Max2,Min2,rightchild);

    Max = max(Max1,Max2);
    Min = min(Min1,Min2);
    return;
}

int n,m;

bool Do() {
    if(!(cin >> n >> m))
        return false;
    for(int i = 1;i <= n;i++)
        cin >> num[i];

    /*线段树*/
    BuildTree(1,n,num,T);

    for(int i = 1;i <= m;i++) {
        int a,b;
        cin >> a >> b;
        int Max,Min;
        GetNum(a,b,num,T,Max,Min);
        cout << Max-Min << endl;
    }
    return true;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(false);

    while(Do());
    return 0;
}