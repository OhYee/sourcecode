#include <cstdio>
#include <string.h>
#include <vector>
#include <iostream>
#include <queue>
#include <map>

using namespace std;

#define debug 0
#define REP(n) for(int o=0;o<n;o++)
#define REP1(m,n) for(int o1=0;o1<m;o1++)for(int o2=0;o2<n;o2++)
#define Min(a,b) ((a)<(b))?(a):(b)
#define Max(a,b) ((a)>(b))?(a):(b)
#define swap(a,b) {int Temp=a;a=b;b=Temp;}
#define abs(a) ((a>0)?a:(-a))
/*
#############################################################
*/
const int maxn=305;
int Map[maxn][maxn];
//int C[maxn][maxn];
int M,N;
int Q;


class C1{
    private:
    map<int,int> m;//ӳ��Ȩֵ
    map<int,int>::iterator it;//������
    struct C2{
        int c[maxn][maxn];
    };
    vector<C2> c;

    public:
    bool Had(int n){
        it=m.find(n);
        return !(it==m.end());
    }
    int Search(int n){
        it=m.find(n);
        return it->second;
    }
    void Add(int x,int y,int n){
        if(!Had(n)){
            C2 t;
            c.push_back(t);
            m.insert(pair<int,int>(n,c.size()-1));
            //REP1(N,M)c[c.size()-1].c[o1][o2]=0;

            #if debug
            printf("�¼�¼%d��(%d,%d)\n",n,x,y);
            #endif
        }
        c[Search(n)].c[x][y]++;
        #if debug
        printf("%d��(%d,%d)��Ȩֵ��Ϊ%d\n",n,x,y,c[Search(n)].c[x][y]);
        #endif // debug
    }
    void change(int x,int y,int n){
        int temp=Map[x][y];
        #if debug
        printf("����(%d,%d)(%d)��ȨֵΪ%d\n",x,y,temp,n);
        #endif
        c[Search(temp)].c[x][y]--;
        Add(x,y,n);
    }
    int get(int x,int y,int n){
        if(!Had(n))return 0;
        return c[Search(n)].c[x][y];
    }
};
C1 C;


int lowbit(int x){
    return x&(-x);
}

int work(int x,int y,int n){//��״���� �������η���(1,1)(x,y)��ָ�����͵ĸ�����
    if (!C.Had(n))return 0;
    int sum=0;
    #if debug
    cout<<"     work"<<endl;
    #endif // debug
    for(int i=x;i>0;i-=lowbit(i)){
        for(int j=y;j>0;j-=lowbit(j)){
            #if debug
            cout<<"     sum("<<sum<<")+= C["<<i<<"]["<<j<<"]  ["<<n<<"]("<<C.get(i,j,n)<<")="<<sum+C.get(i,j,n)<<endl;
            #endif // debug

                sum+=C.get(i,j,n);
            }
        }
    return sum;
}


void add(int x,int y,int n){
    Map[x][y]=n;
    for(int p=x;p<=N;p+=lowbit(p)){
        for(int q=y;q<=M;q+=lowbit(q)){
            C.Add(p,q,n);
        }
    }
}


void change(int x,int y,int n){
    for(int p=x;p<=N;p+=lowbit(p)){
        for(int q=y;q<=M;q+=lowbit(q)){
            C.change(p,q,n);
        }
    }
    Map[x][y]=n;

}



int main(){
    freopen("luvletter.in","r",stdin);
    #if !debug
    freopen("luvletter.out","w",stdout);
    #endif // debug

    cin>>M>>N;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            int temp;
            cin>>temp;
            add(i,j,temp);

        }
    }


    #if debug
    cout<<"��ͼ��������"<<endl;
    cout<<"#######################"<<endl;
    REP(M+1)printf("%5d",o);
    cout<<endl<<endl;
    for(int i=1;i<=N;i++){
        printf("%5d  ",i);
        for(int j=1;j<=M;j++){
            //cout<<" "<<Map[i][j]<<" ";
            printf("%5d",Map[i][j]);
        }
        cout<<endl;
    }
    cout<<"#######################"<<endl;
    #endif // debug

    cin>>Q;
    REP(Q){
        int mode;
        cin>>mode;
        if(mode==1){
            int x,y,c;
            cin>>x>>y>>c;
            change(x,y,c);
            /*#if debug
            cout<<"��ͼ��������"<<endl;
            cout<<"#######################"<<endl;
            for(int p=1;p<=N;p++){
                for(int q=1;q<=M;q++){
                    cout<<" "<<C[p][q][2]<<" ";
                }
                cout<<endl;
            }
            cout<<"#######################"<<endl;
            #endif // debug*/
        }else{

            int x1,x2,y1,y2,c;
            cin>>x1>>x2>>y1>>y2>>c;
            //int sum=0;
            int xa=Min(x1,x2);
            int xb=Max(x1,x2);
            int ya=Min(y1,y2);
            int yb=Max(y1,y2);
            xa--;
            ya--;
            /*change(x,y,n);
            for(int p=xa;p<=xb;p++){
                for(int q=ya;q<=yb;q++){
                    if(Map[p][q]==c)sum+=1;
                }
            }*/


            int t=work(xb,yb,c)+work(xa,ya,c)-work(xa,yb,c)-work(xb,ya,c);
            //t=(t<0?0:t);
            cout<<t<<endl;
        }
    }


    return 0;
}
