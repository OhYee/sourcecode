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
#include <queue>
#include <stack>
using namespace std;
 
#define REP(n) for(int o=0;o<n;o++)
 
int main() {
    double v;
    while(scanf("%lf",&v) != EOF)
        printf("%.3f\n",v*v / 9.8);
    return 0;
}