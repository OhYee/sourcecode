/*
By:OhYee
Github:OhYee
Blog:http://www.oyohyee.com/
Email:oyohyee@oyohyee.com

かしこいかわいい？
エリーチカ！
要写出来Хорошо的代码哦~
*/
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <bitset>
#include <functional>

using namespace std;


/*
	* Tarjan算法
	* 复杂度O(N+M)
*/
const int MAXN = 1005;//点数 
const int MAXM = 2*MAXN*MAXN;//边数 
struct Edge {
	int to,next;
}edge[MAXM];

int head[MAXN],tot;
int Low[MAXN],DFN[MAXN],Stack[MAXN],Belong[MAXN];//Belong数组的值是1~scc 
int Index,top;
int scc;//强连通分量的个数 

bool Instack[MAXN];
int num[MAXN];//各个强连通分量包含点的个数，数组编号1~scc 
			  //num数组不一定需要，结合实际情况 

void addedge(int u,int v) {
	edge[tot].to = v;
	edge[tot].next = head[u];
	head[u] = tot++;
}

void Tarjan(int u) {
	int v;
	Low[u] = DFN[u] = ++Index;
	Stack[top++] = u;
	Instack[u] = true;
	for(int i = head[u];i != -1;i = edge[i].next) {
		v = edge[i].to;
		if(!DFN[v]) {
			Tarjan(v);
			if(Low[u] > Low[v])
				Low[u] = Low[v];
		} else if(Instack[v] && Low[u] > DFN[v])
			Low[u] = DFN[v];
	}  
	
	if(Low[u] == DFN[u]) {
		scc++;
		do {
			v = Stack[--top];
			Instack[v] = false;
			Belong[v] = scc;
			num[scc]++;
		} while(v != u);
	}
}

void solve(int N) {
	memset(DFN,0,sizeof(DFN));
	memset(Instack,false,sizeof(Instack));
	memset(num,0,sizeof(num));
	Index = scc = top = 0;
	for(int i = 1;i <= N;i++)
		if(!DFN[i])
			Tarjan(i);
}

void init() {
	tot = 0;
	memset(head,-1,sizeof(head));
}


struct Point {
	long long x,y;
	long long r;
	int w;
	Point(long long a = 0,long long b = 0,long long c = 0,int d = 0):x(a),y(b),r(c),w(d) {}
	static long long distanceSqure(const Point &a,const Point &b) {
		return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
	}
};
Point p[MAXN];

int Min[MAXN];

int main() {
	//freopen("in.txt","r",stdin);
	cin.tie(0);
	cin.sync_with_stdio(false);

	int T;
	cin >> T;
	int kase = 1;
	while(T--) {

		int n;
		cin >> n;
		for(int i = 1;i <= n;i++) {
			Point &t = p[i];
			cin >> t.x >> t.y >> t.r >> t.w;
		}
		
		init();

		//建图
		for(int i = 1;i <= n;i++)
			for(int j = 1;j <= n;j++)
				if(i != j) {
					long long dis = Point::distanceSqure(p[i],p[j]);
					if((long long)p[i].r * (long long)p[i].r - dis >= 0)
						addedge(i,j);
				}

		//Tarjan + 缩点
		solve(n);

		//寻找入度为0的点
		memset(Instack,false,sizeof(Instack));

		for(int i = 1;i <= n;i++)
			for(int j = head[i];j != -1;j = edge[j].next)
				if(Belong[i] != Belong[edge[j].to])
					Instack[Belong[edge[j].to]] = true;

		for(int i = 1;i <= scc;i++)
			Min[i] = 10005;

		for(int i = 1;i <= n;i++) {
			int tscc = Belong[i];
			Min[tscc] = min(Min[tscc],p[i].w);
		}

		int ans = 0;
		for(int i = 1;i <= scc;i++) {
			if(Instack[i] == false)
				ans += Min[i];
		}

		cout << "Case #" << kase++ << ": " << ans << endl;

	}
	return 0;
}