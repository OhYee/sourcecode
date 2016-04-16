#include<cstdio>
using namespace std;

#define REP(n) for(int o=0;o<n;o++)

struct Point{
       int x,y;
};
struct direction{
       bool up;
       bool down;
       bool left;
       bool right;
};

Point a,b;
int N;
Point c[50];
Point d[50];


bool can_go(int x,int y){
       REP(N){
              if(c[o].x<=x && c[o].y<=y && d[o].x>=x && d[o].y>=y)return false;
       }
       return true;
}
bool is_in_way(){

}

bool work(){
       scanf("&d &d &d &d",&a.x,&a.y,&b.x,&b.y);
       if(!(a.x||a.y||b.x||b.y))return false;
       scanf("%d",&N);
       REP(N){
              scanf("&d &d &d &d",x1,y1,x2,y2);
              int x1,y1,x2,y2;
              c[o].x=min(x1,x2);
              c[o].y=max(x1,x2);
              d[o].x=min(y1,y2);
              d[o].y=max(y1,y2);
       }

       //用bfs从开始位置向外拓展，分别走到不能走的地方，标记上方向和路径，在转弯处继续下一级bfs



       return true;
}

int main(){
       for(;work();){;}
       return 0;
}
