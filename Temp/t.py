#!/usr/bin/python
ans = 1;
for i in range(2,100):
    ans = ans ^ i;
    print(i,ans)