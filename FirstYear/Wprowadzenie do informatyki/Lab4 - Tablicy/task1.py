n = int(input("Podaj dlugosc tablicy: "))
tab = [0] * n
i = 0

for i in range(n):
    tab[i] = int(input("Podaj kolejna liczbe: "))

print(tab)

tab.sort()
print("Pierwsza najwieksza ", tab[n - 1])
print("Druga najwieksza ", tab[n - 2])
