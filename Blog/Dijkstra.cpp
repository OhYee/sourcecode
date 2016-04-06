#include <iostream>
#include <set>
#include <vector>
#include <queue>
using namespace std;


class Dijkstra{
    private:
        const int INF=100000;
        struct Edge{//��
            int to,weight;
        };
        struct Weight{//�������ȶ��еıȽ�
            int weight,n;
            bool operator < (const Weight& rhs)const{
                return weight>rhs.weight;//ȨֵԽ�������ȶ�ԽС
            }
        };

        struct Tree{//��
            vector<vector<Edge> > node;
            vector<int> d;//�������ڵ�����Сֵ
            int N;//�ڵ���Ŀ

            void init(int NodeNumber){//��ʼ��
                node.resize(NodeNumber);
                d.resize(NodeNumber);
                N=NodeNumber;
            }

            void Add(int from,int to,int weight){//���ӱ�
                node[from].push_back((Edge){to,weight});
            }
        };
        Tree T;

    public:
        void Add(int from,int to,int weight){
            T.Add(from,to,weight);
        }
        void init(int NodeNumber){
            T.init(NodeNumber);
        }
        void dijkstra(int v){//Dijkstra���㷨
            vector<int>done;//���ʱ���
            done.resize(T.N);
            for(int i=0;i<T.d.size();i++){
                T.d[i]=INF;
                done[i]=0;
            }
            priority_queue <Weight> Q;//���ȶ���
            Q.push((Weight){0,v});//�ӵ�һ���㿪ʼ
            T.d[v]=0;

            //BFS
            while(!Q.empty()){//ֻҪ���в��վ�����ȥ
                int u=Q.top().n;//�������ȶ����ߵĽڵ�
                Q.pop();
                if(done[u])continue;//�����Ѿ����ʹ�������
                done[u]=1;//���ʱ���
                for(int i=0;i<T.node[u].size();i++){//�ýڵ����Է��ʵĽڵ�
                    Edge& next=T.node[u][i];
                    if(T.d[u]+next.weight<T.d[next.to]){//�����������̣�������
                        T.d[next.to]=T.d[u]+next.weight;
                        Q.push((Weight){next.weight,next.to});
                        //��������������һ��vector��������¼·��
                    }
                }
            }
        }
        int get(int n){//���ص���ָ���ڵ������̾���
            return T.d[n];
        }
};

int main(){
   Dijkstra D;
   D.init(6);
   D.Add(0,1,7);
   D.Add(0,2,9);
   D.Add(0,5,14);
   D.Add(1,0,7);
   D.Add(1,2,10);
   D.Add(1,3,15);
   D.Add(2,0,9);
   D.Add(2,1,10);
   D.Add(2,3,11);
   D.Add(2,5,2);
   D.Add(3,1,15);
   D.Add(3,2,11);
   D.Add(3,4,6);
   D.Add(4,3,6);
   D.Add(4,5,9);
   D.Add(5,0,14);
   D.Add(5,0,14);
   D.Add(5,4,9);
   D.dijkstra(0);

   for(int i=0;i<6;i++){
        cout<<D.get(i)<<endl;
   }

}
