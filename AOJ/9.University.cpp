#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

#define REP(n) for(int o=0;o<n;o++)

char dict1[] = {'E','C','F','A','J','K','L','B','D','G','H','I',
'V','W','Z','Y','M','N','O','P','Q','R','S','T','U','X'};
char dict2[] = {'e','r','w','q','t','y','g','h','b','n','u','i',
'o','p','s','j','k','d','l','f','a','z','x','c','v','m'};

#define dic(c) c>='A'&&c<='Z'?dict1[c-'A']:c>='a'&&c<='z'?dict2[c-'a']:c

int main() {
	char c;
	while(c = getchar(),c != '#')
		putchar(dic(c));
	return 0;
}