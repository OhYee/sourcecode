#coding:gbk
import re
import time
import urllib.request

# 格式
str1="""{% raw %}
<div><div class="fold_hider"><div class="close hider_title">点击显/隐题目</div></div><div class="fold">
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
</div></div>
{% endraw %}"""


# 删除空行
def d1(str):
    str=str.replace('\n\n','\n')
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
f = open('problem.txt','r',encoding='gbk')
while True:
    line = f.readline()
    if len(line) == 0:
        break
    str2 += line+'\n'
f.close()

p = re.compile(r'\$')
p2 = re.compile(r'Input|Output|Sample Input|Sample Output')

ss = p.split(str1)
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

url = oj+"/"+num+"."+name+".cpp"
url = " https://github.com/OhYee/ACM.github.io/blob/master/" + urllib.request.quote(url)

code = "\n\n<!--more-->\n# 题解\n\n\n\n# 代码\n```cpp "+ name + url+" 代码备份\n\n```"


# 强制转换为 utf8
ans = title + str0 + code
# ans = ans.encode('utf-8').decode('gbk')

f = open('problem.txt', 'w')
f.write(ans)            
f.close()          

