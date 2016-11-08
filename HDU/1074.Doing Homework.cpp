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
#include <bitset>
using namespace std;

const int INF = 0x7FFFFFFF / 2;
const int maxn = 16;
const int maxstate = (1 << 15);


int Deadline[maxn],Score[maxn];
struct Node {
    string Name;
    int Deadline;
    int Time;
};
struct Node2 {
    int min;
    int time;
    int last;
};
Node Homework[maxn];
Node2 dp[maxstate];
stack<string> s;


int SetI(int num,int i,bool flag) {
    if(flag)
        return num | (1 << i);
    else
        return num & (0 << i);
}
bool GetI(int num,int i) {
    return num >> i & 1;
}
int GetChange(int num1,int num2) {
    int n = num1 ^ num2;
    int i = 0;
    while(n) {
        if(n & 1)
            return i;
        n >>= 1;
        i++;
    }
    return 0;
}

void Do() {
    int n;
    cin >> n;

    int sum = 0;
    int mt = 0;

    for(int i = 0;i < n;i++)
        cin >> Homework[i].Name >> Homework[i].Deadline >> Homework[i].Time;

    dp[0].min = 0;
    for(int i = 1;i <= (1 << n) - 1;i++)
        dp[i].min = INF;

    for(int i = 0;i < (1 << n) - 1;i++) {
        for(int j = 0;j < n;j++)
            if(!GetI(i,j)) {
                int NewState = SetI(i,j,1);
                int Time = dp[i].time + Homework[j].Time;
                int ReduceScore = (Time > Homework[j].Deadline) ? (Time - Homework[j].Deadline) : 0;
                if(dp[NewState].min > dp[i].min + ReduceScore) {
                    dp[NewState].min = dp[i].min + ReduceScore;
                    dp[NewState].time = Time;
                    dp[NewState].last = i;
                }
            }
    }

    cout<<dp[(1 << n) - 1].min<<endl;

    int k = (1 << n) - 1;
    while(k) {
        int pos = GetChange(k,dp[k].last);
        s.push(Homework[pos].Name);
        k = dp[k].last;
    }

    while(!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }
    return;
}
int main() {
    cin.tie(0);
    std::cin.sync_with_stdio(false);

    int T;
    cin >> T;
    while(T--)
        Do();

    return 0;
}