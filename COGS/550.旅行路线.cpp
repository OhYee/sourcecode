#include <cstdio>
#include <algorithm> 
#include <cstring>
using namespace std;

//宏定义列表
#define REP(n) for(int o=0;o<n;o++)

//变量列表
const int max_n = 5;
const int max_m = 55;
int n, m;
int map[max_n][max_m];
int L[max_n*max_m];
int ans = 0;
int delta[] = { 0,0,1,-1};

void Do(int x, int y, int cnt,  int visited[max_n][max_m]) {
	if (x < 0 || y < 0 || x >= n || y >= m || visited[x][y] == 1)
		return;
	if (map[x][y] != L[cnt])
		return;
	if (cnt == n*m - 1) {
		++ans;
		return;
	}
	
	int visited2[max_n][max_m];
	memcpy(visited2, visited, max_m*max_n*sizeof(visited));
	visited2[x][y] = 1;

	for (int k = 0; k < 4; k++)
		Do(x + delta[k], y + delta[3 - k], cnt + 1, visited2);

	return;
}


int main() {
	freopen("trip.in", "r", stdin);
	freopen("trip.out", "w", stdout);

	int visited[max_n][max_m] = { 0 };

	//输入部分
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			char temp;
			scanf("\n%c\n", &temp);
			map[i][j] = temp - '0';
		}
	REP(n*m) {
		char temp;
		scanf("\n%c\n", &temp);
		L[o] = temp - '0';
	}
	//数据输入结束

	//数据处理开始
	for (int k = 0; k < n; ++k) {
		Do(k, 0, 0, visited);
		Do(k, m - 1, 0, visited);
	}
	for (int k = 1; k < m-1; ++k) {
		Do(0, k, 0, visited);
		Do(n - 1, k, 0, visited);
	}

	//数据处理结束

	//数据输出开始
	printf("%d", ans % 11192869);
	//数据输出结束
	return 0;
}
