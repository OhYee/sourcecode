//**
#define debug
#include <ctime>
//*/

#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int main() {
#ifdef debug
    freopen("in.txt", "r", stdin);
    int START = clock();
#endif

    int T;
    cin >> T;
    while (T--) {
        int n, sum = 0;
        cin >> n;
        while (n--) {
            int A, B;
            cin >> A >> B;
            sum += A * B;
        }
        cout << sum << endl;
    }

#ifdef debug
    printf("Time:%.3f s.\n", double(clock() - START) / CLOCKS_PER_SEC);
#endif
    return 0;
}