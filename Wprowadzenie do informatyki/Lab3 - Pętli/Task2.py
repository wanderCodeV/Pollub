n = int(input("Podaj ilosc n:"))
suma = 0
i = 0
while i < n:
    num = int(input("Podaj liczbe:"))
    if 10 <= num <= 50:
        suma += num*num
        i += 1
    else:
        print("Podana liczba poza zakresem")
print("Suma kwadratow: ", suma)