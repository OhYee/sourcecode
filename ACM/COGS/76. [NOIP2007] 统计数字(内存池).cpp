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
              node*next;
       };
       node h;
       linked(){
              h.n=0;
              h.cnt=1;
              h.next=NULL;
       }
       void Add(long long num){
              node *it = &h;
              while(it!=NULL){
                     if(it->n==num){
                            it->cnt++;
                            return;
                     }
                     if(it->next==NULL||num < it->next->n)break;
                     it=it->next;
              }
              node * temp=new node;
              temp->n=num;
              temp->cnt=1;
              temp->next=it->next;
              it->next=temp;
       }
       void show(){
              node * it=h.next;
              while(it!=NULL){
                     printf("%lld %d\n", it->n , it->cnt);
                     it=it->next;
              }
       }
};
int main(){
       #if debug
       double time_Start = (double)clock(); //开始时间
       #endif // debug

       freopen("pcount.in","r",stdin);
       #if !debug
       freopen("pcount.out","w",stdout);
       #endif

       scanf("%d",&n);

       linked L;
       REP(n){
              scanf("%d",&m);
              L.Add(m);
       }
       L.show();

       #if debug
       double time_Finish = (double)clock(); //结束时间
       printf("\n operate time: %.2fms \n",time_Finish-time_Start); //输出
       #endif // debug
}

