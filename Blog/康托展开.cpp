#include <cstdio>
#include <iostream>
#include <stack>
using namespace std;
#define REP(n) for(int o=0;o<n;o++)
int factorial[]={1,1,2,6,24,120,720,5040,40320};//n!

class linked_list{
private:
    struct link{
        int num;
        link *next;
    };
    link *head;//The address of the first link

public:
    linked_list(){
        head=NULL;
    }
    void Add(int n){//Add node
        link *it;
        if(head==NULL){
            head=new link;
            it=head;
        }else{
            it=head;
            while((it->next)!=NULL){
                it=it->next;
            }
            it->next=new link;
            it=it->next;
        }
        it->num=n;
        it->next=NULL;
        cout<<"add "<<n<<"  ("<<it<<")"<<endl;
    }
    void Del(int n){
        link *it=head;
        if(it->num==n){//if the first node is the target
            head=it->next;
            delete(it);
            cout<<"delete "<<n<<"   ("<<it<<")\n";
            return;
        }
        while(it->next->num!=n){
            it= it->next;
            if(it->next==NULL)return;
        }
        link *temp=it->next;
        it->next=it->next->next;
        delete(temp);
        cout<<"delete "<<n<<"   ("<<temp<<")\n";
    }
    int get(int n){
        link *it=head;
        int cnt=0;
        cout<<"begin ";
        while(it->num!=n){
            cout<<"---->"<<it<<"("<< it->num <<") ";
            it=it->next;
            cnt++;
        }
        cout<<endl;
        return cnt;
    }
    int get2(int n){
        link *it=head;
        cout<<"begin ";
        while(n>1){
            cout<<"---->"<<it<<"("<< it->num <<") ";
            it=it->next;
            n--;
        }
        cout<<"---->"<<it<<"("<< it->num <<") "<<endl;
        return it->num;
    }
};

int KT(int N,int x){
    int ans=1;
    linked_list L;
    stack<int> S;
    while(x){
        S.push(x%10);
        x/=10;
    }
    REP(N){
        L.Add(o+1);
    }
    REP(N){
        int a=L.get(S.top());
        L.Del(S.top());
        S.pop();
        ans+=a*factorial[N-o-1];
    }
    return ans;
}
int KTN(int N,int n){
    int ans=0;
    linked_list L;
    REP(N){
        L.Add(o+1);
    }
    REP(N){
        ans*=10;
        int t=1;
        while(n>factorial[N-o-1]){
            n-=factorial[N-o-1];
            t++;
        }
        int temp=L.get2(t);
        ans+=temp;
        L.Del(temp);
    }
    return ans;
}

int main(){
   cout<<KT(4,2413)<<endl;
   cout<<KTN(4,11);
   printf("11");
   return 0;
}
