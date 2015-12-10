/*
                                    !                              !!
                                                           !!!!!!!!!!
                                                         !!!!     !
                                   ! !                    !!II!!!  !!
                       !!      !!!!   !!!!!!!!              !!IIIII!!
                  !              !!!!!!!!!       !!IILLLLLII! !!!!III!
               !!!!!!!!   !    !!!          !! !LOLLLLIII!!I!   !   !I
               !!I!!!!     !!!!         !!!! !LLI!ILLOOLLI
               !I!!!                        LOI    LVVVO!LVI
             ! !!!!                      ! LV!     LVVVVOLI!!!!!!!!!
            !! !!! !!!!!!!                 IO   IOOVVVOI!  !!!!!!!!!
              !!                            !    !IIII!    !!!!!!!!
                !!!!!!!!!!!!!!!!!!!!
                !!!!!!!!!!!!
               !!!                                                  !
               !!!                                          !!!!
                !!            !!!!!!           !!!       !IOVVVVOOLI!
                !!  !!      !LVVLI!                    ! !VVVVVOOOOLLI
                !!! !      !VVL!IILII                !!  OVVOLLIIIIIII
               !! !       !VV!IVEEEVLLI                IVVVLIIIIIIIIII
                !!!!      LV! !!LEEVIOL             !LOVVVLIIIIIIIIIII
                 !!!!     OV    IVVOVL              IVVVVOIIIIIIIIIIII
                   III    OV! !OVVOOO   !!!!        !IOVVVLIIIIIIIIIII
                    !II!! !VVI  !III! !!!!!!!          ILOOLIIIIIILLI!
                      !!! !!LOL!                          !!!!!I!!!!!

            賢い　可愛い　エリチカ
            BUG退散
            ラブライブ　LOVELIVE!
*/

#include <stdio.h>//头文件
#include <string.h>

FILE *f;//全局变量 读入文件用
//数据
#define maxn 1005//可能读入数据的最大值
int N;//随机数个数
int num[maxn];//数据是否已存在 1为已存在 0为不存在
int a;
int sum;//不同的随机数个数
 int main(){
    f=fopen("random.in","r");//打开文件
    fscanf(f,"%d",&N);//读入 随机数个数 N
    memset(num,0,sizeof(num));//给数组全部赋值为0（所有数都不存在）
    sum=0;//不同的随机数个数 赋值0
    for(int i=0;i<N;i++){//循环N次 来读入数据
        fscanf(f,"%d",&a);//读入一个数 都入到a
        if(num[a]==0){sum+=1;}//num中，该数据对应的是否为0（是否不存在），如果不存在，则加上1。
        num[a]=1;//不管是否存在，给该数据赋值1，说明已存在
    }
    fclose(f);//关闭文件 读入结束
    f=fopen("random.out","w");//打开文件 准备写出
    fprintf(f,"%d\n",sum);//写出 相同的随机数个数
    for(int i=0;i<maxn;i++){//循环判断该数据是否存在
        if(num[i]==1){//若i对应的数据在数组中的数值是1（存在），则输出
               if(sum==1){
                    fprintf(f,"%d",i);
                    break;//如果已经全部输出，就直接跳出循环，后面已经不存在数据
               }
               fprintf(f,"%d ",i);
               sum-=1;//有一个数被输出，剩下没输出的数-1
        }
    }
    fclose(f);
    return 0 ;
 }
