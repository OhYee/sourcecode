/*/
#define debug
#include <ctime>
//*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 105;
int a[maxn];

typedef int LL;

int lower_bound(LL *arr,int size, LL key) {
    int half;
    int mid;
    int first = 0;
    while (size > 0) {
        half = size >> 1;
        mid = first + half;
        if (arr[mid] > key) {
            first = mid + 1;
            size = size - half - 1;
        } else {
            size = half;
        }
    }
    return first;
}
int upper_bound(LL *arr,int size, LL key) {
    int half;
    int mid;
    int first = 0;
    while (size > 0) {
        half = size >> 1;
        mid = first + half;
        if (arr[mid] >= key) {
            first = mid + 1;
            size = size - half - 1;
        } else {
            size = half;
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

    int T;
    cin >> T;
    while(T--){
        int n,k;
        cin >> n >> k;
        for(int i=0;i<n;i++)
            cin >> a[i];

        k = a[k-1];
        if(!k)
            cout << lower_bound(a,n,k) << endl;
        else
            cout << upper_bound(a,n,k) << endl;
    }

    #ifdef debug
    printf("Time:%.3fs.\n", double(clock() - START) / CLOCKS_PER_SEC);
    #endif
    return 0;
}
