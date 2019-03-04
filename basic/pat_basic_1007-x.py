import math


def isPrime(n):
    if (n % 2 == 0 and n != 2) or n == 1:
        return False
    else:
        flag = False  # Flag stands for the state that n is even
        for i in range(3, int(math.sqrt(n))+1):
            if n % i == 0:
                flag = True
                break
        if flag:
            return False
        else:
            return True


N = int(input())
if N <= 4:
    print(0)
    exit(0)
d = [2, 3]
for i in range(5, N+1):
    if isPrime(i):
        d.append(i)
num = 0
for j in range(len(d)-1):
    if d[j+1] - d[j] == 2:
        num += 1
print(num)