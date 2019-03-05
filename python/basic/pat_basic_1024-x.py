sciNum = input()
if sciNum[0] == '+':
    sciNum = sciNum[1:]
i = 0
while sciNum[i] != 'E':
    i += 1
num = sciNum[:i]
dec = int(sciNum[i+1:])
output = ''
if dec == 0:
    print(num)
    exit(0)
if num[0] == '-':
    output += '-'
    num = num[1:]
    i -= 1
if dec < 0:
    output += '0.' + '0' * (abs(dec) - 1)
    for k in range(i):
        if num[k] == '.':
            continue
        output += num[k]
elif dec > 0:
    if len(num) - 2 <= dec:
        output += str(int(float(num) * 10**dec))
    else:
        for k in range(i):
            if num[k] == '.':
                continue
            output += num[k]
            if k == dec + 1:
                output += '.'
print(output)