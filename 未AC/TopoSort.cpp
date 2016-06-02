class TopoSort{
	private:
		bool *vis;
		bool *G;
		int n;
		
		bool HasLoop() {
		//判断是否存在环
			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++)
					if(G[i][j])
						return false;
			return true;
		}

		bool IsStart(int k){
		//判断是否入度为0
			for(int i=0;i<n;i++)
				if(G[i][k])
					return false;
			return true;
		}
		
	public:
	
	bool Sort(bool *_G,int _n,int *ans) {
	//拓扑排序
	/*
		参数:
			邻接矩阵G[][]
			顶点数目n
			用于保存拓扑排序结果的数组 ans[]
	*/
		//初始化
		G = new bool [n *  n];
		memcpy(G,_G,sizeof(_G));
		n = _n;
		
		//输出结果下标初始化
        int pos = 0;
		
		//已访问数组初始化
		if(vis != NULL)
			delete vis;
		*vis = new bool [n];
		memset(vis,false,sizeof(vis));
		
		//可被选择的数
		priotry_queue<int> Q;
		
		//判断i是否为源
		for(int i=0;i<n;i++) {
			if(IsStart(i))
				Q.push(i);
		}
		
		while(!Q.empty()) {
			int k = Q.top();
			Q.pop();
			
			if(vis[k])
				continue;
			else
				vis[k]=true;
				
			//记录到结果中
			ans[++pos] = k;
			
			for(int i=0;i<n;i++) {
				if(G[k][i]){
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
};

