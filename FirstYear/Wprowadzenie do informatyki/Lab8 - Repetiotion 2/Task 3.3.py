num = int(input("Podaj elemnt: "))
min = 100
max = 0

while 10 <= num <= 500:
    
    if min > num:
        min = num
    if max < num:
        max = num
    num = int(input("Podaj elemnt: "))

print("Najwieksza: ", max)
print("Najmniejsza: ", min)