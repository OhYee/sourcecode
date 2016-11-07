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

const int maxn = 20;
const int maxm = 205;

char key[maxn];
char word[maxm];

char KtoA[26];
char AtoK[26];

void GetMap() {
    memset(KtoA,0,sizeof(KtoA));
    memset(AtoK,0,sizeof(AtoK));
    int pos = 0;
    int len = strlen(key);
    for(int i = 0;i < len;i++) {
        if(KtoA[key[i] - 'A'] == 0) {
            KtoA[key[i] - 'A'] = pos + 'A';
            AtoK[pos] = key[i];
            pos++;
        }
    }
    for(int i=0;i < 26;i++) {
        if(KtoA[i] == 0) {
            KtoA[i] = pos + 'A';
            AtoK[pos++] = i + 'A';
        }
    }
}

bool Do() {
    int com;
    scanf("%d",&com);
    if(com == 0)
        return false;

    scanf("\n%s",key);
    GetMap();

    char c;
    int i = 0;
    while(!(((c = getchar()) >= 'A'&&c <= 'Z') || (c >= 'a'&&c <= 'z')));
    while((c >= 'A'&&c <= 'Z') || (c >= 'a'&&c <= 'z')||c==' ') {
        if(c == ' ') {
            putchar(' ');
        }else {
            if(com == 1) {
                putchar(AtoK[c-'A']);
            } else {
                putchar(KtoA[c - 'A']);
            }
        }
    	c = getchar();
	}

	putchar('\n');
	return true;
}

int main() {
	while(Do());
	return 0;
}
