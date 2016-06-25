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
using namespace std;

set<string> s;
set<string>::iterator it;

queue<string> Q;

int read_string(char s[]) {
	char c;
	int i = 0;
	while(!(((c = getchar()) >= 'A'&&c <= 'Z') || (c >= 'a'&&c <= 'z')))
		if(c == EOF)
			return -1;
	while((c >= 'A'&&c <= 'Z') || (c >= 'a'&&c <= 'z')) {
		s[i++] = c;
		c = getchar();
	}
	s[i] = '\0';
	return i;
}

bool Do() {


	char c1[15],c2[15];
	string str1,str2;
	/*if(read_string(c1) == -1 || read_string(c2) == -1)
		return false;*/

	std::ios::sync_with_stdio(false);
	if(cin >> str1 >> str2)
		return false;

	//str1 = c1;
	//str2 = c2;
	if(str1 == str2) {
		Q.push(str1);
	} else {

		it = s.find(str1);
		if(it == s.end())
			s.insert(str1);
		else
			s.erase(it);

		it = s.find(str2);
		if(it == s.end())
			s.insert(str2);
		else
			s.erase(it);

	}

	return true;
}

int vs_main() {
	s.clear();
	while(!Q.empty())
		Q.pop();

	while(Do());

	int len = (int)Q.size();
	for(int i = 0;i < len;i++) {
		string k = Q.front();
		Q.pop();
		if(s.
        
        
        
        
        
        find(k) == s.end())
			Q.push(k);
	}


	if(!(s.size() == 0 || s.size() == 2) || !Q.empty())
		printf("Impossible\n");
	else
		printf("Possible\n");
	return 0;
}