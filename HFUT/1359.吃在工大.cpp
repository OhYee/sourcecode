/*
By:OhYee
Github:OhYee
HomePage:http://www.oyohyee.com
Email:oyohyee@oyohyee.com

かしこいかわいい？
エリーチカ！
要写出来Хорошо的代码哦~
*/

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <queue>
#include <stack>
#include <map>
using namespace std;

const int maxn = 1000;


bool G[maxn][maxn];

bool vis[maxn];

int n;

bool HasLoop() {
	//判断是否存在环
	for(int i = 1;i <= n;i++)
		if(!vis[i])
			return false;
	return true;
}

bool IsStart(int k) {
	//判断是否入度为0
	for(int i = 1;i <= n;i++)
		if(G[i][k])
			return false;
	return true;
}


bool TopoSort(int _n,int *ans) {
	//拓扑排序
	/*
	参数:
	邻接矩阵G[][]
	顶点数目n
	用于保存拓扑排序结果的数组 ans[]
	*/
	//输出结果下标初始化
	int pos = 0;

	//已访问数组初始化
	memset(vis,false,sizeof(vis));

	//可被选择的数
	priority_queue<int> Q;

	//判断i是否为源
	for(int i = 1;i <= n;i++) {
		if(IsStart(i))
			Q.push(i);
	}

	while(!Q.empty()) {
		int k = Q.top();
		Q.pop();

		if(vis[k])
			continue;
		else
			vis[k] = true;

		//记录到结果中
		ans[pos++] = k;

		for(int i = 1;i <= n;i++) {
			if(G[k][i]) {
				//路径k~i存在
				//删除路径
				G[k][i] = false;
				//如果成为入度为0的点
				if(IsStart(i))
					Q.push(i);
			}
		}
	}

	//判断是否有环
	return HasLoop();
}



void Do() {
	memset(G,0,sizeof(G));
	int m;
	scanf("%d%d",&n,&m);
	for(int i = 0;i < m;i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		G[a][b] = 1;
	}

	int ans[maxn];
	if(TopoSort(n,ans)) {
		for(int i = 0;i < n;i++) {
			if(i)
				printf(" ");
			printf("%d",ans[i]);
		}
	} else {
		printf("-1");
	}
	printf("\n");

}

int main() {
	int T;
	scanf("%d",&T);
	while(T--)
		Do();
	return 0;
}