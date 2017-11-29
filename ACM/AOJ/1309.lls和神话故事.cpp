#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
typedef unsigned long long LL;


LL n,m;


// (1+t)*t/2 >= m     min(t)+m
int main(){

    cin.sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    LL l=0,r=1e10;
    LL t=0;
    while(l<r){
        t = (l+r)/2;
        if(t*(t+1) >= (n-m)*2)
            r = t;
        else
            l = t + 1;
        // cout << l <<" " << r << endl;
    }
    cout << l + m << endl;
    return 0;
}
