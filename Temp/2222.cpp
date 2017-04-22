//*/
#define debug
#include <ctime>
//*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <stack>
#include <string>

using namespace std;

const int maxn = 10000 * 50 + 5;
char s[1000000+5];

// AC自动机
struct Node {
    char ch;          //对应的字符
    int failed;       //失败指针
    int parent;       //父节点
    int children[26]; //子结点
    int end;          //单词结尾
    bool vis;         //记录查询时是否已经从此回查过
    Node(char _ch = 0, int _parent = -1) {
        ch = _ch;
        failed = 0;
        parent = _parent;
        memset(children, 0, sizeof(children));
        end = 0;
        vis = false;
    }
};
Node Tree[maxn];
int pos;
void init() { Tree[pos = 0] = Node(); }
void push(char *s) {
    //size_t size = s.size();
    int size = strlen(s);
    int p = 0;
    for (int i = 0; i < size; i++) {
        //判断字符合法性
        int index = s[i] - 'a';
        if (!(index >= 0 && index < 26))
            continue;

        if (!Tree[p].children[index]) {
            Tree[p].children[index] = ++pos; //插入新节点
            Tree[pos] = Node(s[i], p);            //初始化
        }
        p = Tree[p].children[index];
    }
    Tree[p].end++;
}
void make_failed() {
    queue<int> Q;
    while (!Q.empty())
        Q.pop();
    Q.push(0);
    while (!Q.empty()) {
        int t = Q.front();
        Q.pop();
        int iter = Tree[Tree[t].parent].failed;
        do {
            int cousin = Tree[iter].children[Tree[t].ch - 'a'];
            if (cousin && cousin != t) {
                //存在相同的字符并且不是本身
                Tree[t].failed = cousin;
                break;
            } else {
                iter = Tree[Tree[iter].parent].failed;
            }
        } while (iter);

        for (int i = 0; i < 26; i++)
            if (Tree[t].children[i])
                Q.push(Tree[t].children[i]);
    }
}
string show_word(int p) {
    string s = "";
    stack<char> stk;
    while (!stk.empty())
        stk.pop();
    while (p) {
        stk.push(Tree[p].ch);
        p = Tree[p].parent;
    }
    while (!stk.empty()) {
        s += stk.top();
        stk.pop();
    }
    return s;
}
int solve(char *s) {
    int ans = 0;
    //int size = s.size();
    int size = strlen(s);
    int T_iter = 0; //树
    for (int S_iter = 0; S_iter < size; S_iter++) {
        //判断字符合法性
        int index = s[S_iter] - 'a';
        if (!(index >= 0 && index < 26))
            continue;

        while (!Tree[T_iter].children[index] && T_iter)
            T_iter = Tree[T_iter].failed;
        if (Tree[T_iter].children[index])
            T_iter = Tree[T_iter].children[index];
        else
            T_iter = 0;

        //回查
        int temp = T_iter;
        while (temp && !Tree[temp].vis) {
            Tree[temp].vis = true;
            if (Tree[temp].end) {
                //cout << show_word(temp) << "(" << Tree[temp].end << ")" << endl;
                //单词结束
                ans += Tree[temp].end;
                Tree[temp].end = 0; //删除单词
            }
            temp = Tree[temp].failed;
        }
    }
    return ans;
}

int main() {
#ifdef debug
    freopen("in.txt", "r", stdin);
    int START = clock();
#endif
    //cin.tie(0);
    //cin.sync_with_stdio(false);

    int T;
    //cin >> T;
    scanf("%d",&T);
    while (T--) {
        init();
        int n;
        //cin >> n;
        scanf("%d",&n);
        //string s;
        for (int i = 0; i < n; i++) {
            scanf("%s",s);
            push(s);
        }
        make_failed();

        // show
        // for (int i = 0; i <= pos; i++) {
        //     cout << i << "(" << Tree[i].ch << ")" << endl;
        //     cout << "parent: " << Tree[i].parent << "("
        //          << Tree[Tree[i].parent].ch << ")" << endl;
        //     cout << "failed: " << Tree[i].failed << "("
        //          << Tree[Tree[i].failed].ch << ")" << endl;
        //     cout << "children: ";
        //     for (int j = 0; j < 26; j++) {
        //         if (Tree[i].children[j])
        //             cout << Tree[i].children[j] << "("
        //                  << Tree[Tree[i].children[j]].ch << ")"
        //                  << " ";
        //     }
        //     cout << endl << endl << endl;
        // }

        scanf("%s",s);
        printf("%d\n",solve(s));// << solve(s) << endl;
    }

#ifdef debug
    printf("Time:%.3fs.\n", double(clock() - START) / CLOCKS_PER_SEC);
#endif
    return 0;
}
