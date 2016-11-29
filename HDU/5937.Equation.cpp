//#define debug
//#include <ctime>

#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int Left[37][10];
int lis[36][3];

//记录对应的等式是否在这支dfs树枝上
//0 (1,2) (1,3) (1,4) (1,5) (1,6) (1,7) (1,8)
//7 (2,3) (2,4) (2,5) (2,6) (2,7) 
//12 (3,4) (3,5) (3,6)
//15 (4,5)
bool vis[16];
#define Flag(a,b) (vis[(8*(a-1)-(a-1)*(a-1))+(b-a-1)])

int num[10];
int deep;

void Debug(int n, int m) {
    return;
    for (int i = 0; i < n; i++)
        cout << " ";
    cout<<n<<" "<<lis[m][0]<<"+"<<lis[m][1]<<"="<<lis[m][2];
    cout<<"\t\t\t\t\t deep:"<<n<<" p:"<<m<<"\t";
    for(int i=1;i<=9;i++)
        cout<<num[i]<<" ";
    cout<<endl;
}

void dfs(int p, int d, int cnt) {
    // 剪枝
    if (d == 36 || deep ==36) return;// 不可能有更优情况
    if (cnt/3+d <= deep) return;// 所有数字全用上也无法最优  
    if (d+36-p <= deep) return;//剩下的组合都能用上都不可能更优

    //如果有预处理能解决的问题,直接返回答案
    bool Ok = true;
    for(int i=1;i<=9;i++){
        if(num[i] < Left[p][i]){
            Ok = false;
            break;
        }
    }
    if(Ok){
        deep = max(deep,d+36-p);
        return;
    }
    
    deep = max(d,deep);

    for (int i = p; i < 36; i++) {
        num[lis[i][0]]--;
        num[lis[i][1]]--;
        num[lis[i][2]]--;
        if (num[lis[i][0]]>=0 && num[lis[i][1]]>=0 && num[lis[i][2]]>=0){
            Debug(d + 1, i);
            if(lis[i][0] < lis[i][1]){
                Flag(lis[i][0],lis[i][1]) = true;
                dfs(i + 1, d + 1, cnt - 3);
                Flag(lis[i][0],lis[i][1]) = false;
            }else{
                if(lis[i][0] == lis[i][1] || 
                    (lis[i][0] > lis[i][1] && Flag(lis[i][1],lis[i][0]) == true)
                )
                    dfs(i + 1, d + 1, cnt - 3);
            }  
        }
        num[lis[i][0]]++;
        num[lis[i][1]]++;
        num[lis[i][2]]++;
    }
}

//预处理
void Pre(){
    //init 
    memset(vis,false,sizeof(vis));

    //预处理表
    int pos = 0;
    for(int i=1;i<=9;i++)
        for(int j=1;j<=9;j++)
            if(i+j<10){
                lis[pos][0] = i;
                lis[pos][1] = j;
                lis[pos++][2] = i+j;
            }else{
                break;
            }

    //预处理结果
    memset(Left[36],0,sizeof(Left[36]));
    for(int i=35;i>=0;i--){
        for(int j=1;j<=9;j++){
            Left[i][j] = Left[i+1][j];
        }
        for(int j=0;j<3;j++)
            Left[i][lis[i][j]]++;
    }

    //预处理显示
    /*
        cout<<"lis"<<endl;
        for(int i=0;i<pos;i++){
            cout<<i<<": "<<lis[i][0]<<" + "<<lis[i][1]<<" = "<<lis[i][2]<<endl;
        } 
        cout<<endl;
        cout<<"Left"<<endl;
        for(int i=0;i<pos;i++){
            cout<<i<<": ";
            for(int j=1;j<=9;j++)
                cout<<Left[i][j]<<" ";
            cout<<endl;
        }
        cout<<"==============="<<endl;
    //*/
}

int main() {
    #ifdef debug
    freopen("in.txt", "r", stdin);
    int START = clock();
    #endif

    cin.tie(0);
    cin.sync_with_stdio(false);

    Pre();

    int T;
    cin >> T;
    for (int kase = 1; kase <= T; kase++) {
        int cnt = 0;
        for (int i = 1; i <= 9; i++) {
            cin >> num[i];
            num[i]=min(num[i],17-i);
            cnt += num[i];
        }
        deep = 0;
        dfs(0, 0, cnt);
        cout << "Case #" << kase << ": " << deep << endl;
    }

    #ifdef debug
    printf("Time:%.3lfs\n", double(clock() - START) / CLOCKS_PER_SEC);
    #endif

    return 0;
}