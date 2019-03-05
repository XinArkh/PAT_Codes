n = int(input())
# n = 3
num = 0
while n != 1:
    if n % 2 == 0:
        n = n / 2
    else:
        n = (3*n+1)/2
    num += 1

print(num)