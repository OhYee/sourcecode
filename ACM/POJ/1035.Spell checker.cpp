/*
By:OhYee
Github:OhYee
HomePage:http://www.oyohyee.com
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
#include <map>
using namespace std;

//DEBUG MODE
#define debug 0

//循环
#define REP(n) for(int o=0;o<n;o++)

int ok;
int ldict,lstr;
string temp;
vector<string> dict;


void replace(string dict) {
    int count = 0;
    for(size_t i = 0; i < dict.length(); i++) {
        if(temp[i] != dict[i]) count++;
        if(count > 1) return;
    }
    ok = 1;
    cout << " " + dict;
}

void insert(string dict) {
    string tmp;
    for(size_t i = 0; i < temp.length(); i++) {
        if(temp[i] != dict[i]) {
            tmp = dict;
            tmp.insert(i,1,temp[i]);
            if(tmp == temp) {
                ok = 1;
                cout << " " + dict;
            }
            return;
        }
    }
}

void del(string dict) {
    string tmp;
    for(size_t i = 0; i < dict.length(); i++) {
        if(temp[i] != dict[i]) {
            tmp = dict;
            tmp.erase(i,1);
            if(tmp == temp) {
                ok = 1;
                cout << " " + dict;
            }
            return;
        }
    }
}

bool Do() {
    while(1) {
        if(!(cin >> temp))
            return false;
        if(temp == "#") break;
        dict.push_back(temp);
    }

    while(1) {
        cin >> temp;
        if(temp == "#") break;

        ok = -1;
        lstr = temp.length();

        for(size_t i = 0; i < dict.size(); i++) {
            if(dict[i] == temp) {
                cout << temp + " is correct";
                ok = 0;
                break;
            }
        }


        if(ok < 0) {
            cout << temp + ':';
            for(size_t i = 0; i < dict.size(); i++) {
                ldict = dict[i].length();
                if(lstr == ldict) {
                    replace(dict[i]);
                } else if(lstr == ldict + 1) {
                    insert(dict[i]);
                } else if(lstr == ldict - 1) {
                    del(dict[i]);
                }
            }
        }

        cout << endl;
    }

    return true;
}

int main() {
    while(Do());
    return 0;
}