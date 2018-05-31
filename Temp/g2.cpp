#include <cstdio>
#include <cstring>
using namespace std;


//CHELLY
int cnt[5];

char name[25];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n ;
        scanf("%d",&n);
        memset(cnt,0,sizeof(cnt));
        while(n--){
            scanf("%s",name);
            if(name[0]=='C')
                cnt[0]++;
            else if(name[0]=='H')
                cnt[1]++;
            else if(name[0]=='E')
                cnt[2]++;
            else if(name[0]=='L')
                cnt[3]++;
            else if(name[0]=='Y')
                cnt[4]++;
        }
        // printf("c:%d,h:%d,e:%d,l:%d,y:%d\n",cnt[0],cnt[1],cnt[2],cnt[3],cnt[4]);
        printf("%d\n",cnt[0]*cnt[1]*cnt[2]*cnt[4]*cnt[3]*(cnt[3]-1)/2);
    }
    return 0;
}
