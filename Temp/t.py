g = 100

def show():
    global g
    g+=1
    print(g)

for i in range(10):
    show()