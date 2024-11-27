n = int(input('Podaj dlugosc tablicy: '))
tab = [0]*n
i = 0

for i in range (n):
    tab[i] = int(input('Podaj kolejna liczbe: '))

print(tab)

start = int(input('Podaj poczatek przedzialu: '))
end = int(input('Podaj koniec przedzialu: '))

cnt = 0
for elem in tab:
    if start <= elem <= end:
        cnt += 1

print("W przedziale od", start, " do ", end, " miesci sie: ", cnt)
        