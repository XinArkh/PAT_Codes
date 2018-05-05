numDict = {0: 0, 1: 0, 2: 0, 3: 0, 4: 0, 5 :0 , 6: 0, 7 :0 , 8: 0, 9: 0}

N = int(input())
while(N > 0):
    k = int(N % 10)
    N = int(N / 10)
    numDict[k] += 1
out = ''
for i in range(10):
    if numDict[i] > 0:
        out += '%d:%d\n' %(i, numDict[i])
out = out[:-1]
print(out)