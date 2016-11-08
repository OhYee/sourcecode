/*
    By:OhYee
    Email:oyohyee@oyohyee.com
    GitHub:OhYee 
    Page:www.oyohyee.com
*/
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>


#define REP(n)for(o=0;o<n;o++)


const int maxn=10;
const int name_maxn=50;
const int author_maxn=20;

struct DATE{
    int year;
    int month;
    int day;
};

struct BOOK{
    char name[name_maxn];
    int code;
    int price;
    char author[author_maxn];
    int pages;
    int ISBN;    
    DATE date; 

};

struct MUG{
    int code;
    int price;
    char color[author_maxn];
    int size;
};

struct LAMP{
    int code;
    int price;
    char color[author_maxn];
    int size;
    int luminance;
};

union TYPE{
    BOOK b;
    MUG m;
    LAMP l;
};

struct NODE{
    int price;
    int it;
};


void init();
void info_output_all();
void info_change();
void info_delete();
void info_find();
void info_insert();
void info_sort_by_price();
void exit_save();
void read_line(FILE *f,TYPE* book);
TYPE * new_book(TYPE b);
void p(TYPE b);
int confirm();
int search();
void SortByRecursion(NODE *array,int n);
void swap_int(int *a,int *b);
void swap_it(TYPE *a,TYPE *b);


int o;
TYPE *it[maxn];


int main(){
    init();
    while(1){
        system("cls");

        int n;
        printf("================================\n");
        printf("   The Supermarket System\n");
        printf("================================\n");
        printf("The number of the funcation:\n");
        printf("0.Show all infomation\n");
        printf("1.Change the information\n");
        printf("2.Delete the information\n");
        printf("3.Search the information\n");
        printf("4.Insert the information\n");
        printf("5.Sort the information\n");
        printf("6.Exit the system\n");
        printf("===================================\n");
        printf("What do you want to do:");
        scanf("%d",&n);
        printf("===================================\n");

        switch (n){
            case 0:{
                printf("Show all information.\n");
                info_output_all();
                break;
            }
            case 1:{
                printf("Change the information.\n");
                info_change();
                break;
            }
            case 2:{
                printf("Delete the information.\n");
                info_delete();
                break;
            }
            case 3:{
                printf("Search the information.\n");
                info_find();
                break;
            }
            case 4:{
                printf("Insert the information.\n");
                info_insert();
                break;
            }
            case 5:{
                printf("Sort the information.\n");
                info_sort_by_price();
                break;
            }
            case 6:{
                printf("Save and exit.\n");
                exit_save();
                system("pause");
                return 0;
            }

        }

        system("pause");
    }
    return 0;
}


void init(){
    REP(maxn){
        it[o]=NULL;
    }

    FILE *f;
    f=fopen("goods_info.txt","r");
    int i=0,last_code=-1;
    while(1){
        TYPE book;
        fscanf(f,"%d\t",&book.code);
        if(book.code==last_code)break;
        last_code=book.code;
        read_line(f,&book);
        it[i]=new_book(book);
        i++;
    }
    fclose(f);
}

void info_output_all(){
    REP(maxn){
        if(it[o]!=NULL){
            p(*it[o]);
        }
    }
    return ;
}

void info_change(){
    int t;
    t=search();
    if(t!=-1){
        TYPE b;
        b.code= it[t]->code;
        printf("\nPlease input the new goods info:\n");
        printf("Price=");
        scanf("%d",&b.price);
        if(!confirm())return;
        printf("Name=");
        scanf("%s",b.name);
        if(!confirm())return;
        printf("Author=");
        scanf("%s",b.author);
        if(!confirm())return;
        printf("Pages=");
        scanf("%d",&b.pages);
        if(!confirm())return;
        printf("ISBN=");
        scanf("%d",&b.ISBN);
        if(!confirm())return;
        printf("Date(Year)=");
        scanf("%d",&b.date.year);
        if(!confirm())return;
        printf("Date(Month)=");
        scanf("%d",&b.date.month);
        if(!confirm())return;
        printf("Date(Day)=");
        scanf("%d",&b.date.day);
        if(!confirm())return;

        printf("Change successfully.\n");
        free(it[t]);
        it[t]=new_book(b);
        p(b);

    }else{
        printf("There is no such goods!\n");
    }

    return ;
}

void info_delete(){
    int t;
    t=search();
    if(t!=-1){
        char c[5];
        printf("Please confirm to delete[N]");
        scanf("%s",c);
        if(!(strcmp(c,"Yes")&&strcmp(c,"yes")&&strcmp(c,"Y")&&strcmp(c,"y"))){
            printf("The following goods is deleted:\n");
            p(*it[t]);
            free(it[t]);
        }
    }else{
        printf("There is no such goods\n");
    }
    return ;
}

void info_find(){
    int t;
    t=search();
    if(t!=-1){
        p(*it[t]);
    }else{
        printf("There is no such goods\n");
    }
    return ;
}

