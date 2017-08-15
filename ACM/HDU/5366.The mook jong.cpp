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

const int maxn = 65;
long long dp[] = {0,1,2,3,5,8,12,18,27,40,59,87,128,188,276,405,594,871,1277,1872,2744,4022,5895,8640,12663,18559,27200,39864,58424,85625,125490,183915,269541,395032,578948,848490,1243523,1822472,2670963,3914487,5736960,8407924,12322412,18059373,26467298,38789711,56849085,83316384,122106096,178955182,262271567,384377664,563332847,825604415,1209982080,1773314928,2598919344,3808901425,5582216354,8181135699,11990037125,17572253480,25753389180,37743426306,55315679787};

bool Do() {
    int n;
    if(!(cin >> n))
        return false;
    cout << dp[n]<<endl;
    return true;
}

int main() {
    /*
    for(int i = 4;i < 65;i++) {
        dp[i] = dp[i - 1] + dp[i - 3] + 1;
        cout<<dp[i]<<",";
    }
    */
    while(Do());
    return 0;
}