#include <cstdio>
#include <ctime>
#include <cstdlib>
using namespace std;

int main(){
  freopen("in.txt","w",stdout);
  srand((int)time(0));

  for(int i=0;i<1000;i++){
    printf("%d ",1000000000-1000+i);
  }

}