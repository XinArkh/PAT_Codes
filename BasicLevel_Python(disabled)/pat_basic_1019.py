def sortNum(numStr):
    numDir = [int(a) for a in numStr]
    for i in range(4-len(numDir)):
        numDir.append(0)
    big = sorted(numDir, reverse=True)
    small = sorted(numDir)
    bigNum = int(str(big[0]) + str(big[1]) + str(big[2]) + str(big[3]))
    smallNum = int(str(small[0]) + str(small[1]) + str(small[2]) + str(small[3]))
    return bigNum, smallNum

N = input()
bigNum, smallNum = sortNum(N)
while True:
    diff = bigNum - smallNum
    print('%04d - %04d = %04d' %(bigNum, smallNum, diff))
    if diff == 0 or diff == 6174:
        break
    bigNum, smallNum = sortNum(str('%04d'%diff))