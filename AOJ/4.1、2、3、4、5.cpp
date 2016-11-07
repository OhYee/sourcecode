#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

#define REP(n) for(int o=0;o<n;o++)

bool Do() {
    int n,m;
    scanf("%d%d",&n,&m);
    if(n == 0 && m == 0)return false;

    int r,c;
    r = m / 2 - n;
    c = n - r;

    if(m % 2 != 0 || r < 0 || c < 0) {
        printf("Error\n");
    } else {
        printf("%d %d\n",c,r);
    }
    return true;
}

int main() {
    while(Do());
    return 0;
}