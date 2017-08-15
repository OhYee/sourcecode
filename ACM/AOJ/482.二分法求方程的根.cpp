//*/
#define debug
#include <ctime>
//*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <iomanip>
#include <cmath>
using namespace std;

const double eps = 1e-12;

#define f(x) a*x*x*x*x + b*x*x*x+c*x*x+d*x+e

bool equal(double a,double b) {
    return fabs(a - b) < eps;
}

int main(){
    #ifdef debug
    freopen("in.txt", "r", stdin);
    int START = clock();
    #endif
    cin.tie(0);
    cin.sync_with_stdio(false);
    
    double a,b,c,d,e,x1,x2;
    while(cin >> a >> b >> c >> d >> e >> x1 >> x2){
        double x = (x1+x2)/2;
        double y1 = f(x1);
        double y2 = f(x2);
        //cout << "y1 = "<<y1<<" y2 = "<<y2<<endl;
        while(1){
            x = (x1+x2)/2;
            double y = f(x);
            //cout << "x = "<<x<<" y = "<<y<<endl;
            getchar();
            if(equal(0.0,y))
                break;
            if(y*y1 < 0)
                x2 = x;
            else
                x1 = x;
        }
        cout << fixed << setprecision(10) << x << endl;
    }

    #ifdef debug
    printf("Time:%.3fs.\n", double(clock() - START) / CLOCKS_PER_SEC);
    #endif
    return 0;
}