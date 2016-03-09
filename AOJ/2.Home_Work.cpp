#include <cstdio>
#include <algorithm>
using namespace std;

#define REP(n) for(int o=0;o<n;o++)


class LOVE {
private:
	static const int maxn = 25;
	int M, N;
	struct node {
		int T, V;
		double p;
	}paper[maxn];

	static bool compare_node(node a, node b) {
		return a.p > b.p;
	}

public:
	bool Do() {
		scanf("%d%d", &M, &N);
		if (M == 0 && N == 0)return false;
		REP(M) {
			int T, V;
			scanf("%d%d", &T, &V);
			paper[o].T = T;
			paper[o].V = V;
			paper[o].p = (double)V / (double)T;
		}

		sort(paper, paper + M, compare_node);

		//REP(M)
			//printf("T=%d V=%d p=%f\n", paper[o].T, paper[o].V, paper[o].p);

		double ans = 0;
		for (int i = 0; i < M; i++) {
			int temp = N - paper[i].T;
			ans += paper[i].V;
			if (temp < 0) {
				ans += temp*paper[i].p;
				break;
			}
			N = temp;
		}

		printf("%.2f\n", ans);
		return true;
	}
};

int main() {
	LOVE LIVE;
	while (LIVE.Do());
	return 0;
}