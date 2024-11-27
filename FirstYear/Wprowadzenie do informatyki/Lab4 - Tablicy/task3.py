tab = []

elem = int(input('Podaj kolejna liczbe: '))
while elem != 0:
    tab.append(elem)
    elem = int(input('Podaj kolejna liczbe: '))

print(tab)

n = len(tab)
i = 0
for i in range (n//2):
    if tab[i] != tab[n - i - 1]:
        print("Tablica nie symetryczna")
        break

if i + 1 == n//2:
    print("Tablica symetryczna")

