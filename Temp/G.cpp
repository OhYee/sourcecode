//*/
#define debug
#include <ctime>
//*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

typedef int LL;

struct OP {
    char op;
    LL num;
    bool flag;
    LL ans, temp;
    OP(char _op, LL _num) {
        op = _op;
        num = _num;
        flag = true;
        ans = temp = 0 ;
    }
    void show_status() {
        //printf("%c %I64d (%d) %I64d %I64d\n", op, num, flag, ans, temp);
    }
};

struct CALC {
    vector<OP> L;
    int last;
    void init() {
        L.clear();
        L.push_back(OP('+', 1));
        L[0].temp = 1;
        last = 0;
    }

    void add(char op, LL num) {
        // printf("add\n");
        L.push_back(OP(op, num));
        // show_status();
    }
    void del(int t) {
        // printf("del %d\n",t);
        L[t - 1].flag = false;
        last = min(last, t - 2);
        // show_status();
    }
    void mod(int t, char op, LL num) {
        // printf("mod\n");
        L[t - 1] = OP(op, num);
        last = min(last, t - 1);
        // show_status();
    }
    void calc() {
        // printf("query\n");

        LL ans ,temp;
        if(last==0){
            ans = L[0].ans;
            temp = L[0].ans;
        }else{
            ans = L[last-1].ans;
            temp = L[last-1].temp;
        }
        
        size_t sz = L.size();

        for (size_t i = last; i < sz; i++) {
            if (L[i].flag) {
                char op = L[i].op;
                LL num = L[i].num;

                if (op == '+') {
                    L[i].ans = ans += temp;
                    L[i].temp = temp = num;
                } else {
                    L[i].temp = temp *= num;
                }
            }
        }
        ans += temp;
        last = sz - 1;
        printf("%d\n", ans);
        //show_status();
    }
    void show_status() {
        printf("%d\n", last);
        size_t sz = L.size();
        for (size_t i = 0; i < sz; i++) {
            L[i].show_status();
        }
    }
};

CALC calc;
int main() {
#ifdef debug
    freopen("in.txt", "r", stdin);
    int START = clock();
#endif
    cin.tie(0);
    cin.sync_with_stdio(false);
freopen("out.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int kase = 1; kase <= T; kase++) {
        printf("Case %d:\n", kase);
        int n;
        scanf("%d", &n);

        calc.init();
        char s[20];
        LL num;
        int t;
        for (int i = 0; i < n; i++) {
            scanf("%s", s);
            if (s[0] == 'a') {
                scanf("%s%d", s, &num);
                calc.add(s[0], num);
            } else if (s[0] == 'm') {
                scanf("%d%s%d", &t, s, &num);
                calc.mod(t, s[0], num);
            } else if (s[0] == 'd') {
                scanf("%d", &t);
                calc.del(t);
            } else {
                calc.calc();
            }
        }
    }

#ifdef debug
    printf("Time:%.3fs.\n", double(clock() - START) / CLOCKS_PER_SEC);
#endif
    return 0;
}