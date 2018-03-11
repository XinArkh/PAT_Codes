n = int(input())
name = []
number = []
grade = []
i = 0
while i < n:
    inStr = input()
    tmp1, tmp2, tmp3 = inStr.split()
    tmp3 = int(tmp3)
    name.append(tmp1)
    number.append(tmp2)
    grade.append(tmp3)
    i += 1
maxg = 0
maxf = 0
ming = 200
minf = 0
j = 0
while j < n:
    if grade[j] > maxg:
        maxg = grade[j]
        maxf = j
    if grade[j] < ming:
        ming = grade[j]
        minf = j
    j += 1
print('%s %s' %(name[maxf], number[maxf]))
print('%s %s' %(name[minf], number[minf]))