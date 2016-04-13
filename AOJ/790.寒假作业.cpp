/*
By:OhYee
Github:OhYee
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
using namespace std;

//DEBUG MODE
#define debug 0

//循环
#define REP(n) for(int o=0;o<n;o++)

//分数类
class Fraction {
public:

	int a,b;//a分子，b分母

	//最大公约数
	const int gcd(int a,int b) {
		return b == 0 ? a : gcd(b,a%b);
	}

	//化为最简分数
	const void lowest(Fraction &f) {
		bool fs = (f.a < 0);
		f.a = abs(f.a);
		f.b = abs(f.b);

		int cc = gcd(f.a,f.b);
		f.a = f.a / cc;
		f.b = f.b / cc;

		if(fs)
			f.a *= -1;
	}

	const Fraction Add(Fraction a,Fraction b) {
		//当一个加数为0时
		if(a.a == 0)
			return b;
		if(b.a == 0)
			return a;

		a.a *= b.b;
		b.a *= a.b;
		a.a += b.a;
		a.b *= b.b;
		lowest(a);
		return a;
	}

	//加号定义
	Fraction operator + (Fraction rhs) {
		return Add(rhs,*this);
	}

	//乘号定义
	Fraction operator * (Fraction rhs) {
		rhs.a *= a;
		rhs.b *= b;
		lowest(rhs);
		return rhs;
	}

	void print() {
		//if(b == 1)
			//printf("%d",a);
		//else
			printf("%d/%d",a,b);
	}

	//构造函数
	Fraction() {
		a = 0;
		b = 1;
	}
	Fraction(int aa,int bb) {
		a = aa;
		b = bb;
		lowest(*this);
	}
};

bool Do() {
	#if debug
	printf("*\n");
	#endif

	Fraction ans = Fraction(0,1);
	Fraction temp = Fraction(0,1);
	Fraction temp2 = Fraction(0,1);

	char c;
	bool fs = false;

	#define CONDITION \
	((c >= '0'&&c <= '9') || c == '/' || c == '+' || c == '*' || c == '-') \

	while(c = getchar(),!CONDITION) {
		if(c == '\n') {
			ans.print();
			putchar('\n');
			return true;
		}
		if(c == EOF)
			return false;
	}
	int num = 0;
	while(CONDITION) {
		//数字
		if(c >= '0'&&c <= '9') {
			num *= 10;
			num += c - '0';
		} else {
			//分数存入
			if(c == '/') {
				if(fs)
					num *= -1;
				temp.a = num;
			} else {
				temp.b = num;

				//符号存入
				if(c == '-') {
					fs = true;
				} else {
					fs = false;
				}

				#if debug
				printf("temp:");
				temp.print();
				printf("\n");
				#endif

				if(c == '+'||c=='-') {
					if(temp2.a != 0) {
						temp2 = temp2 * temp;
						ans = ans + temp2;
					} else {
						ans = ans + temp;
					}
					temp2 = Fraction(0,1);
				}
				if(c == '*') {
					if(temp2.a == 0)
						temp2 = temp;
					else
						temp2 = temp2 * temp;
				}

			}
			//清除数字
			num = 0;
		}

		c = getchar();
	}
	temp.b = num;

	#if debug
	printf("temp:");
	temp.print();
	printf("\n");
	#endif

	if(temp2.a != 0) {
		temp2 = temp2 * temp;
		ans = ans + temp2;
	} else {
		ans = ans + temp;
	}

	ans.print();
	putchar('\n');
	return true;
}

int main() {
	while(Do());
	return 0;
}