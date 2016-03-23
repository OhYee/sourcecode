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
    while(scanf("%d",&n) != EOF)
        printf("%d\n",n==1?1:6*n*n-12*n+8);
    return 0;
}