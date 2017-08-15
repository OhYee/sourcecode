//#include <ctime>
//#define debug

#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long LL;

LL List[100005][10];
LL Pre[100005];
int pw[10][10];

int Pow(int a,int n) {
    if(pw[a][n] == -1){
        if(n == 1) pw[a][n] = a;
        else if(n == 0) pw[a][n] = 1;
        else pw[a][n] = Pow(a,n / 2) * Pow(a,n - n / 2);
    }
    return pw[a][n];
}

inline LL f(LL y,int k) {
    // if(List[y][k] == -1) {
    //     LL sum = 0;
    //     while(y) {
    //         sum += Pow((int)(y % 10),k);
    //         y /= 10;
    //     }
    //     List[y][k] = sum;
    // }
    return List[y][k];
}

int lower_bound(LL *arr,int size, LL key) {
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

inline int Count(LL pre) {
    return upper_bound(Pre,100000,pre) - lower_bound(Pre,100000,pre);
}

int main() {
    #ifdef debug
    freopen("in.txt","r",stdin);
    int start = clock();
    #endif

    cin.tie(0);
    cin.sync_with_stdio(false);

    int T;
    cin >> T;
    //scanf("%d",&T);

    memset(pw,-1,sizeof(pw));

    for(int i=0;i<100000;i++){
        for(int j=1;j<=9;j++){
            LL sum = 0;
            int y = i;
            while(y) {
                sum += Pow((int)(y % 10),j);
                y /= 10;
            }
            List[i][j] = sum;
        }
    }
    //memset(List,-1,sizeof(List));

    for(int kase = 1;kase <= T;kase++) {
        LL x;
        int k;
        cin >> x >> k;
        //scanf("%d%d",&x,&k);

        //前5位的各位k次方 - 前五位数据
        for(int i = 0;i < 100000;i++) {
            LL pre = f(i,k) - (LL)i * 100000;
            Pre[i] = pre;
        }
        
        sort(Pre,Pre + 100000);
        LL cnt = 0;

        //后5位的各位k次方 - 后五位数据
        for(int i = 0;i < 100000;i++) {
            LL post = f(i,k) - (LL)i;
            LL pre = x - post;
            cnt += Count(pre);
        }
        cout << "Case #" << kase << ": " << cnt-(x==0) << endl;
       // printf("Case #%d: %d\n",kase,cnt);
    }

    #ifdef debug
    printf("Time:%.3lfs\n",double(clock() - start) / CLOCKS_PER_SEC);
    #endif

    return 0;
}