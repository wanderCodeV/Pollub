n = int(input("Podaj ilosc: "))
tab = []

for i in range(n):
    num = int(input("Podaj elemnty: "))
    if 1 <= num <= 100:
        tab.append(num)
    else:
        i -= 1

tab.sort()

for i in range (1, n):
    if tab[i] == tab[i - 1]:
        print("Sa jednakowe liczby ", tab[i])
        break
else:
    print("Nie ma jednakowych liczb")
