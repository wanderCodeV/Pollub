n = int(input("Enter board size: "))
arr = []
for i in range(n):
    el = int(input("Enter element: "))
    arr.append(el)

answer = []

for i in range(n - 1):
    elem = arr[i]
    sum_digit = 0
    while elem > 0:
        sum_digit += elem % 10
        elem //= 10

    if sum_digit > arr[n - 1]:
        answer.append(arr[i])

print("Number of elements: ", len(answer))
