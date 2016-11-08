#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <set>
using namespace std;

//对特定类型进行映射
template <typename T>
class f {
private:
    vector<T> v;
    map<T, int> m;
public:
    //输入id，返回该id对应的值
    T id(int n) {
        return v[n];
    }

    //输入值，返回该值对应的id
    int get_id(T t) {
        return m[t];
    }

    //返回是否已存在该值
    bool exist(T t) {
        return m.count(t);
    }

    //插入一个数据，返回id
    int push(T t) {
        if (exist(t))
            return -1;
        v.push_back(t);
        m[t] = v.size() - 1;
        return m[t];
    }
};


class LOVE {
private:
    int m, n;
    static const int maxn = 1000005;
    struct node {
        int r;
        int c;
    };

    f<string> database;
    vector<node> pos[maxn];
    set<int> repeat;

public:
    bool Do() {
        if (cin >> n >> m)
            return false;
        for (int i = 0; i<n; i++) {
            for (int j = 0; j<m; j++) {
                string s;
                cin >> s;
                if (database.exist(s)) {
                    int id = database.get_id(s);
                    pos[id].push_back(node{ i,j });
                    repeat.insert(id);
                } else {
                    int id = database.push(s);
                    pos[id].push_back(node{ i,j });
                }
            }
        }

        f<node> ans;
        cnt = new int[repeat.size()];
        for (size_t i = 0; i<repeat.size(); i++) {
            int id = repeat[i];
            for (size_t j = 0; j<pos[id].size(); j++)
                for (size_t k = i + 1; k<pos[id]; k++)
                    if (pos[id][j].c == pos[id][k].c) {
                        node t = node{ pos[id][j].r,pos[id][k].r };
                        ans.push(t);
                        cnt[ans.get_id(t)]++;
                    }

            for (size_t i = 0; i<repeat.size(); i++) {
                if (cnt[i] >= 2) {
                    ans.get(i)
                }
            }
        }

        return true;
    }
};

int main() {

    return 0;
}