/*/
#define debug
#include <ctime>
//*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long LL;

const int maxn = 12;

struct Node{
    LL n;
    int k;
    Node(LL a,int b):n(a),k(b){}
};

LL POW(LL a,int n) {
    LL t;
    if(n == 0) return 1;
    if(n == 1) return a;
    t = POW(a,n / 2);
    t = t * t;
    if((n & 1) == 1)t = t * a;
    return t;
}

LL swap(LL n,int a,int b){
    LL t1 = (n/POW(10,a-1)) % 10LL;
    LL t2 = (n/POW(10,b-1)) % 10LL;

    n = n - t1 * POW(10,a-1) - t2 * POW(10,b-1) + t1 * POW(10,b-1) + t2 * POW(10,a-1);
    return n;
}


queue<Node> Q;
vector<LL> v;

LL bfs(LL n,int k){
    while(!Q.empty())Q.pop();
    v.clear();

    int size = 0;
    LL temp = n;
    while(temp){
        temp/=10;
        size++;
    }

    Q.push(Node(n,0));
    v.push_back(n);
    while(!Q.empty()){
        LL tn = Q.front().n;
        int tk = Q.front().k;
        Q.pop();

        
        if(tk < k){
            for(int i=1;i<size;i++){
                LL tt = swap(tn,i,i+1);
                
                if(lower_bound(v.begin(),v.end(),tt) == v.end()){
                    v.insert(lower_bound(v.begin(),v.end(),tt),tt);
                    Q.push(Node(tt,tk+1));
                }
            }
        }
    }
    sort(v.begin(),v.end());
    for(size_t i=0;i<v.size();i++)
        cout<<v[i]<<" ";
        cout<<endl;
    return v[v.size()-1];
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
        LL n;
        int k;
        cin >> n >> k;
        cout << bfs(n,k) << endl;
    }

    #ifdef debug
    printf("Time:%.3fs.\n", double(clock() - START) / CLOCKS_PER_SEC);
    #endif
    return 0;
}
