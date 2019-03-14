dict = {'1':'yi', '2':'er', '3':'san', '4':'si', '5':'wu', '6':'liu', '7':'qi', '8':'ba', '9':'jiu', '0':'ling'}
n = input()
# n = '1234567890987654321123456789'
sum = 0
for num in n:
    sum += int(num)
# print(sum)
out = ''
for tmp in str(sum):
    out += dict[tmp] + ' '
print(out[:len(out)-1])