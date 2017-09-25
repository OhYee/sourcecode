#include <cstdio>
#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

const int maxn = 30;
#define Log(format, ...) // printf(format, ##__VA_ARGS__)

vector<pair<char, char>> vec;
set<int> s[maxn];

void init() {
    vec.clear();
    for (int i = 0; i < maxn; ++i) {
                s[i].clear();
        s[i].insert(i);
    }
};

void add(int a, int b) {
    s[a].insert(b);
    for (int t : s[b]) {
        if (s[a].count(t) == 0) {
            add(a, t);
        }
    }
}

bool calc(string a, string b) {
    int lena = a.size();
    int lenb = b.size();
    bool ok = false;
    if (lena == lenb) {
        ok = true;
        for (int i = 0; i < lena && ok; ++i) {
            if (s[a[i] - 'a'].count(b[i] - 'a') == 0)
                ok = false;
        }
    }
    return ok;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(false);
    int n, m;
    while (cin >> n >> m) {
        init();
        for (int i = 0; i < n; ++i) {
            char a, b;
            cin >> a >> b;
            vec.push_back(make_pair(a, b));
        }
        
        for (int i = 0; i < n; ++i) {
            add(vec[i].first - 'a', vec[i].second - 'a');
        }
        for (int i = n - 1; i >= 0; --i) {
            add(vec[i].first - 'a', vec[i].second - 'a');
        }
        for (int i = 0; i < n; ++i) {
            add(vec[i].first - 'a', vec[i].second - 'a');
        }
        for (int i = n - 1; i >= 0; --i) {
            add(vec[i].first - 'a', vec[i].second - 'a');
        }



        // for (int i = 0; i < 26; ++i) {
        //     cout << char('a' + i) << ":";
        //     for (auto it : s[i])
        //         cout << " " << char('a' + it);
        //     cout << endl;
        // }

        for (int j = 0; j < m; ++j) {
            string a, b;
            cin >> a >> b;
            cout << (calc(a, b) ? "yes" : "no") << endl;
        }
    }
    return 0;
}
