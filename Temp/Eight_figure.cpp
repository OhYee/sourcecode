#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
using namespace std;

const int delta[] = {0, 0, 1, -1}; // BFS拓展规则
const int fac[] = {1,   1,   2,    6,     24,
                   120, 720, 5040, 40320, 362880}; //阶乘表(用于康托展开)

// Hash函数 康托展开和康托逆展开
//康托展开 将序列映射到整数
int cantor(int s, int k) {
    int a[9];
    for (int i = 8; i >= 0; i--, s /= 10)
        a[i] = s % 10;
    int i, j, tmp, num = 0;
    for (i = 0; i < k; i++) {
        tmp = 0;
        for (j = i + 1; j < k; j++)
            if (a[j] < a[i])
                tmp++;
        num += fac[k - i - 1] * tmp;
    }
    return num;
}
//逆康托展开 将整数映射回序列
int uncantor(int x, int k) {
    int res[9];
    int i, j, l, t;
    bool h[9] = {0};
    for (i = 1; i <= k; i++) {
        t = x / fac[k - i];
        x -= t * fac[k - i];
        for (j = 1, l = 0; l <= t; j++)
            if (!h[j])
                l++;
        j--;
        h[j] = true;
        res[i - 1] = j;
    }

    int ans = 0;
    for (int i = 0; i < 9; i++)
        ans = ans * 10 + res[i];
    return ans;
}
//哈希函数(一对一映射)
inline int Hash(int State) { return cantor(State, 9); }
//逆哈希函数
inline int unHash(int hash) { return uncantor(hash, 9); }
//绝对值
inline int abs(int a) { return a >= 0 ? a : -a; }
//将3×3的数组映射成整数形式
int ToInt(int a[3][3]) {
    int num = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            num = num * 10 + a[i][j];
    return num;
}
//绘制整数对应的图形
void Draw(int state) {
    printf("%d %d %d\n%d %d %d\n%d %d %d\n\n", state / 100000000 % 10,
           state / 10000000 % 10, state / 1000000 % 10, state / 100000 % 10,
           state / 10000 % 10, state / 1000 % 10, state / 100 % 10,
           state / 10 % 10, state / 1 % 10);
}

//由于 八数码 写成整数只有 9 位,在整数表达范围内,因此采用整数来记录状态
int s; //初始状态
int v; //结束状态

// A*算法 f(n)=g(n)+h(n)
// 到终点的估价函数 h(n)
int h(int State) {
    int pos[10];

    int t = v;
    int p = 0;
    while (t) {
        pos[t % 10] = p++;
        t /= 10;
    }

    t = State;
    int sum = 0;
    while (t) {
        sum += abs(pos[t % 10] - p) % 3 + abs(pos[t % 10] - p) / 3;
        p++;
        t /= 10;
    }

    return sum;
}

//搜索树上的节点,可以看成一个状态
struct Node {
    int state; //状态
    int hash;  // Hash值
    int f;     //总过程的估价 用于在OPEN表排序
    int g;     //到当前状态的花费
    int pre;   //记录该节点的前一个节点状态

    Node(int State, int G, int Pre) {
        state = State;
        pre = Pre;
        hash = Hash(State);
        g = G;
        f = G + h(State);
    }

    //在OPEN表里以f大小为顺序
    bool operator<(const Node &rhs) const { return f > rhs.f; }
};
priority_queue<Node> OPEN; //待遍历节点
bool CLOSED[362885];       //已遍历节点
int Last[362885];          //记录该节点的上一个节点

//初始化
void init() {
    while (!OPEN.empty()) //清空OPEN表
        OPEN.pop();
    memset(CLOSED, false, sizeof(CLOSED)); //清空CLOSED表
}

int Eight_figure() {
    init();

    //将起点放置到 OPEN 表
    OPEN.push(Node(s, 0, -1));
    int ans = -1;

    while (!OPEN.empty()) {
        int t = OPEN.top().state;
        int g = OPEN.top().g;
        int hash = OPEN.top().hash;
        int pre = OPEN.top().pre;
        OPEN.pop();
        // printf("STATE: %d HASH:%d\n",t,hash);

        //如果已经访问过该节点
        if (CLOSED[hash])
            continue;
        CLOSED[hash] = true;

        //记录路径
        Last[hash] = pre;
        // printf("Last[%d(STATE:%d)] = %d(STATE:%d)\n",hash,t,pre,unHash(pre));

        //到达目标态
        if (t == v) {
            ans = g;
            break;
        }

        //查找 空格 的位置
        int tx, ty;
        int MAP[3][3];
        for (int i = 2; i >= 0; i--)
            for (int j = 2; j >= 0; j--) {
                MAP[i][j] = t % 10;
                t /= 10;
                if (MAP[i][j] == 9) {
                    tx = i;
                    ty = j;
                }
            }
        
        //拓展节点
        for (int i = 0; i < 4; i++) {
            int xx = tx + delta[i];
            int yy = ty + delta[3 - i];

            if (xx >= 0 && xx <= 2 && yy >= 0 && yy <= 2) {
                //如果可以交换
                swap(MAP[tx][ty], MAP[xx][yy]); //交换
                int tt = ToInt(MAP);
                // printf("    STATE: %d HASH: %d\n",tt,Hash(tt));
                if (!CLOSED[Hash(tt)])
                    OPEN.push(Node(tt, g + 1, hash)); //插入到 OPEN 表里
                swap(MAP[tx][ty], MAP[xx][yy]); //交换回去为下次交换做准备
            }
        }
    }
    return ans;
}

int main() {
    //freopen("in.txt", "r", stdin);
    s = 0, v = 0;
    int t;
    printf("Use 9 to instead of the space.\nSuch as\n1 2 3\n4 5 6\n7 8 "
           "9\nmeans\n1 2 3\n4 5 6\n7 8 S\n\n");
    printf("=========\n");

    printf("Input the begin state:\n");
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) {
            scanf("%d", &t);
            s = s * 10 + t;
        }
    printf("Input the end state:\n");
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) {
            scanf("%d", &t);
            v = v * 10 + t;
        }

    int ans = Eight_figure();
    printf("=========\n");
    printf("The min steps is %d.\n\n", ans);

    //路径
    printf("Path: \n");
    stack<int> sta;
    t = Hash(v);

    while (!sta.empty())
        sta.pop();
    while (t != -1) {
        sta.push(unHash(t));
        t = Last[t];
    }
    while (!sta.empty()) {
        Draw(sta.top());
        sta.pop();
    }

    return 0;
}