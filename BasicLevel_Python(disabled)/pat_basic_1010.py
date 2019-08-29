inList = input().split()
outList = []
if inList == ['0', '0']:
    outList = inList
for i in range(0, len(inList), 2):
    outList.append(int(inList[i]) * int(inList[i+1]))
    outList.append(int(inList[i+1]) - 1)
if outList[-1] == -1 and len(outList) == 2:
    print('0 0')
    exit(0)
elif outList[-1] == -1:
    outList = outList[:len(outList)-2]
ans = ''
for i in outList:
    ans += str(i) + ' '
ans = ans[:len(ans)-1]
print(ans)