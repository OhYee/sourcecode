#include <cstdio>
#include <cstring>
using namespace std;

//#define Debug

int kase=0;
bool Do();

int main(){
    //freopen("in.txt","r",stdin);
    while(Do());
    return 0;
}

bool Do(){
    
    int r,c;
    char map[15][15];
    int number[15][15];
    int n=1;
    memset(number,0,sizeof(number));

    //INPUT
    scanf("%d",&r);
    if(r==0)return false;
    scanf("%d",&c);

    for(int i=0;i<r;i++)
        scanf("%s",map[i]);
    getchar();//\n
    //INPUT FINISHED

    //MARK
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            if(map[i][j]!='*'&&(i==0||j==0||map[i-1][j]=='*'||map[i][j-1]=='*'))number[i][j]=n++;
    

    #ifdef Debug
        printf("##########DEBUG##########\n");
        printf("%d %d\n",r,c);
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                printf("%c",map[i][j]);
            }
            printf("\n");
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                printf("%3d",number[i][j]);
            }
            printf("\n");
        }
        printf("##########DEBUG##########\n");
    #endif

    if(kase!=0)printf("\n");
    printf("puzzle #%d:\n",++kase);
    bool mark[15][15];

    printf("Across\n");
    memset(mark,false,sizeof(mark));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(number[i][j] && !mark[i][j]){
                printf("%3d.",number[i][j]);
                for(int k=j;k<c&&map[i][k]!='*';k++){
                    printf("%c",map[i][k]);
                    mark[i][k]=true;
                }
                printf("\n");
            }
        }
    }

    printf("Down\n");
    memset(mark,false,sizeof(mark));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(number[i][j] && !mark[i][j]){
                printf("%3d.",number[i][j]);
                for(int k=i;k<r&&map[k][j]!='*';k++){
                    printf("%c",map[k][j]);
                    mark[k][j]=true;
                }
                printf("\n");
            }
        }
    }


    return true;
}