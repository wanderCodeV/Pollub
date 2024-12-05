num = int(input("Podaj liczbe: "))
pov = int(input("Podaj wykladnik: "))
res = 1

for i in range (pov):
    res *= num

print("Potega: ", res)