num = int(input("Enter digit: "))
arr = []
while num != 0 and len(arr) != 10:
    arr.append(num)
    num = int(input("Enter digit: "))

cnt = len(arr)
left = 0
right = cnt - 1
while left < right:
    if arr[left] % 2 == 0:
        left += 1
    else:
        arr[left], arr[right] = arr[right], arr[left]
        right -= 1

print(arr)
