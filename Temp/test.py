#coding = utf-8
f = open('problem.txt','r',encoding='gbk')
while True:
    line = f.readline()
    if len(line) == 0: 
        break
    else:
        print(line)
f.close()