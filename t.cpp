#include "stdio.h"
int main() {
  int i;
  for(i = 0;;i++) {
    //printf("%d\n",i);
    int m = i * 10 + 6;
    int bit = 1;
    int temp = i;
    while(temp) {
      temp /= 10;
      bit*=10;
    }
    int n = 6 * bit + i;
    if(n == 4 * m) {
      printf("%d\n",n);
      break;
    }
  }
  return 0;
}