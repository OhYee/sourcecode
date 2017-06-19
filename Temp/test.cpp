#include <stdio.h>  
struct node {  
int divisor;            //表示除数  
int  remainder;     //表示余数  
}T[1000];  
  //求最大公约数  
int gcd ( int n, int m)  
{  
    return m ? gcd(m, n%m) : n;  
}  
  int main( )  
{  
   //MAX_NUM表示的是所求的解的范围的最大值，MIN_NUM表示所求的解的范围的最小值，//n表示的是同于方程的个数，m表示的是三个除数的乘积，gcd_max表示的是两个数的最大公约数，因为三个除数是互素的//所以gcd_max=1；  
    int i, j, n, t = 0,m = 1, sum = 0, gcd_max = 0, MAX_NUM, MIN_NUM;  
   printf("请输入有几个方程：\n");    
    scanf("%d", &n);  
    printf("请输入每组数据（  余数 除数）：\n"); 
    for ( i = 0; i < n; i++)  
        scanf("%d%d",&T[i].remainder,&T[i].divisor );  
    printf("请输入所求值的值域：min max\n" );  
        scanf("%d%d",&MIN_NUM, &MAX_NUM);  
//求出三个除数的乘积m  
    for ( i = 0; i < n; i++) {  
    gcd_max = gcd (T[i].divisor, gcd_max);  
    m = m * T[i].divisor;  
    }  
    gcd_max *= m;  
//求mI  
    for ( i = 0; i < n; i++)   
    {     
        t = 0;m = 1;   
        for ( j = 0; j < n; j++)  
        {  
            if (j != i  )  
            {  
                t = gcd( T[j].divisor , t);  
                m  = m * T[j].divisor;  
            }  
        }  
        t = m * t;  
        m = t;  
        while (m % T[i].divisor != 1)  
            m += t;  
        sum += m * T[i].remainder;  
    }  
    printf("最小的值为：\n");  
    printf("%d\n",sum % gcd_max);  
    printf("在所求的值域内值：\n");  
   if (sum >= MIN_NUM && sum <= MAX_NUM)  
    {  
        sum-=gcd_max;  
    while(sum>=MIN_NUM && sum<=MAX_NUM)  
    {   
        printf("%d   ",sum);  
        sum += gcd_max;  
    }  
    }else{  printf("No Solution!\n");   }  
  return 0; } 
