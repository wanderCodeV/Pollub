n = int(input("Enter board size: "))
arr = []
for i in range(n):
    el = int(input("Enter element: "))
    arr.append(el)

sum = 0
cnt = 0
for i in range(n - 1):
    if arr[i] > arr[n - 1]:
        sum += arr[i]
        cnt += 1

print("Suma: ", sum, " average: ", sum / cnt)
