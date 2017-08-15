/*
By:OhYee
Github:OhYee
Email:oyohyee@oyohyee.com
*/
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

int main() {
    int n;
    while(scanf("%d",&n) != EOF) {
        double ans1 = 0,ans2 = 0;
        double a,b;
        REP(n) {
            scanf("%lf%lf",&a,&b);
            ans1 += a*b;
            ans2 += a;
        }
        printf("%.2f\n",ans2 != 0 ? ans1 / ans2 : 0);
    }
    return 0;
}