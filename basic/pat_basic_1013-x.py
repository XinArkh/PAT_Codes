import math


def isPrime(n):
    if (n % 2 == 0 and n != 2) or n <= 1:
        return False
    else:
        flag = False  # Flag stands for the state that n is even
        for i in range(3, int(math.sqrt(n))+1):
            if n % i == 0:
                flag = True
                break
        return not flag


M, N = input().split()
M = int(M)
N = int(N)
i = 3
P = [2]
while True:
    if isPrime(i):
        P.append(i)
    if len(P) >= N:
        break
    i += 1
count = 0
for i in range(M, N + 1):
    print(P[i-1], end='')
    count += 1
    if count % 10 != 0 and i < N:
        print(' ', end='')
    else:
        print('\n', end='')