#include <cstdio>
#include <cstring>
using namespace std;

#define Log(format, ...) //printf(format, ##__VA_ARGS__)

const int maxn = 105;

int nodeNum[maxn];
int nodeIdx[maxn][maxn];
int leaves[maxn];
bool isLeaf[maxn];
int dis[maxn][maxn];

int parents[maxn];
int child[maxn];
int delta[maxn];

int findAndUpdateLastNode(int &lastNode, int &lastNodeIdx, int deep,
                          int nowIdx) {
    // 查找并更新上一层的第一个有孩子的节点
    for (int k = lastNode+1; k < nodeNum[deep - 1]; ++k) {
        if (!isLeaf[nodeIdx[deep - 1][k]]) {
            lastNode = k;
            break;
        }
    }
    lastNodeIdx = nodeIdx[deep - 1][lastNode];

    child[lastNodeIdx] = child[nowIdx];
    delta[lastNodeIdx] = delta[nowIdx] + 1;

    return lastNode;
}

int main() {
    memset(parents, 0, sizeof(parents));
    memset(isLeaf, false, sizeof(isLeaf));
    memset(delta, 0, sizeof(delta));
    memset(parents, 0, sizeof(parents));
    memset(delta, 0, sizeof(delta));

    int N, M, K;
    scanf("%d%d%d", &N, &M, &K);
    for (int i = 0; i < M; ++i)
        scanf("%d", &nodeNum[i]);
    for (int i = 0; i < M; ++i)
        for (int j = 0; j < nodeNum[i]; ++j)
            scanf("%d", &nodeIdx[i][j]);
    for (int i = 0; i < K; ++i) {
        scanf("%d", &leaves[i]);
        isLeaf[leaves[i]] = true;
        child[leaves[i]] = i;
    }
    for (int i = 0; i < K; ++i)
        for (int j = 0; j < K; ++j)
            scanf("%d", &dis[i][j]);

    Log("input ok\n");

    for (int i = M - 1; i > 0; --i) { // 处理第i层
        Log("\tdepth:%d\n", i);
        int lastNode = -1;
        int lastNodeIdx = -1;

        for (int j = 0; j < nodeNum[i]; ++j) { // 处理当前层的第j个节点
            int nowIdx = nodeIdx[i][j];        // 当前节点的编号
            Log("\t\tnowIdx:%d\n", nowIdx);
            if (lastNode == -1) {
                // 处理第一个节点
                findAndUpdateLastNode(lastNode, lastNodeIdx, i, nowIdx);
                parents[nowIdx] = lastNodeIdx;
            } else {
                int preNodeIdx = nodeIdx[i][j - 1];
                Log("\t\t\tpreNodeIdx:%d\n", preNodeIdx);

                int distance = dis[child[nowIdx]][child[preNodeIdx]] -
                               delta[nowIdx] - delta[preNodeIdx];
                Log("\t\t\tdistance:%d dis:%d(%d %d) del:%d %d\n", distance,
                    dis[child[nowIdx]][child[preNodeIdx]], child[nowIdx],
                    child[preNodeIdx], delta[nowIdx], delta[preNodeIdx]);
                if (distance == 2) {
                    parents[nowIdx] = lastNodeIdx;
                } else {
                    findAndUpdateLastNode(lastNode, lastNodeIdx,
                                                     i, nowIdx);
                    parents[nowIdx] = lastNodeIdx;
                }
            }
            Log("\t\t\tlastNode:%d LastNodeIdx:%d\n", lastNode, lastNodeIdx);
        }
    }
    for (int i = 1; i <= N; ++i) {
        printf("%d ", parents[i]);
    }
    printf("\n");
    return 0;
}