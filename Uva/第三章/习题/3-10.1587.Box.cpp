#include <cstdio>
#include <algorithm>
using namespace std;

#define REP(n) for(int o=0;o<n;o++)

bool Do();

int main(){
    //freopen("in.txt","r",stdin);
    while(Do());
    return 0;
}

bool Do(){
    int a[13];
    if(scanf("%d",&a[1])==EOF)
        return false;
    REP(11)
        scanf("%d",&a[o+2]);
    REP(6)
        sort(&a[1+o*2],&a[3+o*2]);

    bool can=true;

    for(int i=0;i<6;i++){
        int cnt=0;
        for(int j=0;j<6;j++){
            if(a[1+i*2]==a[1+j*2]&&a[2+i*2]==a[2+j*2])
                cnt++;
        }
        if(cnt<2){
            can=false;
            break;
        }
    }

    if(can){
        sort(a+1,a+13);
        REP(3)
            if(!(a[1+o*4]==a[2+o*4]&&a[2+o*4]==a[3+o*4]&&a[3+o*4]==a[4+o*4]))
                can=false;
    }
    printf("%s\n",can?"POSSIBLE":"IMPOSSIBLE");
    return true;
}