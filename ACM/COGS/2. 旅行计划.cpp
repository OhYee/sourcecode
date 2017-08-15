#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

//Define the file.
void file(){
    freopen("djs.in","r",stdin);
    freopen("djs.out","w",stdout);
}


const int maxn=105;

int n,m,v;
vector<int>path[maxn];//The path from one city to another city.
int dis[maxn][maxn];//The distance of the path.

string to_string(int a);
void dfs(int a,string way,int dis);

int reasult_distance[maxn];
string reasult_path[maxn]="";

int main(){

    file();

    dis[0][0]=0;

    //n means the number of the city. m means the number of the way between cities. v means the begin city
    scanf("%d%d%d",&n,&m,&v);


    for(int i=0;i<m;i++){
            int x,y,temp;
            scanf("%d%d%d",&x,&y,&temp);
            path[x].push_back(y);
            dis[x][y]=temp;
    }//Load the map



    //From the begin city go to another city.
    dfs(v,to_string(v),0);
    reasult_distance[v]=0;


    for(int i=0;i<n;i++){
            cout<<i<<":"<<endl;
        if(reasult_distance[i]==0){
            printf("no\n");
        }else{
            cout<<"path:"<<reasult_path[i]<<endl<<"cost:"<<reasult_distance[i]<<endl;
        }
    }

    return 0 ;
}

void dfs(int a,string way,int dis1){


    //cout<<a<<" "<<way<<" "<<dis1<<endl;

    if((reasult_distance[a]>dis1)||(reasult_distance[a]==0)){
        reasult_distance[a]=dis1;
        reasult_path[a]=way;
    }else{return;}

    for(int i=0;i<path[a].size();i++){
            int newcity=path[a][i];
        dfs(newcity,way+" "+to_string(newcity),dis1+dis[a][newcity]);
    }

}

string to_string(int a){//From Int to String

    std::stringstream ss;
    std::string str;
    ss<<a;
    ss>>str;
    return str;
}
