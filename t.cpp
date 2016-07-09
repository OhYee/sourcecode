#include <cstdio>
#include <ctime>
#include <cstdlib>
using namespace std;

int main(){
  freopen("in.txt","w",stdout);
  srand((int)time(0));

  for(int i=0;i<100;i++){
    for(int j=0;j<100;j++){
      printf("%c",(rand()%5)==1?'@':'*');
    }
    printf("\n");
  }

}