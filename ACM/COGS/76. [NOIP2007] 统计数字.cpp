#include<cstdio>
#include <ctime>
#define debug 1
#define REP(n) for(int o=0;o<n;o++)
int n;
//unsigned long long a[200005];
long long m;
class linked{
       public:
       struct node{
              long long n;
              int cnt;
              int next;
       };
       //node *N=new node[5000];
       node N[100005];

       int it;
       linked(){
              it=0;
              REP(5000)N[o].next=-1;
              N[0].next=1;
       }
       void Add(long long num){
              int ita=0;
              while(ita!=-1){
                     if(N[ita].n==num){
                            N[ita].cnt++;
                            return;
                     }
                     if(N[ita].next==-1||num < N[N[ita].next].n)break;
                     ita=N[ita].next;
              }
              N[it].n=num;
              N[it].cnt=1;
              N[it].next=N[ita].next;
              N[ita].next=it;
              it++;
       }
       void show(){/*
              int ita=1;
              while(ita!=-1){
                     printf("%lld %d\n", N[ita].n , N[ita].cnt);
                     ita=N[ita].next;

              }*/
              for(int ita=1;ita!=-1;ita=N[ita].next)printf("%lld %d\n", N[ita].n , N[ita].cnt);
       }
};
int main(){
       #if debug
       double time_Start = (double)clock(); //开始时间
       double time_Finish;
       #endif // debug

       freopen("pcount.in","r",stdin);
       #if debug
       freopen("pcount.out","w",stdout);
       #endif

       scanf("%d",&n);

       time_Finish = (double)clock(); //结束时间
       printf("\n read n finished    operate time: %.2fms \n",time_Finish-time_Start); //输出

       linked L;

       REP(n){
              scanf("%d",&m);
              L.Add(m);
       }

              time_Finish = (double)clock(); //结束时间
       printf("\n read m finished    operate time: %.2fms \n",time_Finish-time_Start); //输出

       L.show();

       #if debug
       time_Finish = (double)clock(); //结束时间
       printf("\n operate time: %.2fms \n",time_Finish-time_Start); //输出
       #endif // debug
}

