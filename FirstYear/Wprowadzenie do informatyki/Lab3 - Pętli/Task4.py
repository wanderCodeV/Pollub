num = int(input("Podaj liczbe: "))
if num % 2 == 0:
    max_elem = min_elem = num
while num % 2 == 0:
    num = int(input("Podaj liczbe: "))
    if num < min_elem:
        min_elem = num
    if num > max_elem:
        max_elem = num

potega = 1
for i in range (max_elem):
    potega *= min_elem

print("Potega ", min_elem, "^", max_elem, "=", potega)