numDir = [int(a) for a in input().split()]
head = 0
for i in range(1, len(numDir)):
    if numDir[i] != 0:
        head = i
        numDir[i] -= 1
        break
output = str(head)
for i in range(len(numDir)):
    while numDir[i] != 0:
        output += str(i) * numDir[i]
        numDir[i] -= numDir[i]
print(int(output))