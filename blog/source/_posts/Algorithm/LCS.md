---
title: 最长公共子序列
categories: 算法
tags:
  - 最长公共子序列
  - 动态规划
date: 2016-05-08 22:39:00
---
{% blockquote 百度百科 %}
一个数列 ，如果分别是两个或多个已知数列的子序列，且是所有符合此条件序列中最长的，则 称为已知序列的最长公共子序列。
{% endblockquote %}

对于两个数最长公共子序列，意思为从两个序列中，尽可能少的删除一些数，从未使得两个序列相同

 

对于用`dp[i][j]`记录到字符串a的第i个字符和字符串b的第j个字符时的最长公共子序列

显然有
```
若 a[i]==b[j]

　　dp[i][j] = dp[i-1][j-1]+1

否则

　　dp[i][j] = max{ dp[i-1][j] , dp[i][j-1] }
```

![](/post/img/lcs.png)

如上图，可以发现每个匹配的字符，都是每种数字的最“左上”的一个

因此可以根据这个规律倒叙出最长公共子序列的一个解

```cpp 模板
//最长公共子序列
//输入字符串a 及其长度 字符串b 及其长度 保存最长公共子序列的数组
//字符从0开始
int LCS(char *a,char *b,char s[] = NULL) {
    int len1 = strlen(a);
    int len2 = strlen(b);
    char *aa = a - 1;
    char *bb = b - 1;

    //声明二维数组
    int * m = new int[(len1 + 1)*(len2 + 1)];
    int **dp = new int *[len1 + 1];
    for(int i = 0;i <= len1;i++)
        dp[i] = m + i*(len2 + 1);

    //初始化
    for(int i = 0;i <= len1;i++)
        dp[i][0] = 0;
    for(int i = 0;i <= len2;i++)
        dp[0][i] = 0;

    //动态规划
    for(int i = 1;i <= len1;i++)
        for(int j = 1;j <= len2;j++)
            if(aa[i] == bb[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j],dp[i][j - 1]);

    /*for(int i = 0;i <= len1;i++){
        for(int j = 0;j <= len2;j++)
            printf("%d\t",dp[i][j]);
        printf("\n");
    }*/

    //如果c未传值
    if(s == NULL)
        return dp[len1][len2];

    //逆序推出一条符合串
    int ans = dp[len1][len2];
    int x = len1;
    int y = len2;
    int it = ans;
    s[it] = '\0';
    while(it) {
        if(dp[x - 1][y] == it) {
            x--;
            continue;
        }
        if(dp[x][y - 1] == it) {
            y--;
            continue;
        }
        s[--it] = aa[x];
        x--;
        y--;
    }
    return ans;
}
```