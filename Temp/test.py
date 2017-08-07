def f(n,p):
    return 1 + (p - 1) * (1 - pow(p - 1, n - 1)) / (2 - p)
print(f(3,0.3))
print(f(4,0.3))
print(f(5,0.3))