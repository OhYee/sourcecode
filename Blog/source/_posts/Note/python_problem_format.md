---
title: 使用 Python 写 OJ 题目格式生成工具
date: 2016-12-10 20:20:52
categories: 笔记
tags:
 - Python
---
使用正则表达式将文本分割开,然后拼接成应该的格式  

转码成 `utf-8` 输出出来  

算是第一次学 Python 吧  
学习了下一些基本的语法  

<!--more-->

```python 格式转换
#coding:utf-8
# -*- coding: utf-8 -*-
import re
import time
import urllib.request

# 格式
str1="""{% raw %}
<div>
    <div class="oj">   
        <div class="part" title="Description">
{% endraw %}
            $
{% raw %}
        </div>
        <div class="part" title="Input">
{% endraw %}
            $
{% raw %}
        </div>
        <div class="part" title="Output">
{% endraw %}
            $
{% raw %}
        </div>
        <div class="samp">
            <div class="clear"></div>
            <div class="input part" title="Sample Input">
{% endraw %}
                $
{% raw %}
            </div>
            <div class="output part" title="Sample Output">
{% endraw %}
                $
{% raw %}
            </div>
            <div class="clear"></div>
        </div>
    </div>
</div>
{% endraw %}"""


# 删除空行
def d1(str):
    str=str.replace('\n\n','')
    return str
def d2(str):
    str=str.replace('\n\n','\n')
    return str

# 末尾加两个空格
def k(str):
    p = re.compile(r'\n')
    line = p.split(str)
    str=''
    for i in range(0,len(line)):
        str+=line[i]+'  \n'
    return str

# 获取时间
def GetNowTime():
    return time.strftime("%Y-%m-%d %H:%M:%S",time.localtime(time.time()))



#====================================#
#               main                 #
#====================================#

# 读入内容
str2 = ''
f = open('in.txt')
while True:
    line = f.readline()
    if len(line) == 0:
        break
    str2 += line+'\n'
f.close()

p = re.compile(r'\$')
p2 = re.compile(r'Input|Output|Sample Input|Sample Output')

ss=p.split(str1)
ss2 = p2.split(str2)

str0=''

for i in range(0,5):
    if i < 3:
        ss2[i] = k(d1(ss2[i]))
    else:
        ss2[i] = k(d2(ss2[i]))

for i in range(0, 5):
    str0 += ss[i] + ss2[i]
str0 += ss[5]

oj = input("输入OJ名称:")
num = input("输入题目编号:")
name = input("输入题目名称:")

title = '---\ntitle: '+oj+" "+num+"."+name+"\ndate: "+GetNowTime()+"\ncategories: "+'题解'+"\ntags:\n - "+oj+"\n---\n\n# "+'题目'+"\n"

url = "https://github.com/OhYee/ACM.github.io/blob/master/"+oj+"/"+num+"."+name+".cpp"
url = urllib.request.quote(url)

code = "\n\n# 题解\n\n\n\n# 代码\n```cpp "+ name + url+" 代码备份\n\n```"


# 强制转换为 utf8
ans = title + str0 +code
ans = ans.encode('UTF-8').decode('GBK')

f = open('in.txt', 'w')
f.write(ans)            
f.close()          


```
