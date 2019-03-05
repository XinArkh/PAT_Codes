def appendWord(i):
        if ord('a') <= ord(inStr[i]) <= ord('z'):
            tmp = chr(ord(inStr[i]) - ord('a') + ord('A'))
        else:
            tmp = inStr[i]

        if tmp not in broken:
            broken.append(tmp)

inStr = input()
outStr = input()

broken = []

i = 0
j = 0

while i < len(inStr) and j < len(outStr):
    if inStr[i] != outStr[j]:
        if inStr[i] not in broken:
            appendWord(i)
        i += 1
    else:
        i += 1
        j += 1

output = ''
for i in range(len(broken)):
    output += broken[i]
print(output)