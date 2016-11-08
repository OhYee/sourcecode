/*
字符串结尾\0
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn=1005;
char DNA[55][maxn];
struct node{
    int i;
    char n;
    bool operator < (const node rhs)const{
        return i<rhs.i || (i==rhs.i && n>rhs.n);
    }
};

void Do();
int Hamming(char s1[],char s2[],int len);

int main(){
    //freopen("in.txt","r",stdin);
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++)
        Do();
    return 0;
}

void Do(){
    int m,n;
    scanf("%d%d",&m,&n);
    int A[maxn],C[maxn],G[maxn],T[maxn];
    memset(A,0,sizeof(A));
    memset(C,0,sizeof(C));
    memset(G,0,sizeof(G));
    memset(T,0,sizeof(T));

    for(int i=0;i<m;i++){
        scanf("%s",DNA[i]);
        for(int j=0;j<n;j++){
            if(DNA[i][j]=='A')A[j]++;
            if(DNA[i][j]=='C')C[j]++;
            if(DNA[i][j]=='G')G[j]++;
            if(DNA[i][j]=='T')T[j]++;
        }
    }
    char DNA_min[maxn];
    for(int i=0;i<maxn;i++)
        DNA_min[i]='\0';
    for(int i=0;i<n;i++){
        node a[4]={{A[i],'A'},{C[i],'C'},{G[i],'G'},{T[i],'T'}};
        sort(a,a+4);
        DNA_min[i]=a[3].n;
    }

    int ans=0;
    for(int i=0;i<m;i++){
        ans+=Hamming(DNA_min,DNA[i],n);
    }
    printf("%s\n%d\n",DNA_min,ans);
    return;
}

int Hamming(char s1[],char s2[],int len){
    int ans=0;
    for(int i=0;i<len;i++)
        if(s1[i]!=s2[i])
            ans++;
    return ans;
}