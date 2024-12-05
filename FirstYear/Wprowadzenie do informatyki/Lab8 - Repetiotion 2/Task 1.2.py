n = int(input("Podaj ilosc: "))
sum = 0

for i in range (n):
    num = int(input("Podaj elemnty: "))
    sum += num*num

print("Suma kwadratow: ", sum)