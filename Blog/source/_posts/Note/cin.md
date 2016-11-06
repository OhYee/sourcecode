---
title: 关于cin
date: 2015-10-15 12:05:00
tags: 读入输出
categories: 笔记
---

若要判断文件尾，有很多种方法。

作为对比，有

``` cpp
while(cin>>s){
            ...
}

while(!cin.eof()){
            ...
}

while(scanf("%s",&s)!=EOF){
            ...
}
```

但是`cin.eof()`并不像其看着的样子那样，能够直接判断，他还需要我们再读一下字符才能正确判断是否达到文件尾
> ABCDEFG(EOF)

也即，我们若使用`scanf`的话，在G(处就可判断到是否到达结尾

而`cin.eof()`则需要我们到达)处
