n = int(input("Podaj ilosc: "))
tab = [int] * n

for i in range(n):
    tab[i] = int(input("Podaj elemnty: "))

max = 0
id = -1
for i in range(1, n):
    cnt = 1
    for j in range(i, n):
        if tab[j] >= tab[j - 1]:
            cnt += 1
        else:
            break
    if cnt > max:
        max = cnt
        id = i

print("Id pierwszego: ", id)
print("Dlugosc: ", max)
