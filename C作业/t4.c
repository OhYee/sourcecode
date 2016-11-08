/*
    By:OhYee
    Email:oyohyee@oyohyee.com
    GitHub:OhYee (孔晨皓)
*/
#include <stdio.h>

#define pi 3.14

int main(){
    int r,h;
    printf("Please input r:");
    scanf("%d",&r);
    printf("Please input h:");
    scanf("%d",&h);
    printf("S=%.2f V=%.2f\n",4*pi*r*r,(double)4/3*pi*r*r*h);
    return 0;    
}