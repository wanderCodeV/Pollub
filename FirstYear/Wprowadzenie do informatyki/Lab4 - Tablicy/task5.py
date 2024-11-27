n = int(input('Podaj dlugosc tablicy: '))
while n < 4:
    n = int(input('Podaj dlugosc tablicy(n >= 4): '))
tab = [0] * n
i = 0

for i in range(n):
    tab[i] = int(input('Podaj kolejna liczbe: '))

print(tab)

sum1 = sum2 = sum3 = 0

max_sum1 = max_sum2 = 0
index1 = index2 = 0
i = 0
for i in range(n):
    sum1 += tab[i]
    if i >= 1: sum2 += tab[i]
    if i >= 2: sum3 += tab[i]

    if i % 3 == 2:
        if sum1 > max_sum1:
            max_sum2 = max_sum1
            max_sum1 = sum1
            index2 = index1
            index1 = i - 2
        elif sum1 > max_sum2:
            max_sum2 = sum1
            index2 = i - 2
        sum1 = 0
    elif i % 3 == 0:
        if sum2 > max_sum1:
            max_sum2 = max_sum1
            max_sum1 = sum2
            index2 = index1
            index1 = i - 2
        elif sum2 > max_sum2:
            max_sum2 = sum2
            index2 = i - 2
        sum2 = 0
    else:
        if sum3 > max_sum1:
            max_sum2 = max_sum1
            max_sum1 = sum3
            index2 = index1
            index1 = i - 2
        elif sum3 > max_sum2:
            max_sum2 = sum3
            index2 = i - 2
        sum3 = 0

print("Indeks: ", index1," suma: ", max_sum1)
print("Indeks: ", index2," suma: ", max_sum2)
