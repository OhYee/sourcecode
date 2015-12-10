#include <cstdio>
#include <memory>
#include <cstring>
using namespace std;
#define REP(n) for(int o=0;o<n;o++)
#define Min(a,b) ((a)<(b))?(a):(b)
#define Max(a,b) ((a)>(b))?(a):(b)
class bigNumber{
    private:
    int num[1001];

    public:
    bigNumber(){
        init();
    }
    void init(){
        memset(num,0,sizeof(num));
    }
    bigNumber operator = (const bigNumber& rhs){
        init();
        REP(rhs.num[0]+1)num[o]=rhs.num[o];
        return *this;
    }
    bigNumber operator = (long long rhs){
        init();
        int i=1;
        while(rhs){
            num[i]=rhs%10;
            rhs/=10;
            i++;
        }
        num[0]=i-1;
        return *this;
    }
    bool operator < (const bigNumber rhs)const{
        if(num[0]!=rhs.num[0])return (num[0]<rhs.num[0]);
        REP(num[0]){
            int temp=num[0]-o;
            if(num[temp]!=rhs.num[temp])return (num[temp]<rhs.num[temp]);
        }
        return 0;
    }
    bool operator > (const bigNumber rhs)const{
        if(num[0]!=rhs.num[0])return (num[0]>rhs.num[0]);
        REP(num[0]){
            int temp=num[0]-o;
            if(num[temp]!=rhs.num[temp])return (num[temp]>rhs.num[temp]);
        }
        return 0;
    }
    bool operator == (const bigNumber rhs)const{
        return !(*this>rhs||*this<rhs);
    }
    bool operator <= (const bigNumber rhs)const{
        return *this<rhs||*this ==rhs;
    }
    bigNumber operator + (const bigNumber rhs)const{
        bigNumber temp;
        int len;
        len=num[0]>rhs.num[0]?num[0]:rhs.num[0];
        len++;
        REP(len){
            temp.num[o+1]+=num[o+1]+rhs.num[o+1];
            temp.num[o+2]+=temp.num[o+1]/10;
            temp.num[o+1]%=10;
        }
        REP(len){
            if(temp.num[len-o]!=0){
                temp.num[0]=len-o;
                break;
            }
        }
        return temp;
    }
    bigNumber operator + (const long long rhs)const{
        bigNumber temp1,temp2;
        temp1=*this;
        temp2=rhs;
        return temp1 + temp2;
    }
    bigNumber operator * (const bigNumber rhs)const{
        bigNumber temp;
        int len;
        len=num[0]+rhs.num[0];
        //len++;
        for(int i=1;i<=num[0];i++){
            for(int j=1;j<=rhs.num[0];j++){
                temp.num[i+j-1]+=num[i]*rhs.num[j];
                temp.num[i+j]+=temp.num[i+j-1]/10;
                temp.num[i+j-1]%=10;
            }
        }
        REP(len){
            if(temp.num[len-o]!=0){
                temp.num[0]=len-o;
                break;
            }
        }
        return temp;
    }
    bigNumber operator * (const long long rhs)const{
        bigNumber temp1,temp2;
        temp1=*this;
        temp2=rhs;
        return temp1 * temp2;
    }
    bigNumber operator - (const bigNumber rhs)const{
        bigNumber temp,a,b;
        temp=Max(*this,rhs);
        b=Min(*this,rhs);
        a=temp;
        temp=0;
        int len=a.num[0];
        REP(len){
            temp.num[o+1]+=10+a.num[o+1]-b.num[o+1];
            temp.num[o+2]--;
            temp.num[o+2]+=temp.num[o+1]/10;
            temp.num[o+1]%=10;
        }
        REP(len){
            if(temp.num[len-o]!=0){
                temp.num[0]=len-o;
                break;
            }
        }
        return temp;
    }
    bigNumber operator - (const long long rhs)const{
        bigNumber temp1,temp2;
        temp1=*this;
        temp2=rhs;
        return temp1 - temp2;
    }
    bigNumber operator / (const bigNumber rhs)const{
        bigNumber a;
        int it=num[0];

        bigNumber d;
        bigNumber c;

        while(it>0){
            a=(d*10)+num[it];
            c=c*10;

            int t;
            REP(9){
                if(a < rhs * (o+1)){
                    t=o;
                    break;
                }
                t=9;
            }
            c=c+t;
            d=a-rhs*t;
            it--;
        }
        return c;
    }
    bigNumber operator / (const long long rhs)const{
        bigNumber temp1,temp2;
        temp1=*this;
        temp2=rhs;
        return temp1 / temp2;
    }
    bigNumber operator % (const bigNumber rhs)const{
        bigNumber a;
        int it=num[0];

        bigNumber d;
        bigNumber c;



        while(it>0){

            a=(d*10)+num[it];
            c=c*10;

            int t;
            REP(9){
                if(a < rhs * (o+1)){
                    t=o;
                    break;
                }
                t=9;
            }
            c=c+t;
            d=a-rhs*t;
            it--;
        }
        return d;
    }
    bigNumber operator % (const long long rhs)const{
        bigNumber temp1,temp2;
        temp1=*this;
        temp2=rhs;
        return temp1 % temp2;
    }
    void p(){
        REP(num[0]){
            printf("%d",num[num[0]-o]);
        }
    }
};
int main(){
    bigNumber a,b;
    a=9;
    b=9;
    a.p();
    b.p();
    a=a+b;
    printf("\n");
    a.p();
    printf("\n");
    a=5135;b=139;
    a=a*b;
    a.p();
    printf("\n");
    a=9;b=7;
    a=a-b;
    a.p();
    printf("\n");
    a=12;b=7;
    a=a-b;
    a.p();
    printf("\n");
    a=11311;b=12;
    a=a/b;
    a.p();
    printf("\n");
    a=11311;b=12;
    a=a%b;
    a.p();
    printf("\n");
    return 0;
}
