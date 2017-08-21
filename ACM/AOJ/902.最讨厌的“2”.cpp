#include <cmath>
#include <cstdio>
#include <ctime>
const int maxn = 2e5 + 5;

typedef long long LL;

int n, m;
LL a[maxn];

LL read_int() {
    char c;
    LL ans = 0;
    while (c = getchar(), !(c >= '0' && c <= '9'))
        ;
    while (c >= '0' && c <= '9') {
        ans *= 10;
        ans += (int)c - '0';
        c = getchar();
    }
    return ans;
}
long long add(long long a, long long b) { return a + b; }

class ST {
    struct Tree {
        int l, r;
        LL n;
    };

    Tree T[maxn * 8];

  public:
    inline static int getLastRowBeginPosition(int n) {
        int ans = 1 << ((int)(log(n) / log(2)));
        if (ans < n)
            ans <<= 1;
        return ans;
    }
    LL BuildTree(int a, int b, LL (*compare)(LL, LL), LL *num, int pos = 1) {
        // printf("build(%d,%d,%d)\n", a, b, pos);

        T[pos].l = a;
        T[pos].r = b;

        if (a == b) {
            if (a > n)
                return T[pos].n = 0;
            else
                return T[pos].n = num[a];
        }

        int mid = (a + b) >> 1;
        int leftchild = pos << 1;
        int rightchild = (pos << 1) + 1;

        return T[pos].n =
                   compare(BuildTree(a, mid, compare, num, leftchild),
                           BuildTree(mid + 1, b, compare, num, rightchild));
    }

    LL query(int a, int b, LL (*compare)(LL, LL), LL *num, int pos = 1) {
        // printf("query(%d,%d,%d)\n", a, b, pos);

        if (a == b)
            return T[getLastRowBeginPosition(n) - 1 + a].n;

        if (T[pos].n == 0)
            return 0;

        int &l = T[pos].l;
        int &r = T[pos].r;

        if (a == l && b == r)
            return T[pos].n;

        int mid = (l + r) >> 1;
        int leftchild = pos << 1;
        int rightchild = (pos << 1) + 1;

        if (b <= mid)
            return query(a, b, compare, num, leftchild);
        if (a > mid)
            return query(a, b, compare, num, rightchild);
        return compare(query(a, mid, compare, num, leftchild),
                                  query(mid + 1, b, compare, num, rightchild));
    }

    LL update(int a, int b, LL (*compare)(LL, LL), LL *num, int pos = 1) {
        // printf("     update(%d,%d,%d)\n", a, b, pos);

        int &l = T[pos].l;
        int &r = T[pos].r;

        if (l == r)
            return T[pos].n >>= 1;

        if (T[pos].n == 0)
            return 0;

        int mid = (l + r) >> 1;
        int leftchild = pos << 1;
        int rightchild = (pos << 1) + 1;

        if (b <= mid) {
            T[pos].n =
                compare(update(a, b, compare, num, leftchild), T[rightchild].n);
        } else if (a > mid) {
            T[pos].n =
                compare(T[leftchild].n, update(a, b, compare, num, rightchild));
        } else {
            T[pos].n = compare(update(a, mid, compare, num, leftchild),
                               update(mid + 1, b, compare, num, rightchild));
        }
        return T[pos].n;
    }

    void printTree() {
        for (int i = 1; i < getLastRowBeginPosition(n) << 1; ++i) {
            if ((i > 0) && (i & (i - 1)) == 0)
                printf("\n");
            printf("[%d (%d,%d) %I64d] ", i, T[i].l, T[i].r, T[i].n);
        }
        printf("\n");
    }
};

ST tree;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //int START = clock();
    while (~scanf("%d%d", &n, &m)) {
        for (int i = 1; i <= n; ++i) {
            scanf("%I64d", &a[i]);
            // printf("%d\n",i);
        }
        // printf("read finish\n");
        tree.BuildTree(1, ST::getLastRowBeginPosition(n), add, a);
        // tree.printTree();
        for (int i = 1; i <= m; ++i) {
            int c, l, r;
            scanf("%d%d%d", &c, &l, &r);
            if (c == 1)
                tree.update(l, r, add, a);
            else
                printf("%I64d\n", tree.query(l, r, add, a));
            // tree.printTree();
        }
    }
    //printf("Time:%.3fs.\n", double(clock() - START) / CLOCKS_PER_SEC);
    return 0;
}