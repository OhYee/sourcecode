bool G[maxn][maxn];
bool vis[maxn];
int n;

bool HasLoop() {
    //判断是否存在环
    for(int i = 1;i <= n;i++)
        if(!vis[i])
            return false;
    return true;
}

bool IsStart(int k) {
    //判断是否入度为0
    for(int i = 1;i <= n;i++)
        if(G[i][k])
            return false;
    return true;
}


bool TopoSort(int _n,int *ans) {
    //拓扑排序
    /*
    参数:
    邻接矩阵G[][]
    顶点数目n
    用于保存拓扑排序结果的数组 ans[]
    */
    //输出结果下标初始化
    int pos = 0;

    //已访问数组初始化
    memset(vis,false,sizeof(vis));

    //可被选择的数
    priority_queue<int> Q;

    //判断i是否为源
    for(int i = 1;i <= n;i++) {
        if(IsStart(i))
            Q.push(i);
    }

    while(!Q.empty()) {
        int k = Q.top();
        Q.pop();

        if(vis[k])
            continue;
        else
            vis[k] = true;

        //记录到结果中
        ans[pos++] = k;

        for(int i = 1;i <= n;i++) {
            if(G[k][i]) {
                //路径k~i存在
                //删除路径
                G[k][i] = false;
                //如果成为入度为0的点
                if(IsStart(i))
                    Q.push(i);
            }
        }
    }

    //判断是否有环
    return HasLoop();
}
