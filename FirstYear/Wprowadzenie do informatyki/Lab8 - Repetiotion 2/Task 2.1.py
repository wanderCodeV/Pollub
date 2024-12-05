n = int(input("Podaj ilosc: "))

min = max = int(input("Podaj elemnty: "))

for i in range (n - 1):
    num = int(input("Podaj elemnty: "))
    if num < min:
        min = num
    if num > max:
        max = num

print("Najwieksza: ", max)
print("Najmniejsza: ", min)