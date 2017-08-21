#include <cstdio>

int read_int() {
    char c;
    int ans = 0;
    while(c = getchar(),!(c >= '0'&&c <= '9'));
    while(c >= '0'&&c <= '9') {
        ans *= 10;
        ans += (int)c - '0';
        c = getchar();
    }
    return ans;
}

int main(){
    int n=read_int();
    int ans = 0;
    while(n--){
        ans ^= read_int();
    }
    printf("%d\n",ans);
    return 0;
}