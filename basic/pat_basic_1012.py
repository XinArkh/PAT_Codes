inList = input().split()
n = int(inList[0])
inList = inList[1:]
for i in range(n):
    inList[i] = int(inList[i])
A = []
a1 = 0
a2List = []
a2 = 0
a3 = 0
a4sum = 0
a4num = 0
a4 = 0
a5 = 0
for i in range(n):
    mod = inList[i] % 5
    if mod == 0:
        if inList[i] % 2 == 0:
            a1 += inList[i]
    elif mod == 1:
        a2List.append(inList[i])
    elif mod == 2:
        a3 += 1
    elif mod == 3:
        a4sum += inList[i]
        a4num += 1
    elif mod == 4:
        if inList[i] > a5:
            a5 = inList[i]
if a1 == 0:
    a1 = 'N'
if len(a2List) == 0:
    a2 = 'N'
else:
    for j in range(len(a2List)):
        a2 += (-1)**j * a2List[j]
if a3 == 0:
    a3 = 'N'
if a4sum == 0:
    a4 = 'N'
else:
    a4 = '%.1f' %(a4sum / a4num)
if a5 == 0:
    a5 = 'N'
A.append(str(a1))
A.append(str(a2))
A.append(str(a3))
A.append(str(a4))
A.append(str(a5))
ans = ''
for a in A:
    ans += a + ' '
ans = ans[:len(ans)-1]
print(ans)