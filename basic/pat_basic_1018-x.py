res = [0, 0, 0]  # 甲胜、平、负次数
win = ['B', 'C', 'J']
win1 = [0, 0, 0]  # 甲出B、C、J胜利次数
win2 = [0, 0, 0]  # 乙出B、C、J胜利次数

N = int(input())
for i in range(N):
    p1, p2 = input().split()
    if p1 == 'C':
        if p2 == 'C':
            res[1] += 1
        elif p2 == 'J':
            res[0] += 1
            win1[1] += 1
        elif p2 == 'B':
            res[2] += 1
            win2[0] += 1
    if p1 == 'J':
        if p2 == 'J':
            res[1] += 1
        elif p2 == 'B':
            res[0] += 1
            win1[2] += 1
        elif p2 == 'C':
            res[2] += 1
            win2[1] += 1
    if p1 == 'B':
        if p2 == 'B':
            res[1] += 1
        elif p2 == 'C':
            res[0] += 1
            win1[0] += 1
        elif p2 == 'J':
            res[2] += 1
            win2[2] += 1
print(res[0], res[1], res[2])
print(res[2], res[1], res[0])
flag = max(win1)
for i in range(3):
    if win1[i] == flag:
        print(win[i], end=' ')
        break
flag = max(win2)
for i in range(3):
    if win2[i] == flag:
        print(win[i])
        break