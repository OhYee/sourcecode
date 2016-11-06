int H[maxn][maxn];

int Left[maxn];
int Right[maxn];

int MaxMatrix(bool Matrix[maxn][maxn],int n,int m,bool target) {
	memset(H,0,sizeof(H));
	memset(Left,0,sizeof(Left));
	memset(Right,0,sizeof(Right));

	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++) {
			if(Matrix[i][j] == target) {
				if(Matrix[i - 1][j])
					H[i][j] = H[i - 1][j] + 1;
				else
					H[i][j] = 1;
			}
		}

	int Max = 0;
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= m;j++) {
			if(Matrix[i][j] == target) {
				int t = j;
				while(t > 1 && H[i][j] <= H[i][t - 1])
					t = Left[t - 1];
				Left[j] = t;
			}
		}
		for(int j = m;j >= 1;j--) {
			if(Matrix[i][j] == target) {
				int t = j;
				while(t < m && H[i][j] <= H[i][t + 1])
					t = Right[t + 1];
				Right[j] = t;
			}
		}

		for(int j = 1;j <= m;j++) {
			if(Matrix[i][j] == target) {
				int S = H[i][j] * (Right[j] - Left[j] + 1);
				Max = max(Max,S);
			}
		}

	}

	return Max;
} 