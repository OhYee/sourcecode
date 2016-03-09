#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

#define REP(n) for(int o=0;o<n;o++)

const int maxn = 1005;

int read(char s[]) {
	char c;
	int i = 0;
	c = getchar();
	if(c == EOF)
		return 0;
	while(c != '\n'&&c != EOF) {
		s[i++] = c;
		c = getchar();
	}
	s[i] = '\0';
	return i;
}

int main() {
	//std::ios::sync_with_stdio(false);
	char s[maxn];
	while(read(s)) {
		int len = (int)strlen(s);
		for(int i = len / 2 + 1;i > 0;i--) {
			char temp[maxn];
			strcpy(temp,s);
			int v[maxn];
			int it = 0;
			for(int j = i;j <= len;j += i)
				v[it++] = j;

			for(int j = 0;j < it;j++) {
				int t = (i % 2 ? j + 1 : j - 1);
				t = t == -1 ? it - 1 : t == it ? t == 0 : t;
				s[v[j] - 1] = temp[v[t] - 1];
			}
			//cout << " " << s << endl;
			//v.erase(v.begin(),v.end());
		}
		cout << s << endl;
	}
	return 0;
}