def Bai(n):
    return 'B' * int(n)

def Shi(n):
    return 'S' * int(n)

def Ge(n):
    ret = ''
    for i in range(int(n)):
        ret += str(i+1)
    return ret

num = input()
ans = ''
if len(num) == 3:
    ans += Bai(num[0]) + Shi(num[1]) + Ge(num[2])
elif len(num) == 2:
    ans += Shi(num[0]) + Ge(num[1])
elif len(num) == 1:
    ans += Ge(num)
else:
    exit(0)
print(ans)