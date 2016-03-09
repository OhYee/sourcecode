#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

#define REP(n) for(int o=0;o<n;o++)

const int maxn = 25;
const int delta[4] = {0,0,1,-1};

class LOVE {
private:
	int N,M,T;
	int x1,y1,x2,y2;
	bool visited[maxn][maxn];//是否已访问过该位置
	char map[maxn][maxn];//地图
	int ans;//结果


	void dfs(int x,int y,int l) {
		if(x < 0 || y < 0 || x >= M || y >= N ||
			visited[x][y] == true || map[x][y] == '*')
			return;
		if(x == x2&&y == y2)
			ans = l;

		visited[x][y] = true;

		for(int i = 0;i < 4;i++)
			dfs(x + delta[i],y + delta[3 - i],l + 1);

	}

public:
	bool Do() {
		scanf("%d%d%d",&N,&M,&T);
		//测试数据结束
		if(N == 0 && M == 0 && T == 0)
			return false;
		//输入地图
		for(int i = 0;i < M;i++) {
			for(int j = 0;j < N;j++) {
				char temp;
				scanf("\n%c\n",&temp);
				if(temp == 'S') {
					x1 = i;
					y1 = j;
					temp = '.';
				}
				if(temp == 'P') {
					x2 = i;
					y2 = j;
					temp = '.';
				}
				map[i][j] = temp;
			}
		}

		//输出地图
		/*
		for(int i = 0;i < M;i++) {
			for(int j = 0;j < N;j++)
				printf("%c",map[i][j]);
			printf("\n");
		}
		printf("\n");
		*/

		//初始化
		ans = -1;
		memset(visited,false,sizeof(visited));
		//dfs寻求最短路（用bfs应该会更快点，不过数据小，就不改了）
		dfs(x1,y1,0);

		/*
		for(int i = 0;i < M;i++) {
			for(int j = 0;j < N;j++)
				printf("%d",visited[i][j]);
			printf("\n");
		}
		printf("\n");
		*/

		printf("%s\n",ans == -1 || ans > T ? "NO" : "YES");

		return true;
	}
};



int main() {
	LOVE LIVE;
	while(LIVE.Do());
	return 0;
}