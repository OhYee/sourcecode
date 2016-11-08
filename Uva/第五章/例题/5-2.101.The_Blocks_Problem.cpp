#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

struct blocks{
    int n;
    blocks *up;
    blocks *down;
};

int n;
blocks *b[30],*p[30];

void back(int n){
    if(b[n]->up!=NULL)
        back(b[n]->up->n);
    if(b[n]->down!=NULL)
        b[n]->down->up=NULL;
    b[n]->up=b[n]->down=NULL;
    p[n]=b[n];
}

void pr(){
    printf("=====================\n");
    for(int i=0;i<n;i++){
        printf("%d:",i);
        blocks *temp=p[i];
        while(temp!=NULL){
            printf(" %d",temp->n);
            temp=temp->up;
        }
        printf("\n");
    }

    printf("\n");
    for(int i=0;i<n;i++){
        printf("%d: %d %d %d\n",i,b[i]->down==NULL?-1:b[i]->down->n,i,b[i]->up==NULL?-1:b[i]->up->n);
    }
    
    printf("=====================\n");
    return;
}

int main(){
    //freopen("in.txt","r",stdin);
    //======init======
    for(int i=0;i<30;i++)
        p[i]=b[i]=new blocks{i,NULL,NULL};
    //================

    scanf("%d",&n);
    
    char com1[5],com2[5];
    int A,B;

    while(1){
        scanf("%s %d %s %d",com1,&A,com2,&B);
        if(!strcmp(com1,"quit"))break;

        //pr();

        //printf("%s %d %s %d\n",com1,A,com2,B);
        if(A==B)continue;
        bool can=true;
        blocks *t=b[A];
        while(t!=NULL){
            t=t->up;
            if(t==b[B])
                can=false;
        }
        t=b[A];
        while(t!=NULL){
            t=t->down;
            if(t==b[B])
                can=false;
        }
        if(!can)continue;

        if(!(strcmp(com1,"move")||strcmp(com2,"onto"))){    
            back(A);
            if(b[B]->up!=NULL)
                back(b[B]->up->n);
            b[B]->up=b[A];
            b[A]->down=b[B];
            if(p[A]==b[A])
                p[A]=NULL;
        }
        if(!(strcmp(com1,"move")||strcmp(com2,"over"))){
            back(A);
            blocks *temp=b[B];
            while(temp->up!=NULL)
                temp=temp->up;
            temp->up=b[A];
            b[A]->down=temp;
            if(p[A]==b[A])
                p[A]=NULL;
        }
        if(!(strcmp(com1,"pile")||strcmp(com2,"onto"))){
            if(b[B]->up!=NULL)
                back(b[B]->up->n);
            b[B]->up=b[A];
            if(b[A]->down!=NULL)
                b[A]->down->up=NULL;
            b[A]->down=b[B];
            if(p[A]==b[A])
                p[A]=NULL;
        }
        if(!(strcmp(com1,"pile")||strcmp(com2,"over"))){
            blocks *temp=b[B];
            while(temp->up!=NULL)
                temp=temp->up;
            temp->up=b[A];
            if(b[A]->down!=NULL)
                b[A]->down->up=NULL;
            b[A]->down=temp;
            if(p[A]==b[A])
                p[A]=NULL;
        }
    }

    for(int i=0;i<n;i++){
        printf("%d:",i);
        blocks *temp=p[i];
        while(temp!=NULL){
            printf(" %d",temp->n);
            temp=temp->up;
        }
        printf("\n");
    }
    return 0;
}