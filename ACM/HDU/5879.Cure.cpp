/*
By:OhYee
Github:OhYee
Blog:http://www.oyohyee.com/
Email:oyohyee@oyohyee.com

かしこいかわいい？
エリ0隶�
要写出来Хорошо的代码哦~
*/
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <bitset>
#include <functional>

using namespace std;

typedef long long LL;

const int INF = 0x7FFFFFFF;
const double eps = 1e-10;

const int maxn = 200005;

LL n;
double ans[maxn];
char s[1000000];

char cmp[] = "200000";

int read_string(char s[]) {
    char c;
    int i = 0;
    while(!((c = getchar()) >= '1' && c <= '9'))
        if(c == EOF)
            return -1;
    while(c >= '0'&&c <= '9') {
        s[i++] = c;
        c = getchar();
    }
    s[i] = '\0';
    return i;
}

bool cmp_biger(char *a,char *b) {
    int len1 = strlen(a);
    int len2 = strlen(b);
    if(len1 > len2)
        return true;
    else if(len1 == len2) {
        len1 = 0;
        while(a[len1] == b[len1] && len1 <= len2)
            len1++;
        if(len1 <= len2 && a[len1] > b[len1])
            return true;
        else
            return false;
    } else
        return false;
}

bool Do() {
    if(read_string(s) == -1)
        return false;

    //cout << cmp << " " << s << endl << "    ";

    if(cmp_biger(cmp,s)) {
        int len = strlen(s);
        n = 0;
        for(int i = 0;i < len;i++)
            n = n * 10 + s[i] - '0';
        cout << fixed << setprecision(5) << ans[n] << endl;
    } else {
        cout << "1.64493" << endl;
    }
    return true;
}


int main() {
    cin.tie(0);
    cin.sync_with_stdio(false);


    ans[1] = 1.0;
    for(int i = 2;i < maxn;i++)
        ans[i] = ans[i - 1] + 1 / (double)i / (double)i;


    while(Do());

    return 0;
}