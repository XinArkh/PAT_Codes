n = int(input())
while n > 0:
    test = input()
    i = 0
    num1 = 0  # 前缀A数量
    num2 = 0  # 中间A数量
    num3 = 0  # 后缀A数量
    while i < len(test):
        while i < len(test) and test[i] == 'A':
            i += 1
        num1 = i
        if test[i:i+2] != 'PA':
            print('NO')
            break
        else:
            j = 1
            while test[i+j] == 'A':
                j += 1
            i += j
            num2 = j - 1
            if test[i] != 'T':
                print('NO')
                break
            else:
                i += 1
                while i < len(test) and test[i] == 'A':
                    i += 1
                    num3 += 1
                if i < len(test) or num3 - (num2 - 1) * num1 != num1:
                    print('NO')
                    break
                print('YES')
    n -= 1
exit(0)