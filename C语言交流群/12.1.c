/*
12.1 群作业
编写一个C程序代码:
程序目的：熟络函数及指针的用法。
要求：
1．先向数组中读入数值，每次读入前要有提示、读入后清屏。
2．读入一个数值，同样要有读入提示,清屏。
3．函数实现：查找出数组中能被2.中读入数值整除的元素，并删除，函数返回值为
   删去元素的个数。
4.删除元素后的数组输出要在自己编写函数外。
实例：
读入前的提醒不予展示
读入数组：3（第一个元素） 按ENTER键
清屏效果：提示读入的printf();还在但“3”不显示，直接读如下一个数据，直到数组长度
例：（假设数组长度为5）
3 enter
5 enter
23 enter
46 enter
57 enter
读入2.数据
3 enter
输出示例：
5  23  46 换行
      21
提示，清屏语句为system(“cls”);有的编译器还要预处理#incalude <stdlib.h>这个头文件，或者是#include <conio.h>反正总是可以实现的 话不多说加油哈

*/


//By：OhYee

/*
爸爸没看懂题，求下次好好排下版23333
大概这个意思吧23333
*/


#include <stdio.h>
#include <stdlib.h>

#define maxn 5
#define REP(n) int o;\
            for(o=0;o<n;o++)

int Read(){
    int temp;
    printf("Input a number:");
    scanf("%d",&temp);
    printf("\nThe number is %d\n",temp);
    printf("Press any key to continue.");
    system("pause");
    system("cls");
    return temp;
}

int out(int * a,int cnt){
    printf("Del %d numbers.\n",cnt);
    printf("The numbers in the array are:");
    REP(maxn-cnt)printf("%d ",a[o]);
}

int main(){
    int a[maxn],b,cnt=0;
    b=Read();


    REP(maxn){
        a[o-cnt]=Read();
        if(a[o-cnt]%b==0)cnt++;
    }

    out(a,cnt);

    return 0;
}
