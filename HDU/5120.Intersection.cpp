/*
By:OhYee
Github:OhYee
Blog:http://www.oyohyee.com/
Email:oyohyee@oyohyee.com

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
#include <set>
#include <functional>
#include <bitset>
using namespace std;

const int maxn = 45;
const int maxm = 1000005;
const double pi = 3.141592653589;
int a[maxn];
int dp[maxn][maxm];

struct O {
	double x;
	double y;
	double r;
	O(double x,double y,double r) {
		this->x = x;
		this->y = y;
		this->r = r;
	}
};
inline double Ha(double a,double b,double c) {
	double p = (a + b + c) / 2;
	double ans = sqrt(p*(p - a)*(p - b)*(p - c));
	return ans;
}
inline double distance(double x1,double y1,double x2,double y2) {
	double ans = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
	return ans;
}
inline double Sshanxing(double r,double h) {
	double th = asin(h / r);
	return th  * r *r / 2;
}
inline double Ssanjiao(double h,double r) {
	return sqrt(r*r - h*h)*h / 2;
}
inline double Syuan(double r) {
	return pi*r*r;
}


inline double S(O o1,O o2) {
	double dis = distance(o1.x,o1.y,o2.x,o2.y);
	if(dis + 1e-8 > o2.r + o1.r)
		return 0;
	if(dis < fabs(o2.r - o1.r) + 1e-8) {
		double r = min(o1.r,o2.r);
		return pi * r * r;
	}


	double costh1 = (o1.r*o1.r + dis*dis - o2.r*o2.r) / (2 * o1.r*dis);
	double costh2 = (o2.r*o2.r + dis*dis - o1.r*o1.r) / (2 * o2.r*dis);
	double th1 = acos(costh1);
	double th2 = acos(costh2);
	return th1*o1.r*o1.r + th2*o2.r*o2.r - o1.r*dis*sin(th1);

	/*double h = Ha(o1.r,o2.r,dis) / dis * 2;
	double S1 = Sshanxing(o1.r,h) - Ssanjiao(h,o1.r);
	double S2 = Sshanxing(o2.r,h) - Ssanjiao(h,o2.r);
	double s = (S1 + S2) * 2;
	return s;*/
}

void Do() {
	double r,R;
	double x1,x2,y1,y2;
	scanf("%lf%lf",&r,&R);
	scanf("%lf%lf",&x1,&y1);
	scanf("%lf%lf",&x2,&y2);

	O o1x(x1,y1,r);
	O o1d(x1,y1,R);
	O o2x(x2,y2,r);
	O o2d(x2,y2,R);

	double ans = S(o1d,o2d) - S(o1x,o2d) - S(o1d,o2x) + S(o1x,o2x);

	printf("%.6f\n",ans);
}

int main() {
	int T;
	scanf("%d",&T);
	for(int i = 1;i <= T;i++) {
		printf("Case #%d: ",i);
		Do();
	}
	return 0;
}