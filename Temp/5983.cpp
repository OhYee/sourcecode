//**
#define debug
#include <ctime>
//*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <map>
using namespace std;

int cube[24];

int list[7][24] = {
    {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23},
    {0,5,2,7,4,9,6,11,8,13,10,15,12,1,14,3,16,17,18,19,22,20,23,21},
    {0,13,2,15,4,1,6,3,8,5,10,7,12,9,14,11,16,17,18,19,21,23,20,22},
    {20,21,2,3,4,5,6,7,8,9,16,17,12,16,14,15,0,1,18,19,10,11,22,23},
    {16,17,2,3,4,5,6,7,8,9,20,21,12,13,14,15,10,11,18,19,0,1,22,23},
    {2,0,3,1,22,20,6,7,8,9,10,11,12,13,19,17,16,4,18,5,14,21,15,23},
    {1,3,0,2,17,19,6,7,8,9,10,11,12,13,20,22,16,15,18,14,4,21,5,23}
};

int check[24]={16,17,0,1,20,21,18,19,2,3,22,23,4,5,6,7,8,9,10,11,12,13,14,15};

map<int,int> m;
void solve() {
    m.clear();
    int pos = 0;
    int num[24];
    memset(num, 0, sizeof(num));

    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 4; j++) {
            int t;
            cin >> t;
            cube[i * 4 + j] = t;
            if (!m.count(t))
                m.insert(make_pair(t, pos++));
            num[m[t]]++;
        }
    }
    
    // cout<<"Cube:"<<endl;
    // for(int i=0;i<24;i++)
    //     cout<<cube[i]<<" ";
    // cout<<endl;
    
    bool ok = true;
    for (int i = 0; i < 6 && ok; i++)
        if (num[i] != 4)
            ok = false;
    
    if (ok) {
        ok = false;
        for (int i = 0; i < 7 && !ok; i++) {
            
            cout << "Case" << i << endl;
            for(int j=0;j<6;j++)
                printf("%3d",cube[list[i][check[j]]]);
            cout<<endl;
            for(int j=6;j<12;j++)
                printf("%3d",cube[list[i][check[j]]]);
            cout<<endl;
            for(int j=0;j<6;j++)
                printf("      %3d%3d\n",cube[list[i][check[12+j*2]]],cube[list[i][check[12+j*2+1]]]);
            cout<<endl;
            

            bool flag = true;
            for (int j = 0; j < 6 && flag; j++) {
                if (!(cube[list[i][4 * j + 0]] == cube[list[i][4 * j + 1]] &&
                      cube[list[i][4 * j + 1]] == cube[list[i][4 * j + 2]] &&
                      cube[list[i][4 * j + 2]] == cube[list[i][4 * j + 3]]))
                    flag = false;
            }
            if (flag)
                ok = true;
        }
    }
    cout << (ok ? "YES" : "NO") << endl;
}

int main() {
#ifdef debug
    freopen("in.txt", "r", stdin);
    int START = clock();
#endif

    int T;
    cin >> T;
    while (T--)
        solve();

#ifdef debug
    printf("Time:%.3f s.\n", double(clock() - START) / CLOCKS_PER_SEC);
#endif
    return 0;
}