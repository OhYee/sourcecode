#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
#define REP(n) for(int o=0;o<n;o++)
#define Max(a,b) (a)>(b)?(a):(b)
class bigNumber{
    public:
        int num[105];
        bigNumber(){
            init();
        }
        void init(){
            memset(num,0,sizeof(num));
        }
        void read(string s){
            num[0]=s.size();
            REP(num[0]){
                num[o+1]=s[num[0]-o-1]-'0';
            }
        }
        void write(){
            REP(num[0])printf("%d",num[num[0]-o]);
        }
        bigNumber operator + (const bigNumber rhs)const{
            int len=Max(num[0],rhs.num[0]);
            len++;
            bigNumber temp;
            REP(len){
                temp.num[o+1]+=num[o+1]+rhs.num[o+1];
                temp.num[o+2]=temp.num[o+1]/10;
                temp.num[o+1]%=10;
            }
            REP(len){
                if(temp.num[len-o]){
                    temp.num[0]=len-o;
                    break;
                }
            }
            return temp;
        }

};
int main(){
    freopen("add.in","r",stdin);
    freopen("add.out","w",stdout);
    string s;
    bigNumber a,b;
    cin>>s;
    a.read(s);
    cin>>s;
    b.read(s);
    a=a+b;
    a.write();
    return 0;
}
