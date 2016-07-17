#include "stdafx.h"
//====================================================================
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

struct BigInter {
	bool postive;
	vector<int> num;

	#define MAX 9999999
	#define BIT 100000000

	//迭代器
	typedef vector<int>::iterator itor;
	typedef unsigned long long Inter;
	
	//构造函数
	BigInter() {
		Init();
	}
	BigInter(BigInter &rhs) {
		Init();
		postive = rhs.postive;
		num = (vector<char>)(rhs.num);
	}
	BigInter(Inter rhs) {
		ReadFromInter<Inter>(rhs);
	}
	BigInter(int rhs) {
		ReadFromInter<int>(rhs);
	}
	BigInter(string &s) {
		ReadFromString<string>(s,s.size());
	}
	BigInter(char* s) {
		ReadFromString<char*>(s,strlen(s));
	}
	template<typename T>
	BigInter* ReadFromString(T s,int len) {
		Init();
		num.clear();
		int Begin = 0;
		//读入负号
		if(s[0] == '-')
			postive = false;
		//消除前导0
		for(int i = 0;i < len;i++) {
			if(s[i] > '0'&&s[i] < '9') {
				Begin = i;
				break;
			}
		}
        int t=0;
		for(int i = len - 1;i >= Begin;i--){
            t=t*10+s[i]-'0';
            if(t>MAX){
                num.push_back(t%BIT);
                t/=BIT;
            }
        }
        num.push_back(t);
        standard();
		return this;
	}
	template<typename T>
	BigInter* ReadFromInter(T rhs) {
		postive = (rhs >= 0);
		num.clear();
		long long k = rhs;
        int t=0;
		while(k) {
			num.push_back(k % BIT);
			k /= BIT;
		}
		return this
	}
	void Init() {
		num.clear();
		num.push_back(0);
		postive = true;
	}


	//判断函数
	bool operator == (BigInter &rhs) {
		return compare(rhs) == 0;
	}
	bool operator != (BigInter &rhs) {
		return compare(rhs) != 0;
	}
	bool operator < (BigInter &rhs) {
		return compare(rhs) == -1;
	}
	bool operator > (BigInter &rhs) {
		return compare(rhs) == 1;
	}
	bool operator >= (BigInter &rhs) {
		return compare(rhs) >= 0;
	}
	bool operator <= (BigInter &rhs) {
		return compare(rhs) <= 0;
	}
	int compare(BigInter &rhs) {
		//-1 小于 0 等于 1 大于
		if(postive == rhs.postive && num == rhs.num)
			return 0;

		if(postive == rhs.postive) {
			if(this->Bit() == rhs.Bit()) {
				for(int i = this->Bit() - 1;i >= 0;i--) {
					if(num[i] != rhs.num[i])
						return (num[i] < rhs.num[i]) ? -1 : 1;
				}
			} else {
				return (this->Bit() < rhs.Bit()) ? -1 : 1;
			}
		} else {
			return rhs.postive ? -1 : 1;
		}
		return 0;
	}

