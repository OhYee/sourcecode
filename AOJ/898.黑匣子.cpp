//*/
#define debug
#include <ctime>
//*/
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

const int maxn = 30005;
int A[maxn];
int U[maxn];

int main() {
#ifdef debug
    freopen("in.txt", "r", stdin);
    int START = clock();
#endif
    cin.tie(0);
    cin.sync_with_stdio(false);

    int m, n;
    while (cin >> m >> n) {
        for (int i = 0; i < m; i++)
            cin >> A[i];

        for (int i = 0; i < n; i++)
            cin >> U[i];

        sort(U, U + n);

        vector<int> v;
        int I = 0;
        int getNum = 0, addNum = 0;
        for (int i = 0; i < n + m; i++) {
            if (U[getNum] == addNum) {
                //cout << "Get(" << I << ")" << endl;
                cout << v[I++] << endl;
                getNum++;
                if (getNum >= n)
                    break;
            } else {
                //cout << "Add(" << A[addNum] << ")  ";

                v.insert(lower_bound(v.begin(), v.end(), A[addNum]), A[addNum]);

                // for (size_t i = 0; i < v.size(); i++)
                //     cout << v[i] << " ";
                // cout << endl;

                addNum++;
            }
        }
    }

#ifdef debug
    printf("Time:%.3fs.\n", double(clock() - START) / CLOCKS_PER_SEC);
#endif
    return 0;
}