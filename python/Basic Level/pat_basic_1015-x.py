def sortStudents(S):
    if len(S) <= 1:
        return
    for i in range(len(S)-1):
        for j in range(len(S)-i-1):
            if S[j][3] < S[j+1][3]:
                S[j], S[j+1] = S[j+1], S[j]
            elif S[j][3] == S[j+1][3]:
                if S[j][1] < S[j+1][1]:
                    S[j], S[j+1] = S[j+1], S[j]
                elif S[j][1] == S[j+1][1]:
                    if S[j][0] > S[j+1][0]:
                        S[j], S[j+1] = S[j+1], S[j]
    return


N, L, H = input().split()
N = int(N)
L = int(L)
H = int(H)
S1 = []
S2 = []
S3 = []
S4 = []
for i in range(N):
    num, d, c = input().split()
    num = int(num)
    d = int(d)
    c = int(c)
    if d < L or c < L:
        continue
    else:
        if d >= H and c >= H:
            S1.append([num, d, c, d+c])
        elif d >= H and c < H:
            S2.append([num, d, c, d+c])
        elif d < H and c < H and d >=c:
            S3.append([num, d, c, d+c])
        else:
            S4.append([num, d, c, d+c])
sortStudents(S1)
sortStudents(S2)
sortStudents(S3)
sortStudents(S4)
print(len(S1)+len(S2)+len(S3)+len(S4))
for i in S1:
    print(i[0], i[1], i[2])
for i in S2:
    print(i[0], i[1], i[2])
for i in S3:
    print(i[0], i[1], i[2])
for i in S4:
    print(i[0], i[1], i[2])