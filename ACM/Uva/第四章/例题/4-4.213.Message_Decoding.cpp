#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

class Do{
    private:
        char dict[1000];

        int _2_to_10(int n){//进制转换
            int ans=0;
            int i=0;
            while(n){
                ans+=(n%10)*pow(2,i);
                n/=10;
                i++;
            }
            return ans;
        }
        void decode(int len,int num){//解码
            int n=0;
            for(int i=1;i<len;i++)
                n+=pow(2,i)-1;
            n+=num;
            //printf(" %d(%d)-%c(%d)  ",num,len,dict[n],n);
            printf("%c",dict[n]);
            return;
        }
        int read(int n){//读入数据
            int ans=0;
            for(int i=0;i<n;i++){
                char temp;
                scanf("\n%c\n",&temp);
                ans*=10;
                ans+=temp-'0';
            }
            return _2_to_10(ans);
        }
        int pow(int a,int b){//a的b次方
            if(b==0)return 1;
            int ans=a;
            for(int i=0;i<b-1;i++)
                ans*=a;
            return ans;
        }

    public:
        bool d(){//do
            for(int i=0;;i++){
                if(scanf("%c",&dict[i])==EOF)return false;
                if(dict[i]=='\n')break;
            }
            //if(scanf("%s",dict)==EOF)
            //    return false;
            //printf("Get dict: %s \n ",dict);

            while(1){
                int part=read(3);
                if(part==0)break;
                while(1){
                    int temp=read(part);
                    if(temp==pow(2,part)-1)break;
                    decode(part,temp);
                }
            }
            printf("\n");
            return true;
        }

};


int main(){
    //freopen("in.txt","r",stdin);
    Do d;
    while(d.d());
    return 0;
}