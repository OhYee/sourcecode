import urllib.request
import os 
import platform

def getHTML(url):
    print("getting " + url)
    response=urllib.request.urlopen(url)
    html=response.read().decode('utf-8')
    return html

def writeToFile(filename,text):
    dirname = os.path.dirname(filename)
    if os.path.exists(dirname) == False:
        os.makedirs(dirname)
    f=open(filename,"w",encoding='UTF-8')
    f.write(text)
    f.close()

if __name__=='__main__':
    host = getHTML("https://raw.githubusercontent.com/googlehosts/hosts/master/hosts-files/hosts")
    writeToFile("./hosts",host)
    sysstr = platform.system()
    if(sysstr =="Windows"):
        os.system(r"move .\hosts %SystemRoot%\System32\drivers\etc\hosts")
    elif(sysstr == "Linux"):
        os.system(r"sudo mv ./hosts /etc/hosts")
    else:
        print ("Unknown system.")