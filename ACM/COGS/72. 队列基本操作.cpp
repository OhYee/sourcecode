#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

#define REP(n) for(int o=0;o<n;o++)

int n;
int a;
queue<int> Q;
queue<int> Q2;
int main(){
    freopen("queue.in","r",stdin);
    freopen("queue.out","w",stdout);


    cin>>n;
    REP(n){
        cin>>a;
        if(a==1){
            REP(Q.size()){
                Q.pop();
            }
        }else{
            if(a==2){
                cin>>a;
                if(Q.size()>=10){
                    printf("queue out\n");
                }else{
                    Q.push(a);
                }
            }else{
                if(a==3){
                    if(Q.empty()){
                        printf("queue empty\n");
                        //return 0;
                    }else{
                        Q.pop();
                    }
                }else{
                    int s=Q.size();
                    printf("%d\n",s);
                    REP(s){
                        int t=Q.front();
                        Q2.push(t);
                        Q.pop();
                        printf("%d ",t);
                    }
                    REP(s){
                        Q.push(Q2.front());
                        Q2.pop();
                    }
                    printf("\n");
                }
            }
        }
    }
    return 0;
}
