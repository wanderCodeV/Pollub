num = int(input("Podaj liczbe: "))
pov = int(input("Podaj wykladnik: "))
target = int(input("Podaj ograniczenie: "))
res = 1
i = 0
while i < pov and res < target:
    res *= num
if res  > target:
    res /= num
print("Potega: ", res)