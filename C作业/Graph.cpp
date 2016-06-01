#include <stdio.h>

/*第一部分：邻接矩阵*/

//邻接矩阵
typedef struct {
	char *Vertex;//顶点信息数组,n
	int *Adjacency;//邻接矩阵,n*n
	int n;//顶点数目
	int m;//边数目
}AdjGraph;

//从图中查找顶点值为v的顶点在Vertex数组中的下标,没有找到返回-1;
int FindVertex(AdjGraph *G,char v) {
	for(int i = 0;i < G->n;i++)
		if(G->Vertex[i] == v)
			return i;
	return -1;
}


//向图G中添加一条边
void AddEdge(AdjGraph *G,char v1,char v2) {
	int idx1 = FindVertex(G,v1);
	int idx2 = FindVertex(G,v2);
	if(idx1 >= 0 && idx2 >= 0) {
		int k1 = idx1 * G->n + idx2;//M[idx1][idx2]
		int k2 = idx2 * G->n + idx1;//M[idx2][idx1]
		G->Adjacency[k1] = G->Adjacency[k2] = 1;
		G->m++;
	}
}

void RemoveEdge(AdjGraph *G,char v1,char v2) {
	int idx1 = FindVertex(G,v1);
	int idx2 = FindVertex(G,v2);
	if(idx1 >= 0 && idx2 >= 0) {
		int k1 = idx1 * G->n + idx2;//M[idx1][idx2]
		int k2 = idx2 * G->n + idx1;//M[idx2][idx1]
		G->Adjacency[k1] = G->Adjacency[k2] = 0;
		G->m--;
	}
}

void CreateAdjGraph(AdjGraph *G) {
	//从控制台读入图的信息
	//1。读入顶点信息
	//举例：6 A B C D E F（顶点数n,n个顶点）

	//2.读入边信息
	//举例：
	//3
	//A B
	//B C
	//E F
	scanf("%d",&G->n);
	G->Vertex = (char *)malloc(G->n*sizeof(char));

	for(int i = 0;i < G->n;i++) 
		scanf("\n%c",&G->Vertex[i]);

	int m;
	scanf("%d",&m);

	G->Adjacency = (int *)malloc(G->n * G->n * sizeof(int));

	for(int i = 0;i < G->n * G->n;i++)
		G->Adjacency[i] = 0;
	G->m = 0;

	for(int i = 0;i < m;i++) {
		char v1,v2;
		scanf("\n%c\n%c",&v1,&v2);
		AddEdge(G,v1,v2);
	}
}

//销毁G
void DestroyAdjGraph(AdjGraph *G) {
	free(G->Vertex);//顶点信息数组,n
	free(G->Adjacency);//邻接矩阵,n*n
	G->n=0;//顶点数目
	G->m=0;//边数目
}

//输出顶点信息和邻接矩阵
//举例：
//  A B C D E F
//A 0 1 0 0 0 0
//B 1 0 1 0 0 0
//C 0 1 0 0 0 0
//D 0 0 0 0 0 0
//E 0 0 0 0 0 1
//F 0 0 0 0 1 0
void PrintAdjGraph(AdjGraph *G) {
	printf(" ");
	for(int i = 0;i < G->n;i++)
		printf(" %c",G->Vertex[i]);
	printf("\n");
	for(int i = 0;i < G->n;i++) {
		printf("%c",G->Vertex[i]);
		for(int j = 0;j < G->n;j++) {
			printf(" %d",G->Adjacency[i * G->n + j]);
		}
		printf("\n");
	}

}

/*第二部分：邻接表*/
typedef struct _Neighbor {
	int vidx;
	struct _Neighbor *next;
}Neighbor;

typedef struct _VertexNode {
	char vertex;
	Neighbor *first;
}VertexNode;
typedef struct _AdjList {
	VertexNode *list;
	int n,m;
}AdjList;

