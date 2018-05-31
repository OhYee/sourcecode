def getAns(n):
    cnt = 0
    while n > 1:
        if n % 2 == 1:
            n = (3 * n + 1) / 2
        else:
            n /= 2
        cnt += 1
    return cnt


n = int(input())
print(getAns(n))
