#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <iostream>
using namespace std;

//Kruscal
//ufs中，要及时更新f[x]
class Kruscal{
	private:
		int ufs(int x,int f[]){
			return f[x]==x?x:f[x]=ufs(f[x],f);
		}
	public:
		struct Edge{
			int u,v,w;
			bool operator < (const Edge rhs)const{
				return w < rhs.w;
			}
		};
		int kruscal(Edge e[],int size){
			int ans=0;
			int f[size];
			for(int i=0;i<size;i++)f[i]=i;
			sort(e,e+size);
			for(int i=0;i<size-1;i++){
				int x=ufs(e[i].u,f),y=ufs(e[i].v,f);
				if(x!=y){
					f[x]=y;
					ans+=e[i].w;
				}
			}
			return ans;
		}
};

//Prim
//注意无向图的u和v可以互换
class Prim{
	public:
		struct Edge{
			int u,v,w;
			bool operator < (const Edge rhs)const{
				return w > rhs.w;
		    }
		};
		int prim(Edge e[],int size){
			int ans=0;
			bool S[size];
			memset(S,false,sizeof(S));
			priority_queue<Edge> Q;
			S[1]=true;


			for(int i=0;i<size-1;i++){
				for(int o=0;o<size;o++)
					if((S[e[o].u]==true&&S[e[o].v]==false)||(S[e[o].u]==false&&S[e[o].v]==true))
						Q.push(e[o]);
				while(!Q.empty()){
					if(S[Q.top().u]==true&&S[Q.top().v]==true){
						Q.pop();
						continue;
					}else{
						ans+=Q.top().w;
						S[Q.top().u]=true;
						S[Q.top().v]=true;
						Q.pop();
						break;
					}
				}
			}
			return ans;
		}
};


int main(){
	//freopen("in.txt","r",stdin);
	/*
	1 2 2
	1 3 12
	1 4 10
	2 3 8
	2 5 9
	3 4 6
	3 5 3
	4 5 7
	*/
	Kruscal a;
	Kruscal::Edge e1[8];
	Prim b;
	Prim::Edge e2[8];
	for(int o=0;o<8;o++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		e1[o].u=u;
		e1[o].v=v;
		e1[o].w=w;
		e2[o].u=u;
		e2[o].v=v;
		e2[o].w=w;
	}

	printf("%d\n",a.kruscal(e1,8));
	printf("%d\n",b.prim(e2,8));

	return 0;
}