//FIXED:优化时间

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <stack>
using namespace std;

#define REP(n) for(int o=0;o<n;o++)

const int maxn = 1000005;

int n;
bool c[maxn];//保存符号，第i和i+1间的符号保存在i位置。1表示< 0表示>
int a[maxn];//保存第i个数字


int main() {
    char temp;
    scanf("%d",&n);
    REP(n - 1) {
        scanf("\n%c\n",&temp);
        c[o] = temp == '<' ? 1 : 0;
    }
    REP(n)
        scanf("%d",&a[o]);

    //快速排序，使字典序最小
    sort(a,a + n);

    //改造的冒泡排序，排成符合要求的顺序
    //Q:此处如果将交换部分写成调用swap函数，会发生bug
    int t;
    for(int j = 0; j < n - 1; j++)
        for(int i = 0; i < n - 1 - j; i++) {
            if(c[i]) {
                if(a[i] > a[i + 1]) {
                    t = a[i];
                    a[i] = a[i + 1];
                    a[i + 1] = t;
                }
            } else {
                if(a[i] < a[i + 1]) {
                    t = a[i];
                    a[i] = a[i + 1];
                    a[i + 1] = t;
                }
            }
        }

    REP(n)
        printf("%d ",a[o]);
    printf("\n");

    return 0;
}