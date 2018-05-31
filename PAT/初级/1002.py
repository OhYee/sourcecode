pinyin = ["ling", "yi",  "er", "san", "si", "wu",   "liu", "qi", "ba",  "jiu"]
print(" ".join([pinyin[int(i)] for i in str(sum([int(i) for i in input()]))]))
