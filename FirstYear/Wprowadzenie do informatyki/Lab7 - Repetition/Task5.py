n = int(input("Enter board size: "))
arr = []
for i in range(n):
    el = int(input("Enter element: "))
    arr.append(el)

move = 0

for i in range(n):
    if arr[i] != 0 and arr[i] % 5 == 0:
        move += 1
    else:
        arr[i - move] = arr[i]

for i in range(n - move):
    print(arr[i], end=" ")
print()
