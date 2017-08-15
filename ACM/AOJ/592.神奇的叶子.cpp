#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

#define REP(n) for(int o=0;o<n;o++)

int main() {
    int a1,n,d;
    scanf("%d%d%d",&a1,&n,&d);
    printf("%d\n",a1*n + (n*(n - 1)*d) / 2);
    return 0;
}