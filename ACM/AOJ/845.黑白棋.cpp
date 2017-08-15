/*/
#define debug
#include <ctime>
//*/
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

const int ans[][2] = {{1,12},{2,6},{3,4},{4,3},{6,2},{12,1}};
bool answ[6];
bool a[12];
bool Map[12][12];

int main(){
    #ifdef debug
    freopen("in.txt", "r", stdin);
    int START = clock();
    #endif
    cin.tie(0);
    cin.sync_with_stdio(false);

    int T;
    cin >> T;
    while(T--){
        for(int i=0;i<12;i++){
            char t;
            cin >> t;
            a[i] = t=='X';
        }
        memset(answ,false,sizeof(answ));

        for(int i=0;i<6;i++){
            int pos=0;
            for(int x=0;x<ans[i][0];x++){
                for(int y=0;y<ans[i][1];y++){
                    Map[x][y] = a[pos++];
                }
            }

            bool OK = true;
            for(int y=0;y<ans[i][1];y++){
                OK = true;
                for(int x=0;x<ans[i][0];x++){
                    if(!Map[x][y]){
                        OK = false;
                        break;
                    }
                }
                if(OK)
                    break;
            }
            if(OK)
                answ[i] = true;
        }

        int cnt=0;
        for(int i=0;i<6;i++)
            cnt+=(int)answ[i];
        cout << cnt;
        for(int i=0;i<6;i++)
            if(answ[i])
                cout << " " << ans[i][0] << "x"<< ans[i][1];
        cout << endl;

    }

    #ifdef debug
    printf("Time:%.3fs.\n", double(clock() - START) / CLOCKS_PER_SEC);
    #endif
    return 0;
}
