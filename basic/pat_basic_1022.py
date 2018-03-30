A, B, D = [int(a) for a in input().split()]

N = A + B
NN = ''
while N > 0:
    NN += str(N % D)
    N = int(N / D)

if NN == '':
    NN = '0'

NN = int(NN[::-1])
print(NN)