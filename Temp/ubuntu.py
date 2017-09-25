import os
import re
import time
import urllib.request
import threading

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
    dirname = os.path.dirname(filename)
    if os.path.exists(dirname) == False:
        os.makedirs(dirname)
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


class myThread (threading.Thread):
    def __init__(self,name):
        threading.Thread.__init__(self)
        self.name = name
        global tot,alive
        tot+=1
        alive+=1
    def __del__(self):
        global tot
        tot-=1
    def run(self):
        print ("开启线程： " + self.name)
        threadLock.acquire()
        global num
        i = num
        num += 1
        threadLock.release()
        getCode(i)
        self.callback()

    def callback(self):
        global alive
        alive-=1
        print ("结束线程： " + self.name+"("+str(alive)+"/"+str(tot)+")")

if __name__ == '__main__':
    global num
    num = 25596793

    global tot,alive
    tot=0
    alive=0

    threadLock = threading.Lock()
    threads = []
    while 1:
        for i in range(50):
            thread = myThread("thread-"+str(i))
            thread.start()
            threads.append(thread)
        for thread in threads:
            thread.join();
        