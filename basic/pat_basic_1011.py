T = int(input())
for n in range(T):
    A, B, C = input().split()
    A = int(A)
    B = int(B)
    C = int(C)
    ans = ''
    if A + B > C:
        ans = 'true'
    else:
        ans = 'false'
    print('Case #%d: %s' %((n+1), ans))