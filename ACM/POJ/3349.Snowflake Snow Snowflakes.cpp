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


const int maxl = 10000005;
const int maxn = 100005;
const int HashSize = maxn;


int HashTable[HashSize];
int Next[maxn];
int Link[maxn][6];
int pos;

void Init() {
    pos = 0;
    memset(Next,-1,sizeof(Next));
    memset(HashTable,-1,sizeof(HashTable));
}

//hash
bool HashCmp(int a[6],int b[6]) {
    for(int i = 0;i < 6;i++) {
        if(a[i] == b[0]) {
            for(int k = 1;k == 1 || k == -1;k -= 2) {
                for(int j = 1;j < 6;j++) {
                    int n = (i + k*j + 6) % 6;
                    if(a[n] != b[j])
                        break;
                    else
                        if(j == 5)
                            return true;
                }
            }
        }
    }
    return false;
}

int Hash(int a[6]) {
    int sum = 0;
    for(int i = 0;i < 6;i++)
        sum += a[i];
    return sum%HashSize;
}

bool HashInsert(int a[6]) {
    int h = Hash(a);
    if(HashTable[h] == -1) {
        memcpy(Link[pos],a,6 * sizeof(int));
        HashTable[h] = pos++;
    } else {
        int k = HashTable[h];
        int last = HashTable[h];
        while(k != -1) {
            if(HashCmp(a,Link[k]))
                return false;
            last = k;
            k = Next[k];
        }
        memcpy(Link[pos],a,6 * sizeof(int));
        Next[last] = pos++;
    }
    return true;
}

bool Do() {
    int n;
    scanf("%d",&n);
    Init();
    bool Find = false;
    int a[6];
    for(int o = 0;o < n;o++) {
        for(int i = 0;i < 6;i++)
            scanf("%d",&a[i]);
        if(!HashInsert(a)) {
            Find = true;
            break;
        }
    }

    if(Find)
        printf("Twin snowflakes found.\n");
    else
        printf("No two snowflakes are alike.\n");

    return false;
}

int main() {
    while(Do());
    return 0;
}