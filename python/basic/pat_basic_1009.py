wordList = input().split()
wordList = wordList[::-1]
ans = ''
for w in wordList:
    ans += w + ' '
ans = ans[:len(ans)-1]
print(ans)