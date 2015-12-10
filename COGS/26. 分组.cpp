#include <cstdio>
#include <string.h>
#include <vector>
#include <iostream>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>
#include <stack>

using namespace std;

#define debug 0
#define REP(n) for(int o=0;o<n;o++)
#define REP1(m,n) for(int o1=0;o1<m;o1++)for(int o2=0;o2<n;o2++)
#define Min(a,b) ((a)<(b))?(a):(b)
#define Max(a,b) ((a)>(b))?(a):(b)
#define swap(a,b) {int Temp=a;a=b;b=Temp;}
#define abs(a) ((a>0)?a:(-a))

/*
#############################################################
*/

int n,m;
set<vector<int> > s;


void try_to_insert(vector<int>d){

}


void group(int n,int m,vector<int>d){
    #if debug
    printf("     将%d分成%d组\n",n,m);
    #endif // debug
    if(m==1){
        d.push_back(n);
        sort(d.begin(),d.end());
        /*long long temp=0;
        std::stringstream ss;
        //std::string str;
        REP(d.size())ss<<d[o];
        ss>>temp;
        s.insert(temp);
        */
        s.insert(d);
        #if debug
        cout<<"         获得一组"<<temp<<endl;
        #endif // debug
        return;
    }
    int l,r;
    for(l=1;l<n;l++){
            r=n-l;
            d.push_back(l);
            group(r,m-1,d);
            d.pop_back();
    }
}

int main(){
    #if !debug
    freopen("dataa.in","r",stdin);
    freopen("dataa.out","w",stdout);
    #endif // debug

    #if debug
    printf("读入数据准备\n");
    #endif // debug

    cin>>n>>m;

    #if debug
    printf("数据读入n(%d) m(%d)\n",n,m);
    #endif // debug

    vector<int>d;
    d.clear();
    group(n,m,d);

    #if debug
    printf("分组完成\n共分成%d组\n",s.size());
    #endif // debug

    cout<<s.size()<<endl;

    set<vector<int> >::iterator it;
    it=s.begin();
    REP(s.size()){
        for(int i=0;i<(*it).size();i++){
            cout<<(*it)[i]<<" ";
        }
        it++;
        cout<<endl;
    }

    return 0;
}
