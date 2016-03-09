#include <cstdio>
#include <set>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;

int read(char s[]){
	char c;
	int i=0;
	while(!(((c=getchar())>='A'&&c<='Z')||(c>='a'&&c<='z')))
		if(c==EOF)
			return 0;
	while((c>='A'&&c<='Z')||(c>='a'&&c<='z')){
		s[i++]=(c>='A'&&c<='Z'?c-'A'+'a':c);
		c=getchar();
	}
	s[i]='\0';
	return i;
}

int main(){
	//freopen("in.txt","r",stdin);
	set<string> s;
	set<string>::iterator it;
	char str[100];
	while(read(str))
		s.insert(str);

	for(it=s.begin();it!=s.end();it++)
		cout<<*it<<endl;

	return 0;
}