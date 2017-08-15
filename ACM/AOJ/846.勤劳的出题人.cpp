/*/
#define debug
#include <ctime>
//*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 3005;
int a[maxn];
int b[maxn];
bool flag[maxn];

typedef int LL;
int upper_bound(LL *arr,int size, LL key) {
    int mid;
    int first = 0;
    int half;
    while (size > 0) {
        half = size >> 1;
        mid = half + first;
        if (arr[mid] > key) {
            size = half;
        } else {
            first = mid + 1;
            size = size - half - 1;
        }
    }
    return first;
}

int main(){
    #ifdef debug
    freopen("in.txt", "r", stdin);
    int START = clock();
    #endif
    cin.tie(0);
    cin.sync_with_stdio(false);

    int n,m;
    while(cin >> n >> m){
        memset(flag,false,sizeof(flag));
        for(int i=0;i<n;i++)
            cin >> a[i];
        for(int i=0;i<m;i++)
            cin >> b[i];
        sort(a,a+n);
        sort(b,b+m);
        int ans=0;
        int bpos=0;
        for(int i=0;i<n;i++){
            while(1){
                if(bpos>=m){
                    ans = n-i;
                    break;
                }
                if(b[bpos]>=a[i]){
                    bpos++;
                    break;
                }
                bpos++;
            }
            if(ans)
                break;
        }
        cout << ans << endl;
    }

    #ifdef debug
    printf("Time:%.3fs.\n", double(clock() - START) / CLOCKS_PER_SEC);
    #endif
    return 0;
}
