#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
 
const int maxn = 1005;
int node[maxn];
int ans[maxn];
 
int main(){
    cin.tie(0);
    cin.sync_with_stdio(false);
     
    int n;
    while(cin>>n){
        for(int i=1;i<=n;i++)
            cin>>node[i];
         
        int len = 1;
        ans[1] = node[1];
        for(int i = 2; i <= n; ++i) {
         if(node[i] > ans[len])
              ans[++len] = node[i];
            else
              *lower_bound(ans + 1,ans + 1 + len,node[i]) = node[i];
        }
 
        cout<< n - len<<endl;
    }
}