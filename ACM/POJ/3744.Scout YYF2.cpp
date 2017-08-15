/*/
#define debug
#include <ctime>
//*/
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <set>
using namespace std;

const int maxn = 15;

class Matrix {
  public:
    static const int LINE = 2; //行列数
    double matrix[LINE][LINE];

    Matrix() {
        for (int i = 0; i < LINE; i++)
            for (int j = 0; j < LINE; j++)
                matrix[i][j] = 0;
    }

    Matrix operator*(Matrix rhs) { return mul(*this, rhs); }
    Matrix operator^(int n) { return pow(*this, n); }

    static Matrix mul(Matrix a, Matrix b) {
        Matrix ans;
        for (int i = 0; i < LINE; i++)
            for (int j = 0; j < LINE; j++) {
                ans.matrix[i][j] = 0;
                for (int k = 0; k < LINE; k++)
                    ans.matrix[i][j] += a.matrix[i][k] * b.matrix[k][j];
            }
        return ans;
    }

    static Matrix pow(Matrix a, int n) {
        if (n == 0) {
            Matrix E;
            for (int i = 0; i < LINE; i++)
                E.matrix[i][i] = 1;
            return E;
        }
        if (n == 1)
            return a;
        Matrix ans = pow(a, n / 2);
        ans = ans * ans;
        if (n & 1)
            return ans * a;
        return ans;
    }
    void print() {
        for (int i = 0; i < LINE; i++) {
            printf("|");
            for (int j = 0; j < LINE; j++)
                printf("%f ", matrix[i][j]);
            printf("|\n");
        }
        printf("\n");
    }
};

int mines[maxn];

int main() {
#ifdef debug
    freopen("in.txt", "r", stdin);
    int START = clock();
#endif
    cin.tie(0);
    cin.sync_with_stdio(false);

    int n;
    double p;
    while (cin >> n >> p) {
        mines[0] = 0;
        for (int i = 1; i <= n; i++)
            cin >> mines[i];

        sort(mines + 1, mines + 1 + n);

        double ans = 1;
        for (int i = 1; i <= n; i++) {
            int dis = mines[i] - mines[i - 1];

            if (dis == 1) {
                ans = 0;
                break;
            }

            Matrix dp, pro;
            dp.matrix[0][0] = p;
            dp.matrix[1][0] = 1;

            pro.matrix[0][0] = p;
            pro.matrix[0][1] = 1 - p;
            pro.matrix[1][0] = 1;

            dp = Matrix::pow(pro, dis - 2) * dp;

            dp.print();

            ans *= (1 - dp.matrix[0][0]);
        }

        cout << fixed << setprecision(7) << ans << endl;
    }

#ifdef debug
    printf("Time:%.3fs.\n", double(clock() - START) / CLOCKS_PER_SEC);
#endif
    return 0;
}