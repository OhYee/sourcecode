import urllib.request
import time
import re
import os 

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
    dr = re.compile(r'<[^>]+>',re.S)
    dd = dr.sub('',text)
    return dd

def format(text):
    text = text.replace('&lt;','<')
    text = text.replace('&gt;','>')
    text = text.replace('&quot;','"')
    text = text.replace('&amp;','&')
    text = text.replace('&#39;','\'')
    return text

def writeToFile(filename,text):
    f=open(filename,"w",encoding='UTF-8')
    f.write(text)
    f.close()

def getCode(i):
    url = "http://paste.ubuntu.com/"+str(i)+"/"
    html = getHTML(url)
    items = regex(html,r'<pre>(.*?)</pre>')
    code=""
    for item in items:
        code=format(clear(item))+"\n"
    match = re.compile(r'.*int main.*').search(code)
    if match :
        writeToFile("./ubuntu/"+str(i)+".cpp",code)
        print("\tfind cpp" + str(i)+"\n")
        

#i=25344200;
#i=25344553
#i=25344675
#i=25345040
i = 25344672
for i in range(i,i+9999999):
    getCode(i)
    
