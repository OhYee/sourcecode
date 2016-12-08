#include <cstdio>
#include <iostream>
#include <iomanip>
using namespace std;
const double PI = 3.1415927;
int main(){
	/*
	double r;
	while(scanf("%lf",&r)!=EOF)
		printf("%.3f\n",4.0/3.0*PI*r*r*r);
	*/
	double r;
	while(cin>>r)
		cout<<fixed<<setprecision(3)<<4.0/3.0*PI*r*r*r<<endl;
	return 0;
}