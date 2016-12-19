#include <cstdio>
#include <cstring>
using namespace std;

bool OPEN[8];   // OPEN表(还能选择的列)
int  CLOSED[8]; // CLOSED表(记录每行选取的列)
bool LURD[15];  //左上右下斜边记录
bool RULD[15];  //右上坐下斜边记录
int  cnt;       //方案数

//画出棋盘
void Draw() {
    printf(" ########\n");
    for (int i = 0; i < 8; i++) {
        printf("#");
        for (int j = 0; j < 8; j++)
            printf("%c", (j == CLOSED[i] ? 'O' : '.'));
        printf("\n");
    }
    printf("\n");
}

//初始化
void init() {
    memset(OPEN, true, sizeof(OPEN)); //初始化OPEN表
    memset(LURD, false, sizeof(LURD)); //清空左上到右下斜对角线判断数组
    memset(RULD, false, sizeof(RULD)); //清空右上到左下斜对角线判断数组
    cnt = 0;                           //计数清空
}

//搜索八皇后问题 一行一行搜索
//目前搜的是 row 行(初始从 0 开始)
void Search(int row = 0) {
    if (row == 8) {
        //找到结果
        cnt++;
        Draw();
        return;
    }
    for (int col = 0; col < 8; col++)
        if (OPEN[col] && !LURD[row - col + 7] && !RULD[row + col]) {
            OPEN[col] = false;
            CLOSED[row] = col;
            RULD[row + col] = true;
            LURD[row - col + 7] = true;
            Search(row + 1);
            OPEN[col] = true;
            RULD[row + col] = false;
            LURD[row - col + 7] = false;
        }
}

int main() {
    init();
    Search();
    printf("Count = %d.\n", cnt);
}