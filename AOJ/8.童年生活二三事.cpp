#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

#define REP(n) for(int o=0;o<n;o++)

const int maxn = 41;
int ans[maxn]={1,1,2,3,5,8,13,21,34,55,89,144,233,377,610,
987,1597,2584,4181,6765,10946,17711,28657,46368,75025,121393,
196418,317811,514229,832040,1346269,2178309,3524578,5702887,
9227465,14930352,24157817,39088169,63245986,102334155,165580141};

int main() {

	//ans[0] = 1;
	//ans[1] = 1;
	//for(int i = 2;i < maxn;i++) {
	//	ans[i] = ans[i - 1] + ans[i - 2];
	//}

	//printf("ans[]={");
	//REP(maxn)
	//	printf("%d,",ans[o]);
	//printf("};\n");

	int n;
	while(scanf("%d",&n),n != 0) {
		printf("%d\n",ans[n]);
	}

	return 0;
}