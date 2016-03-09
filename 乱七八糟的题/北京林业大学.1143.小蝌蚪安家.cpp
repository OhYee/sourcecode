#include <cstdio>
#include <algorithm>
using namespace std;

#define REP(n) for(int o=0;o<n;o++)
#define REP2(m,n) for(int i=0;i<m;i++)for(int j=0;j<n;j++)

class D{
	private:
		static const int maxn=105;
		char map[maxn][maxn];
		bool mark[maxn][maxn];
		int n,m;

		int DFS(int x,int y){
			if(!(x>=0&&y>=0&&x<n&&y<m)||(map[x][y]=='#'||mark[x][y]==true))return 0;
			//printf("get %d %d\n",x,y);
			mark[x][y]=true;
			return 1+DFS(x+1,y)+DFS(x-1,y)+DFS(x,y+1)+DFS(x,y-1);
		}

	public:
		bool Do(){
			if(scanf("%d%d",&n,&m)==EOF)return false;
			REP(n)
				scanf("%s",map[o]);

			/*
			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++)
					printf("%c",map[i][j]);
				printf("\n");
			}
			printf("\n");
			*/

			REP2(n,m)
				mark[i][j]=false;

			int Max=0;

			REP2(n,m)
				if(map[i][j]=='.' && mark[i][j]==false)
					Max=max(Max,DFS(i,j));

			printf("%d\n",Max);
			return true;
		}
};

int main(){
	freopen("in.txt","r",stdin);
	D d;
	while(d.Do());
	return 0;
}

