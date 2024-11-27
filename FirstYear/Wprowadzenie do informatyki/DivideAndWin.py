# Napisz funkcję wyznaczającą minimum i maksimum ciągu n liczb (n = 2^k). 
# Zastosuj technikę dziel i zwyciężaj:
def min(a, b):
    if a < b:
        return a
    else:
        return b

def max(a, b):
    if a > b:
        return a
    else:
        return b

def MINMAX(t):
    n = len(t)
    if n == 0:
        return None, None
    if n == 1:
        return t[0], t[0]
    if n == 2:
        return min(t[0], t[1]), max(t[0], t[1])
    
    mid = n // 2
    min1, max1 = MINMAX(t[:mid])
    min2, max2 = MINMAX(t[mid:])
    
    return min(min1, min2), max(max1, max2)

n = int(input("Podaj ilość (potęga 2): "))
t = [0] * n

for i in range(n):
    t[i] = int(input("Element " + str(i) + ": "))

print(MINMAX(t))

