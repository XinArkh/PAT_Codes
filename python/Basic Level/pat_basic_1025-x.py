head, N, K = [a for a in input().split()]
N = int(N)
K = int(K)
d = {}
for i in range(N):
    h, data, next = [a for a in input().split()]
    d[h] = [data, next, '-1']
p = head
while d[p][1] != '-1':
    nextP = d[p][1]
    d[nextP][2] = p
    p = nextP
p = head
for i in range(K-1):
    p = d[p][1]
head = p
tmp = d[head][1]
while d[p][2] != '-1':
    d[p][1], d[p][2] = d[p][2], d[p][1]
    p = d[p][1]
d[p][2] = d[p][1]
d[p][1] = tmp
d[head][2] = '-1'
p = head
while d[p][1] != '-1':
    print('%s %s %s' %(p, d[p][0], d[p][1]))
    p = d[p][1]
print('%s %s %s' %(p, d[p][0], d[p][1]))