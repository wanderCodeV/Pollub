def suma_cyfr(n):
    if n // 10 == 0:
        return n
    else:
        return n % 10 + suma_cyfr(n // 10)

n = int(input("Podaj liczbe n: "))
print("Suma syfr liczby n = ", suma_cyfr(n))