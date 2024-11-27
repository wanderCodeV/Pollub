tab = []

elem = int(input("Podaj kolejna liczbe: "))
while elem != 0:
    tab.append(elem)
    elem = int(input("Podaj kolejna liczbe: "))

# print(tab)

n = len(tab)
tab.sort()
count = 1
i = 1
for i in range(n):
    if tab[i] == tab[i - 1]:
        count += 1
    else:
        if count > 2:
            print(tab[i - 1], end=" ")
        count = 1

# 5 5 7 6 1 5 6 1 6 8 7
