import urllib.request
import time
import re
import os 


# =======================

def getHTML(url):
    print("getting " + url)
    response=urllib.request.urlopen(url)
    html=response.read().decode('utf-8')
    return html

def regex(content,reg):
    pattern = re.compile(reg,re.S)
    items = re.findall(pattern,content)
    return items
    
def clear(text):
    return re.compile(r'<[^>]+>',re.S).sub('',text)

def getProblem(html):
    vjs = [r'<dd>(.*?)</dd>'] # r'<div class="panel_content">(.*?)</div>', # ,r'<pre>(.*?)</pre>'
    results = []
    for vj in vjs:
        contents = regex(html,vj)
        for content in contents:
            results.append(clear(content))
    return results



def getVJ(oj,problemID):
    url = 'https://cn.vjudge.net/problem/' + oj.lower() + '-' + problemID
    head = 'https://cn.vjudge.net/problem/description/'

    html1 = getHTML(url)
    id = regex(html1,r'data-id=\"(.*?)\"')[0]
    print("id="+id)

    results = getProblem(getHTML(head+id))
    name = regex(html1,r'<h2>(.*?)</h2>')[0]
    results.insert(0,name);

    return results

def replaceBR(str):
    str = re.compile(r'<br>',re.S).sub('\n',str)
    return str

def getAOJProblem(html):
    results = regex(html,r'<div class="panel-body">(.*?)</div>')
    # if len(results) == 4:
    #     results[0] += '\n' + results[3]
    #     results.pop(3)
    # results.insert(3,regex(html,r'<pre id="PreInput" class="IO">(.*?)</pre>')[0])
    # results.insert(4,regex(html,r'<pre id="PreOutput" class="IO">(.*?)</pre>')[0])
    return results

def getAOJ(oj,problemID):
    url = "http://112.27.234.70:8899/problem.aspx?id="+problemID
    html = getHTML(url)

    results = getAOJProblem(html)
    print(results)
    name = regex(html,r'<div style="font-family:STZhongsong;font-size:30px;text-align:center">(.*?)</div>')[0]
    results.insert(0,name)
    for i in range(0,len(results)):
        results[i] = clear(replaceBR(results[i]))
    return results
    


# ===============
str1="""
{% fold 点击显/隐题目 %}
<div class="oj"><div class="part" title="Description">
$
</div><div class="part" title="Input">
$
</div><div class="part" title="Output">
$
</div><div class="samp"><div class="clear"></div><div class="input part" title="Sample Input">
$
</div><div class="output part" title="Sample Output">
$
</div><div class="clear"></div></div></div>
{% endfold %}"""


# 替换格式  
def d1(str):
    str = str.strip()
    str = re.compile(r'(\n){1,}',re.S).sub('\n',str)
    str = str.replace('<','&lt;')
    return str+'\n'

# 获取时间
def GetNowTime():
    return time.strftime("%Y-%m-%d %H:%M:%S",time.localtime(time.time()))

def formatProblem(results):
    problem = ''
    ss = re.compile(r'\$').split(str1)
    for i in range(0,5):
        problem += ss[i]
        if i+1 < len(results):
            problem += d1(results[i+1])
    problem += ss[5]
    return problem

def formatHead(oj,num,name):
    return '---\ntitle: '+oj+" "+num+"."+name+"\ndate: "+GetNowTime()+"\ncategories: "+'题解'+"\ntags:\n - "+oj+"\n---\n\n# "+'题目'+"\n"

def formatCode(name,code):
    url = 'https://github.com/OhYee/sourcecode/tree/master/ACM'
    return "\n\n<!--more-->\n# 题解\n\n\n\n# 代码\n{% fold 点击显/隐代码 %}```cpp "+ name +" "+ url+" 代码备份\n" + code + "\n```\n{% endfold %}" 



# ===============
def readFromFile(filename):
    str = ''
    f = open(filename,'r',encoding='UTF-8')
    while True:
        line = f.readline()
        if len(line) == 0:
            break
        str += line
    f.close()
    return str

def writeToFile(filename,text):
    dirname = os.path.dirname(filename)
    if os.path.exists(dirname) == False:
        os.makedirs(dirname)
    f=open(filename,"w",encoding='UTF-8')
    f.write(text)
    f.close()

# ===============

if __name__=='__main__':
    oj = input("输入OJ名称:").upper()
    num = input("输入题目编号:")

    if oj == "AOJ" :
        results = getAOJ(oj,num)
    else:
        results = getVJ(oj,num)

    name = re.compile(r'\t|\n|\r?',re.S).sub('',results[0])
    print("name: " + name)
    # print(results)
    # exit()
    # for result in results:
    #     print("###########")
    #     print(result)

    filename = "./Temp/"+num+".cpp"
    code = readFromFile(filename)


    out = formatHead(oj,num,name)+formatProblem(results)+formatCode(name,code)
    # print(out)
    mdfilename = "./Blog/source/_posts/"+oj+"/"+num+".md" 
    writeToFile(mdfilename,out)
    print("write mdfile("+mdfilename+")")

    tofilename = "./ACM/"+oj+"/"+num+"."+name+".cpp"
    os.rename(filename,tofilename)
    print("move code file from " + filename + " to " + tofilename)
     