#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

const int maxn=10005;
vector<int> v;
//int vis[maxn];

int d(int t){
    int ans = t;
    while(t){
        ans += t%10;
        t/=10;
    }
    return ans;
}

void getans(int t){
    v.clear();
    for(int i=max(0,t-1000);i<=t+1000;++i){
        if(d(i)==t)
            v.push_back(i);
    }
    int sz = v.size();
    printf("%d\n",sz);
    for(int i=0;i<sz;++i)
        printf("%d\n",v[i]);
}

int main(){
    //freopen("in.txt","r",stdin);
    //memset(vis,0,sizeof(vis));
    int n;
    while(scanf("%d",&n)!=EOF){
        getans(n);
    }
    return 0;
}
