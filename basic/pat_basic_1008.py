N, M = input().split()
N = int(N)
M = int(M)
numList = input().split()
for i in range(M):
    tmp = numList[N-1]
    for j in range(N-1):
        numList[N-j-1] = numList[N-j-2]
    numList[0] = tmp
    i += 1
ans = ''
for n in numList:
    ans += str(n) + ' '
ans = ans[:len(ans)-1]
print(ans)