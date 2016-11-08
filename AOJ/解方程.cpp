#include <cstdio>
#include <cmath>
int main(){
    double a,b,c;
    while(scanf("%lf%lf%lf",&a,&b,&c)!=EOF){
        double delta=b*b-4*a*c;
        if(delta>0){
            delta=sqrt(delta);
            double x1=-b+delta;
            double x2=-b-delta;
            if(x1==x2)
                printf("%.1f\n",x1);
            else
                printf("%.1f %.1f\n",x1,x2);
        }else
            printf("-1\n");
    }
    return 0;
}