num1 = int(input("Podaj liczbe 1: "))
num2 = int(input("Podaj liczbe 2: "))
num3 = int(input("Podaj liczbe 3: "))

print("Najwieksza liczba:", end='')

if num1 >= num2 and num1 >= num3:
    print(num1)
elif num2 >= num3:
    print(num2)
else:
    print(num3)