int FindAdjListVertex(AdjList *G,char v) {
	for(int i = 0;i < G->n;i++)
		if(G->list[i].vertex == v)
			return i;
	return -1;
}

void AddAdjListEdge(AdjList *G,char v1,char v2) {
	int idx1 = FindAdjListVertex(G,v1);
	int idx2 = FindAdjListVertex(G,v2);
	//在顶点v1的邻接表里加入一个节点
	Neighbor *node1 = (Neighbor *)malloc(sizeof(Neighbor));
	node1->vidx = idx2;
	node1->next = G->list[idx1].first;
	G->list[idx1].first = node1;

	//在顶点v2的邻接表里加入一个节点
	Neighbor *node2 = (Neighbor *)malloc(sizeof(Neighbor));
	node2->vidx = idx1;
	node2->next = G->list[idx2].first;
	G->list[idx2].first = node2;

	G->m++;

}

void RemoveAdjListEdge(AdjList *G,char v1,char v2) {
	int idx1 = FindAdjListVertex(G,v1);
	int idx2 = FindAdjListVertex(G,v2);
	//在顶点v1的邻接表里删除一个节点
	Neighbor * idx = G->list[idx1].first;
	Neighbor * temp = (Neighbor *)malloc(sizeof(Neighbor));
	Neighbor * last = temp;
	while(idx != NULL) {
		if(idx->vidx == v2) {
			last->next = idx->next;
			free(idx);
			break;
		}
		last = idx;
		idx = idx->next;
	}

	//在顶点v2的邻接表里删除一个节点
	idx = G->list[idx2].first;
	last = temp;
	while(idx != NULL) {
		if(idx->vidx == v1) {
			last->next = idx->next;
			free(idx);
			break;
		}
		last = idx;
		idx = idx->next;
	}

	free(temp);
	G->m--;
}

void GreateAdjList(AdjList *G) {
	int n;
	scanf("%d",&n);
	G->list = (VertexNode *)malloc(sizeof(VertexNode)*n);
	for(int i = 0;i < n;i++) {
		char v;
		scanf("\n%c",&v);
		G->list[i].vertex = v;
		G->list[i].first = 0;
	}
	G->n = n;
	//读入边的信息
	int m;
	scanf("%d",&m);
	for(int i = 0;i < m;i++) {
		char v1,v2;
		scanf("\n%c\n%c",&v1,&v2);
		AddAdjListEdge(G,v1,v2);
	}
}
void DestroyAdjList(AdjList *G) {
	for(int i = 0;i < G->n;i++) {
		while(G->list[i].first != NULL)
			RemoveAdjListEdge(G,G->list[i].vertex,G->list[i].first->vidx);
	}
	free(G->list);
	G->n = 0;
}

//输出顶点信息和邻接矩阵
//举例：
//  A B C D E F
//A 0 1 0 0 0 0
//B 1 0 1 0 0 0
//C 0 1 0 0 0 0
//D 0 0 0 0 0 0
//E 0 0 0 0 0 1
//F 0 0 0 0 1 0
bool Linked(AdjList *G, int v1,int v2) {
	Neighbor * idx = G->list[v1].first;
	while(idx != NULL) {
		if(idx->vidx == v2)
			return true;
		idx = idx->next;
	}
	return false;
}


void PrintAdjList(AdjList *G) {
	printf(" ");
	for(int i = 0;i < G->n;i++)
		printf(" %c",G->list[i].vertex);
	printf("\n");
	for(int i = 0;i < G->n;i++) {
		printf("%c",G->list[i].vertex);
		for(int j = 0;j < G->n;j++) {
			printf(" %d",Linked(G,i,j));
		}
		printf("\n");
	}
}

int main() {
	//freopen("in.txt","r",stdin);
	AdjGraph G;
	CreateAdjGraph(&G);
	PrintAdjGraph(&G);

	AdjList G2;
	GreateAdjList(&G2);
	PrintAdjList(&G2);

	return 0;
}