	//运算函数
	BigInter operator + (BigInter &rhs) {
		BigInter ans;
		if(postive == rhs.postive) {
			add(*this,rhs,ans);
			ans.postive = postive;
		} else {
			BigInter absa = this->abs();
			BigInter absb = rhs.abs();
			if(absa < absb) {
				minute(absb,absa,ans);
				ans.postive = rhs.postive;
			} else {
				minute(absa,absb,ans);
				ans.postive = postive;
			}
		}
		return ans;
	}
	BigInter operator + (Inter &rhs) {
		return _ADD<Inter>(*this,rhs);
	}
	BigInter operator + (int &rhs) {
		return _ADD<int>(*this,rhs);
	}
	BigInter operator - (BigInter &rhs) {
		BigInter b = rhs;
		b.postive = !b.postive;
		return *this + b;
	}
	BigInter operator - (Inter &rhs) {
		return _Minute<Inter>(*this,rhs);
	}
	BigInter operator - (int &rhs) {
		return _Minute<int>(*this,rhs);
	}
	BigInter operator * (BigInter &rhs) {
		//每次运算8位
		const int length = 8;

		BigInter a = *this;
		BigInter b = rhs;

		Inter aa;
		Inter bb;

		BigInter ans;
		int t = 0;
		while(!(a.isZero() && b.isZero())) {
			aa = a.GetLastNum(length);
			a.DelLastNum(length);
			bb = b.GetLastNum(length);
			b.DelLastNum(length);

			aa *= bb;

			int pos = t;
			while(aa) {
				ans[pos] += aa % 10;
				aa /= 10;
				pos++;
			}
			t += 2 * length;
		}
		ans.standard();
		return ans;
	}
	BigInter operator * (Inter &rhs) {
		return _Mulit<Inter>(*this,rhs);
	}
	BigInter operator * (int &rhs) {
		return _Mulit<int>(*this,rhs);
	}
	BigInter operator / (Inter rhs) {
		//每次运算16位
		const int length = 16;

		BigInter a = *this;
		Inter b = rhs;

		Inter aa;

		BigInter ans;
		int t = 0;
		while(!a.isZero()) {
			aa = a.GetLastNum(length);
			a.DelLastNum(length);

			aa /= b;

			int pos = t;
			while(aa) {
				ans[pos] += aa % 10;
				aa /= 10;
				pos++;
			}
			t += length;
		}
		ans.standard();
		return ans;
	}
	BigInter operator / (BigInter &rhs) {
		BigInter a;
		int it = Bit();

		BigInter d;
		BigInter c;

		while(it > 0) {
			a = (d * (BigInter)10) + (BigInter)num[it];
			c = c * (BigInter)10;

			int t;
			for(int i = 0;i <= 9;i++) {
				if(a < rhs * (BigInter)(i + 1)) {
					t = i;
					break;
				}
				t = 9;
			}
			c = c + (BigInter)t;
			d = a - rhs * (BigInter)t;
			it--;
		}
		return c;
	}
	Inter operator % (Inter rhs) {
		Inter ans = (*this - (*this / rhs) * (BigInter)rhs).toInter();
		return ans;
	}
	BigInter operator % (BigInter &rhs) {
		BigInter a;
		int it = Bit();

		BigInter d;
		BigInter c;

		while(it > 0) {
			a = (d * (BigInter)10) + (BigInter)num[it];
			c = c * (BigInter)10;

			int t;
			for(int i = 0;i <= 9;i++) {
				if(a < rhs * (BigInter)(i + 1)) {
					t = i;
					break;
				}
				t = 9;
			}
			c = c + (BigInter)t;
			d = a - rhs * (BigInter)t;
			it--;
		}
		return d;
	}
	static void add(BigInter &a,BigInter &b,BigInter &ans) {
		int len = max(a.Bit(),b.Bit());
		for(int i = 0;i < len;i++) {
			ans[i] += a[i] + b[i];
			int k = i;
			while(ans[k] >= MAX) {
				ans[k + 1] += ans[k] / BIT;
				ans[k] %= BIT;
				k++;
			}
		}
	}
	static void minute(BigInter a,BigInter b,BigInter &ans) {
		int len = max(a.Bit(),b.Bit());
		ans = a;
		for(int i = 0;i < len;i++) {
			ans[i] -= b[i];
			int k = i;
			while(ans[k] < 0) {
				ans[k + 1]--;
				ans[k] += MAX;
				k++;
			}
		}
	}
	static BigInter pow(Inter a,Inter p) {
		if(p == 0)
			return (BigInter)1;
		BigInter t = pow(a,p / 2);
		return (p % 2) ? t*t*(BigInter)a : t*t;
	}
	template<typename T>
	BigInter _ADD(BigInter a,T b) {
		return a+(BigInter)b;
	}
	template<typename T>
	BigInter _Minute(BigInter a,T b) {
		return a-(BigInter)b;
	}
	template<typename T>
	BigInter _Mulit(BigInter a,T b) {
		return a * (BigInter)b;
	}
	//取地址操作符
	int &operator [](int pos) {
		if(pos >= Bit()) {
			while(pos >= Bit()) {
				num.push_back(0);
			}
		}
		return num[pos];
	}

	//其他函数
	Inter toInter() {
		//转化为long long 保留18位
		return GetLastNum(18);
	}
	BigInter abs() {
		//取绝对值
		BigInter ABS = *this;
		ABS.postive = true;
		return ABS;
	}
	bool isZero() {
		return Bit() == 1 && num[0] == 0;
	}
	void standard() {
		if(num.size() == 0)
			Init();
		//消除前导0
		for(itor it = num.end() - 1;it != num.begin();it--) {
			if(*it == 0)
				num.erase(it);
			else
				break;
		}
		if(num.size() == 0)
			Init();
	}
	int Bit() {
		//返回位数
		if(num.size() == 0)
			standard();
		return num.size();
	}
	int print() {
		string out;

	}
};

int vs_main() {
	printf("a\n");
	BigInter a = 1561;
	BigInter b = 5613;
	BigInter c = a + b;
	BigInter d = b*c;
	BigInter e = b / 3;

	return 0;
}

//====================================================================
int main() {
	int start = clock();
	freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	printf("#===================#\n");
	vs_main();
	printf("#===================#\n");
	printf("Time:%.3lf\n",double(clock() - start) / CLOCKS_PER_SEC);
	//system("pause");
	return 0;
}

