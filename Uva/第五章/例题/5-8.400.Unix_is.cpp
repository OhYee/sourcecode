#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class LOVE{
    private:
        static const int len=65;
        static const int maxn=105;

    public:
        bool Do(){
            int n,Max=0;
            if(!(cin>>n))
                return false;
            cout<<"------------------------------------------------------------\n";
            string str[maxn];
            for(int i=0;i<n;i++){
                cin>>str[i];
                Max=max(Max,(int)str[i].size());
            }
            sort(str,str+n);

            int L,H;
            for(int i=n;i>0;i--){
                L=i;
                H=n/L+(n%L?1:0);
                int size=Max*L+2*(L-1);
                if(size<=60)break;
            }
            //cout<<"\n"<<L<<" "<<H<<"\n";
            for(int i=0;i<H;i++){
                for(int j=0;j<L;j++){
                    cout<<str[i+j*H];
                    for(int k=0;k<(j==L-1?0:2)+Max-(int)str[i+j*H].size();k++)
                        cout<<" ";
                }
                cout<<"\n";
            }
            return true;
        }
};

int main(){
    //freopen("in.txt","r",stdin);
    std::ios::sync_with_stdio(false);
    LOVE LIVE;
    while(LIVE.Do());
    return 0;
}