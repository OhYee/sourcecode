/*
By:OhYee
Github:OhYee
HomePage:http://www.oyohyee.com
Email:oyohyee@oyohyee.com
Blog:http://www.cnblogs.com/ohyee/

かしこいかわいい？
エリーチカ！
要写出来Хорошо的代码哦~
*/

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <map>
using namespace std;

//DEBUG MODE
#define debug 0

//循环
#define REP(n) for(int o=0;o<n;o++)

const double PI = 3.1415926;

void Do() {
	double a,b,r,x,y,w,t;
	scanf("%lf%lf%lf%lf%lf%lf%lf",&a,&b,&r,&x,&y,&w,&t);

	double xb = a + r * cos(w*t);
	double yb = b + r * sin(w*t);

	double A = y - yb;
	double B = xb - x;
	double C = x * yb - xb * y;

	double l = abs(A * a + B * b + C) / sqrt(A * A + B * B);

	double ans = 2 * sqrt(r * r - l * l);

	printf("%.2f\n",abs(ans));
}

int main() {
	int T;
	scanf("%d",&T);
	while(T--) 
		Do();
	return 0;
}
