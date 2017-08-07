#include <cstdio>
double pow(double a, int n) {
    if (n == 0)
        return 1.0;
    if (n == 1)
        return a;
    double ans = pow(a, n / 2);
    ans = ans * ans;
    if (n & 1)
        ans *= a;
    return ans;
}
double f(int n,double p){
    return 1 + (p - 1) * (1 - pow(p - 1, n - 1)) / (2 - p);
}
int main(){
    printf("%f\n",f(4,0.3));
    return 0;
}