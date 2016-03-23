REP(n) for(int o=0;o<n;o++)

//优化输入
inline int read_int() {
    char c;
    int ans = 0;
    while(c = getchar(),!(c >= '0'&&c < '9'));
    while(c >= '0'&&c < '9') {
        ans *= 10;
        ans += (int)c - '0';
        c = getchar();
    }
    return ans;
}

inline int read_string(char s[]){
    char c;
    int i=0;
    while(!(((c=getchar())>='A'&&c<='Z')||(c>='a'&&c<='z')))
        if(c==EOF)
            return 0;
    while((c>='A'&&c<='Z')||(c>='a'&&c<='z')){
        s[i++]=c;
        c=getchar();
    }
    s[i]='\0';
    return i;
}
 
//优化输出
inline void write_int(long long n) {
    char str[50];
    int len = 0;
    if(n < 0) {
        n = -n;
        putchar('-');
    }
    if(n == 0)
        putchar('0');
    while(n) {
        str[len++] = (int)(n % 10) + '0';
        n /= 10;
    }
    while(len)
        putchar(str[--len]);
    return;
}