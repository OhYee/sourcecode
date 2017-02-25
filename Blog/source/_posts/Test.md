---
title: Test
date: 2016-06-03 20:29:03
tags:
---

Test Hexo post

<!--more-->

** 测试加粗 ** 

*** 测试斜体 ***

# 测试标题1

## 测试标题2

### 测试标题3

#### 测试标题4

##### 测试标题5

###### 测试标题6

> 测试引用

> 测试引用

{% blockquote [author[, source]] [link] [source_link_title] %}
content
{% endblockquote %}

{% blockquote David Levithan, Wide Awake %}
Do not just seek happiness for yourself. Seek happiness for all. Through kindness. Through mercy.
{% endblockquote %}

{% blockquote @DevDocs https://twitter.com/devdocs/status/356095192085962752 %}
NEW: DevDocs now comes with syntax highlighting. http://devdocs.io
{% endblockquote %}


    测试代码段
    
    测试代码段
    
测试代码高亮

pullquote  


{% pullquote [class] %}
content
{% endpullquote %}

jsfiddle  


{% jsfiddle shorttag [tabs] [skin] [width] [height] %}

gist  

{% gist gist_id [filename] %}


iframe  


{% iframe url [width] [height] %}

include_code  

{% include_code [title] [lang:language] path/to/file %}

slug  

{% post_path slug %}

slug  

{% post_link slug [title] %}



{% asset_path slug %}


{% asset_img slug [title] %}


{% asset_link slug [title] %}


raw  

{% raw %}
content
{% endraw %}


cq  

{% centerquote %}blah blah blah{% endcenterquote %}



`include<cstdio> `

``` cpp Title http://www.oyohyee.com Link
#include <cstdio>
int main(){
    printf("Hello World!");
    return 0;
}
```

``` bash

npm install hexo -g

```

<mark>aaa</mark>
bbb
