def f(n):
    if n==1:
        return 1
    ans = n*f(n-1)
    print(n,ans)
    return ans

def zx(n):
    sum = pow(n,n-1)
    for i in range(2,n):
        sum+=i*(pow(n,n-1-i))
    return sum

def zd(n):
    sum = 0
    for i in range(0,n):
        sum+=i*(pow(n,i))
    return sum


#for i in range(2,20):
#    print(i,zx(i),zd(i))


def MAX(d):
    return  pow(d,d-1)/pow(d-1,2)+(d-1)*pow(d,d)/(d-1)


for i in range(2,20):
    print(MAX(i),zd(i))