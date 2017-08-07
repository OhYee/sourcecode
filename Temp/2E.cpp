#include <cstdio>
using namespace std;

struct Tree {
    int l, r;
    int n;
};
int BuildTree(int a, int b, int (*compare)(int, int), int *num, Tree *T,
              int pos = 1) {
    T[pos].l = a;
    T[pos].r = b;
    if (b - a == 1)
        return T[pos].n = compare(num[a], num[b]);

    int mid = (a + b) / 2;
    int leftchild = 2 * pos;
    int rightchild = 2 * pos + 1;

    T[pos].n = compare(BuildTree(a, mid, compare, num, T, leftchild),
                       BuildTree(mid, b, compare, num, T, rightchild));
}

int Update(int pos,int num){

}

int GetNum(int a, int b, int (*compare)(int, int), int *num, Tree *T,
           int pos = 1) {
    if (a == b)
        return num[a];

    int &l = T[pos].l;
    int &r = T[pos].r;

    if (a == l && b == r)
        return T[pos].n;

    int mid = (l + r) / 2;
    int leftchild = 2 * pos;
    int rightchild = 2 * pos + 1;

    if (b <= mid)
        return GetNum(a, b, compare, num, T, leftchild);
    if (a >= mid)
        return GetNum(a, b, compare, num, T, rightchild);

    return T[pos].n = compare(GetNum(a, mid, compare, num, T, leftchild),
                              GetNum(mid + 1, b, compare, num, T, rightchild));
}

int main() {
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }

        for (int i = 0; i < m; i++) {
            char c;
            int a, b;
            scanf("\n%c", &c, &a, &b);
        }
    }
    return 0;
}