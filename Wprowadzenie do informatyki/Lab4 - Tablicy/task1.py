n = int(input('Podaj dlugosc tablicy: '))
tab = [0]*n
i = 0

for i in range (n):
    tab[i] = int(input('Podaj kolejna liczbe: '))

print(tab)

tab.sort()
print(tab[n-1], tab[n-2])
