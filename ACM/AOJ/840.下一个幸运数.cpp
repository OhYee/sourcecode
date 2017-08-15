/*/
#define debug
#include <ctime>
//*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;


typedef unsigned long long LL;
const int maxn = 5000;
LL L[maxn];
int pos=0;

void dfs(LL t){
    if(t >= 7777777777LL)
        return;
    L[pos++] = t*10+4;
    L[pos++] = t*10+7;
    dfs(t*10+4);
    dfs(t*10+7);
}

LL lower_bound(LL *arr,int size, LL key) {
    int half;
    int mid;
    int first = 0;
    while (size > 0) {
        half = size >> 1;
        mid = first + half;
        if (arr[mid] < key) {
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

    dfs(0LL);
    sort(L,L+pos);
    /*
    for(int i=0;i<pos;i++)
        cout << i << " " << L[i]<< endl;
    */

    int T;
    cin >> T;
    while(T--){
        int l,r;
        cin >> l >> r;
        LL pos1 = lower_bound(L,pos,l);
        LL pos2 = lower_bound(L,pos,r);

        LL ans1 = (L[pos1]-l+1)*L[pos1];//��һ����
        LL ans2 = 0;
        for(int i=pos1;i<pos2;i++)
            ans2 += (L[i+1] - L[i])*L[i+1];
        LL ans3 = (r-L[pos2])*L[pos2];
        //cout <<pos1<<" "<<pos2<<endl;
        //cout << ans1 << " " << ans2 << " " << ans3 << endl;
        cout << ans1+ans2+ans3 << endl;
    }

    #ifdef debug
    printf("Time:%.3fs.\n", double(clock() - START) / CLOCKS_PER_SEC);
    #endif
    return 0;
}
