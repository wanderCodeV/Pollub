n = int(input("Podaj ilosc: "))
tab = [int] * n

for i in range(n):
    tab[i] = int(input("Podaj elemnty: "))

print("Wynik: ", end="")
if n % 2 == 1:
    print(tab[i // 2])
else:
    print((tab[i // 2] + tab[i // 2 + 1]) / 2)
