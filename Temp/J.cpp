#include <bits/stdc++.h>

//#define Ms(a,b) memset(a,(b),sizeof(a))
//#define M(a) Ms(a,0)
//#define sf(a) scanf("%d",&a)
using namespace std;

const int maxn = 2e5 + 50;

int cg[10];
long long la[10];
long long lb[10];
void Hash(long long A, long long *Alist, int N) {
    for (int i = 0; i < N; i++) {
        Alist[N - i - 1] = A % 10;
        A /= 10;
    }
}
void unHash(long long &A, long long *Alist, int N) {
    A = 0;
    for (int i = 0; i < N; i++)
        A = A * 10 + Alist[i];
}

map<long long, int> maze;
void bfs(long long A, int N) {
    queue<long long> que;
    que.push(A);
    maze.clear();
    maze[A] = 0;
    long long t;
    while (!que.empty()) {
        long long now = que.front();
        que.pop();
        long long len = maze[now];
        Hash(now, la, N);
        for (int i = 1; i < N; i++) {
            swap(la[0], la[i]);
            unHash(t, la, N);
            if (maze.count(t) == 0) {
                maze[t] = len + 1;
                que.push(t);
            }
            swap(la[0], la[i]);
        }
    }
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(false);
    int N;
    long long A, B;
    while (~scanf("%d", &N)) {
        A = 0;
        for (int i = 0; i < N; i++)
            A = A * 10 + i + 1;
        bfs(A, N);
        for (int i = 0; i < 5; i++) {
            scanf("%lld %lld", &A, &B);
            Hash(A, la, N);
            Hash(B, lb, N);

            for (int i = 0; i < N; i++)
                cg[la[i]] = i + 1;
            for (int i = 0; i < N; i++)
                la[i] = cg[la[i]];
            for (int i = 0; i < N; i++)
                lb[i] = cg[lb[i]];
            unHash(B, lb, N);
            cout << maze[B] << endl;
        }
    }
    return 0;
}