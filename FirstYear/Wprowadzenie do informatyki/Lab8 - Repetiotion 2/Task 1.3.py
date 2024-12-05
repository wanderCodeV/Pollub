min = num = int(input("Podaj liczbe: "))
sum = 0
n = 0
while num % 10 != 0:
    if num < min:
        min = num
    sum += num
    n += 1
    num = int(input("Podaj liczbe: "))

print("Najmniejsza: ", min)
print("Srednia: ", sum / n)
