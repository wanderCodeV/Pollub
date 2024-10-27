suma = 0
iloczyn = 0
cnt = 0

while suma < 255 and iloczyn < 1 :
    num = int(input("Podaj liczbe: "))
    suma += num
    iloczyn *= num
    cnt = cnt + 1
print("Srednie arytmetyczne: ", suma/cnt)