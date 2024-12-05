min = num = int(input("Podaj liczbe: "))
sum = 0
while num != 0:
    if num < min:
        sum += num
    num = int(input("Podaj liczbe: "))
print("Suma mniejszych od pierwszej: ", sum)

