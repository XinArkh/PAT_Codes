A, DA, B, DB = input().split()
PA = 0
PB = 0
for i in range(len(A)):
    if A[i] == DA:
        PA = PA * 10 + int(DA)
for i in range(len(B)):
    if B[i] == DB:
        PB = PB * 10 + int(DB)
print(PA+PB)