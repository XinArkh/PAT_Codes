def findHistPrs(avgPrs):
    Hist = 0
    Hflag = 0
    for k in range(len(avgPrs)):
        if avgPrs[k] > Hist:
            Hflag = k
            Hist = avgPrs[k]
    return Hflag


N, D = [int(a) for a in input().split()]
ttlStg = [int(a) for a in input().split()]
ttlPrs = [int(a) for a in input().split()]

avgPrs = []
for i in range(N):
    avgPrs.append(ttlPrs[i] / ttlStg[i])

bene = 0
while D > 0:
    k = findHistPrs(avgPrs)
    if D <= ttlStg[k]:
        bene += avgPrs[k] * D
        D = 0
    else:
        bene += ttlPrs[k]
        D -= ttlStg[k]
        avgPrs[k] = -1

print('%.2f' %bene)