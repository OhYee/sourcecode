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

const int maxn = 1005;

bool Do() {
    int n;
    int a[maxn];
    scanf("%d",&n);
    if(n == 0)
        return false;
    while(scanf("%d",&a[0]),a[0] != 0) {
        REP(n - 1)
            scanf("%d",&a[o + 1]);
        stack<int> S,A;
        REP(n)
            A.push(n - o);

        bool ok = true;
        //尝试将编号i+1出站
        for(int i = 0;i < n;i++) {
            //从中转站出站
                /*
                while的原理
                如果中转站中的车符合要求，让它出站，结束该次循环·····1
                如果中转站最外面的车不符合要求，检查A口，将它进站，继续上一步·····2
                如果A口已经没有车，则无解·····3
                */
            while(1) {
                if(!S.empty()&&S.top() == a[i]) {//·····1
                    S.pop();
                    break;
                } else {//·····3
                    if(A.empty()) {
                        ok = false;
                        break;
                    } else {//·····2
                        S.push(A.top());
                        A.pop();
                    }
                }
            }
            //不能达到题目的要求
            if(!ok)
                break;
        }
        printf("%s",ok ? "Yes\n" : "No\n");
    }
    printf("\n");
    return true;
}

int main() {
    while(Do());
    return 0;
}