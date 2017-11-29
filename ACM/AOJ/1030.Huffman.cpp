#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

vector<int> v;

void show(){
    int sz = v.size();
    for(int i=0;i<sz;++i){
        printf("%d ",v[i]);
    }
    printf("\n");
}

int main(){
    freopen("in.txt","r",stdin);
    v.clear();
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        int t;
        scanf("%d",&t);
        v.insert(lower_bound(v.begin(),v.end(),t),t);
    }
    //show();
    int ans = 0;
    while(v.size() > 1){
        int p = v[0]+v[1];
        ans += p;
        v.erase(v.begin());
        v.erase(v.begin());
        v.insert(lower_bound(v.begin(),v.end(),p),p);
        //show();
    }
    printf("%d\n",ans);
    return 0;
}


