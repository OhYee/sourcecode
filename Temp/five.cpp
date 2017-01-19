//*/
#define debug
#include <ctime>
//*/
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int delta[3][2]={{1,0},{1,1},{0,1}};
const int maxn = 16;

bool Map1[maxn][maxn];
bool Map2[maxn][maxn];
bool vis[maxn][maxn][3];

bool dfs(bool Map[maxn][maxn],int x,int y,int dirc,int deep){
    if(deep==5)
        return true;
    vis[x][y][dirc] = true;
    x += delta[dirc][0];
    y += delta[dirc][1];
    if((x>= 1&& x<=15 && y>=1 && y<=15) && Map[x][y])
        return dfs(Map,x,y,dirc,deep+1);
    return false;
}
bool judge(bool Map[maxn][maxn]){
    memset(vis,false,sizeof(vis));
    for(int i=1;i<=15;i++)
        for(int j=1;j<=15;j++)
            if(Map[i][j])
                for(int k=0;k<3;k++)
                    if(!vis[i][j][k])
                        if(dfs(Map,i,j,k,1))
                            return true;
    return false;
}

void Do(){
    int n;
    cin >> n;
    int step=0;
    int Ok = false;
    bool A = true;
    memset(Map1,false,sizeof(bool)*maxn*maxn);
    memset(Map2,false,sizeof(bool)*maxn*maxn);
    for(step=1;step<n && !Ok;step++,A=!A){
        int x,y;
        cin >> x >> y;
        if(A){
            Map1[x][y] = true;
            if(judge(Map1))
                Ok = true;
        }else{
            Map2[x][y] = true;
            if(judge(Map2))
                Ok = true;
        }
    }
    //最后多运行一次循环头
    if(Ok)
        cout << (A?"B":"A") << " " << step-1 << endl;
    else
        cout << "Tie" << endl;
}

int main(){
    #ifdef debug
    freopen("in.txt", "r", stdin);
    int START = clock();
    #endif
    cin.tie(0);
    cin.sync_with_stdio(false);
    
    Do();
    
    #ifdef debug
    printf("Time:%.3fs.\n", double(clock() - START) / CLOCKS_PER_SEC);
    #endif
    return 0;
}