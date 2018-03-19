Week = {'A': 'MON', 'B': 'TUE', 'C': 'WED', 'D': 'THU', 'E': 'FRI', 'F': 'SAT', 'G': 'SUN'}


L1 = input()
L2 = input()
L3 = input()
L4 = input()

length12 = min(len(L1), len(L2))
ans = ''
flag = False  # flag means whether it is the second pair
for i in range(length12):
    if not flag and L1[i] == L2[i] and 'A' <= L1[i] <= 'G':
        ans += Week[L1[i]] + ' '
        flag = True
    elif flag and L1[i] == L2[i] and ('0' < L1[i] < '9' or 'A' < L1[i] < 'N'):
        if '0' < L1[i] < '9':
            ans += '0' + L1[i] + ':'
        else:
            hh = ord(L1[i]) - ord('A') + 10
            ans += str(hh) + ':'
length34 = min(len(L3), len(L4))
for j in range(length34):
    if L3[j] == L4[j] and ('a' <= L3[j] <= 'z' or 'A' <= L3[j] <= 'Z'):
        break
ans += '%02d' %j
print(ans)