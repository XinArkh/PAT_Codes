def binarySearch(i, l, upperBound):
    if nums[l-1] <= upperBound:
        return l
    low  = i + 1
    high = l - 1
    while low < high:
        mid = int((low+high)/2)
        if nums[mid] <= upperBound:
            low = mid + 1
        else:
            high = mid
    return high


N, p = [int(a) for a in input().split()]
nums = [int(a) for a in input().split()]

nums.sort()
n = 0
l = len(nums)
for i in range(l):
    j = binarySearch(i, l, nums[i] * p)
    if n < j - i:
        n = j - i
print(n)