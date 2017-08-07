//*/
#define debug
#include <ctime>
//*/
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

char screen[7][21];

int get(int zero) {
    bool a = (screen[0][zero + 1] == 'X') ;
    bool b = screen[1][zero + 3] == 'X';
    bool c = screen[4][zero + 3] == 'X';
    bool d = screen[6][zero + 1] == 'X';
    bool e = screen[4][zero] == 'X';
    bool f = screen[1][zero] == 'X';
    bool g = screen[3][zero + 1] == 'X';

    //printf(" %d \n%d %d\n %d \n%d %d\n %d\n",a,f,b,g,e,c,d);

    if (a && b && c && d && e && f && !g) {
        return 0;
    } else if (!a && b && c && !d && !e && !f && !g) {
        return 1;
    } else if (a && b && !c && d && e && !f && g) {
        return 2;
    } else if (a && b && c && d && !e && !f && g) {
        return 3;
    } else if (!a && b && c && !d && !e && f && g) {
        return 4;
    } else if (a && !b && c && d && !e && f && g) {
        return 5;
    } else if (a && !b && c && d && e && f && g) {
        return 6;
    } else if(a && b && c && !d && !e && !f && !g){
        return 7;
    }else if (a && b && c && d && e && f && g) {
        return 8;
    } else if (a && b && c && d && !e && f && g) {
        return 9;
    }
    //printf(" %d \n%d %d\n %d \n%d %d\n %d\n",a,f,b,g,e,c,d);
    while (1);
    return 0;
}

int main() {
#ifdef debug
    freopen("in.txt", "r", stdin);
    int START = clock();
#endif
    cin.tie(0);
    cin.sync_with_stdio(false);

    int T;
    scanf("%d", &T);
    while (T--) {
        for (int i = 0; i < 7; i++)
            for (int j = 0; j < 21; j++)
                scanf("\n%c", &screen[i][j]);
        printf("%d%d:%d%d\n", get(0), get(5), get(12), get(17));
    }

#ifdef debug
    printf("Time:%.3fs.\n", double(clock() - START) / CLOCKS_PER_SEC);
#endif
    return 0;
}