void info_insert(){
    int has_empty=-1;
    REP(maxn){
        if(it[o]==NULL){
            has_empty=o;
            break;
        }
    }

    if(has_empty!=-1){
        int n;
        printf("Please input goods code:");
        scanf("%d",&n);

        int code=-1;
        REP(maxn){
            if(it[o]!=NULL && n == it[o]->code){
                code=o;
                break;
            }
        }

        if(code!=-1){
            printf("The goods already exists\n");
        }else{
            TYPE b;
            b.code=n;
            printf("\nPlease input the new goods info:\n");
            printf("Price=");
            scanf("%d",&b.price);
            printf("Name=");
            scanf("%s",b.name);
            printf("Author=");
            scanf("%s",b.author);
            printf("Pages=");
            scanf("%d",&b.pages);
            printf("ISBN=");
            scanf("%d",&b.ISBN);
            printf("Date(Year)=");
            scanf("%d",&b.date.year);
            printf("Date(Month)=");
            scanf("%d",&b.date.month);
            printf("Date(Day)=");
            scanf("%d",&b.date.day);

            it[has_empty]=new_book(b);

            printf("The following goods is inserted:\n");
            p(*it[has_empty]);
        }

    }else{
        printf("The warehouse is full\n");
    }
    return ;
}

void info_sort_by_price(){
    NODE node[maxn];
    int cnt=0;
    REP(maxn){
        if(it[o]!=NULL){
            node[cnt].price=it[o]->price;
            node[cnt++].it=o;
        }
    }
    SortByRecursion(node,cnt);

    TYPE *temp[maxn];
    REP(maxn){
        temp[o]=it[o];
        it[o]=NULL;
    }
    REP(cnt){
        it[o]=temp[node[o].it];
    }
    info_output_all();
    return ;
}

void exit_save(){
    FILE *f;
    f=fopen("goods_info.txt","w");
    REP(maxn){
        if(it[o]!=NULL){
            TYPE t=*it[o];
            int temp;
            temp=fprintf(f,"%d\t%d\t%s\t%s\t%d\t%d\t%d\t%d\t%d",
                t.code,t.price,t.name,t.author,t.pages,t.ISBN,
                t.date.year,t.date.month,t.date.day);
            printf("Output %s.\n",temp<0?"failure":"successfully");
        }
    }
    fclose(f);
    

    REP(maxn){
        if(it[o]!=NULL){
            free(it[o]);
            printf("Free memory successfully.\n");
        }
    }
    return ;
}

void read_line(FILE *f,TYPE *book){
    fscanf(f,"%d\t%s\t%s\t%d\t%d\t%d\t%d\t%d",
        &book->price,book->name,
        book->author,&book->pages,&book->ISBN,
        &book->date.year,&book->date.month,
        &book->date.day);
}

TYPE * new_book(TYPE b){
    TYPE * th;
    th=(TYPE*)malloc(sizeof(TYPE));
    th->code=b.code;
    th->price=b.price;
    REP(name_maxn)th->name[o]=b.name[o];
    REP(author_maxn)th->author[o]=b.author[o];
    th->pages=b.pages;
    th->ISBN=b.ISBN;
    th->date.year=b.date.year;
    th->date.month=b.date.month;
    th->date.day=b.date.day;
    return th;
}


void p(TYPE b){
    printf("-----------------------------------\n");
    printf("Code    : %d\n",b.code);
    printf("price     : %d\n",b.price);
    printf("Name     : %s\n",b.name);
    printf("Author     : %s\n",b.author);
    printf("Pages     : %d\n",b.pages);
    printf("ISBN     : %d\n",b.ISBN);
    printf("Date     : %d/%d/%d\n",b.date.year,b.date.month,b.date.day);
    printf("-----------------------------------\n");
}

int confirm(){
    char c[5];
    printf("Please confirm to change[Y]");
    scanf("%s",c);
    if(!(strcmp(c,"Yes")&&strcmp(c,"yes")&&strcmp(c,"Y")&&strcmp(c,"y")))
        return 1;
    return 0;
}

int search(){
    int n;
    printf("Please input goods code:");
    scanf("%d",&n);

    int code=-1;

    REP(maxn){
        if(it[o]!=NULL && n == it[o]->code){
            code=o;
            break;
        }
    }

    return code;
}

void SortByRecursion(NODE array[],int n){
    int i;
    if(1==n){
        return;
    }
    for(i=0;i<n-1;i++){
    if(array[i].price>array[i+1].price)
        swap_int(&array[i].price,&array[i+1].price);
        swap_int(&array[i].it,&array[i+1].it);
    }
    SortByRecursion(array,n-1);
}

void swap_int(int *a,int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
    return ;
}

void swap_it(TYPE *a,TYPE *b){
    TYPE *temp;
    temp=a;
    a=b;
    b=temp;
    return ;
}