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
#include <iomanip> 
using namespace std;

inline double dis(double x1,double y1,double x2,double y2) {
	return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}

bool Do() {
	double x,y;
	if(!(cin >> x >> y))
		return false;

	int n;
	cin >> n;

	double Min = 9999999999;
	for(int i = 1;i <= n;i++) {
		double tx,ty,v;
		cin >> tx >> ty >> v;
		double distance = fabs(dis(x,y,tx,ty));
		Min = min(Min,distance / v);
	}

	cout << fixed << setprecision(20) << Min << endl;

	return true;
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(false);

	while(Do());
	return 0;
}