import re


def judge(s):
    wrong = False
    l = s.split('P')
    if len(l) != 2:
        return False
    r = l[1].split('T')
    if len(r) != 2:
        return False
    if not re.match(r'[PAT]+', s):
        return False

    # print([l[0], r[0], r[1]])

    return (len(l[0]) * len(r[0]) == len(r[1])) and len(r[0]) > 0


n = int(input())
for i in range(n):
    s = input()
    print("YES" if judge(s) else "NO")
