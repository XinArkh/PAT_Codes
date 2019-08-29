def Callatz(n):
    if n % 2 == 0:
        return int(n / 2)
    else:
        return int((3*n+1) / 2)

K = int(input())
nums = input().split()
drop = []
for num in nums:
    if num in drop:
        continue
    c = Callatz(int(num))
    while c != 1:
        if str(c) in nums and str(c) not in drop:
            drop.append(str(c))
        c = Callatz(c)
outs = []
for i in range(len(nums)):
    if nums[i] not in drop:
        outs.append(int(nums[i]))
outs.sort(reverse=True)
output = ''
for j in outs:
    output += str(j) + ' '
output = output[:len(output)-1]
print(output)