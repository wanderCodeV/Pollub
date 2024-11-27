from math import *

print("Równanie kwadratowe a*x^2 + b*x + c = 0")
a = int(input("Podaj a: "))
b = int(input("Podaj b: "))
c = int(input("Podaj c: "))

delta = b*b - 4*a*c
if delta < 0:
    print("Brak pierwiastków")
elif delta == 0:
    x = -1*b / 2*a
    print("Pierwiastek: " + str(x))
else:
    pierwistek_delta = sqrt(delta)
    x1 = (-1*b + pierwistek_delta)/(2*a)
    x2 = (-1*b - pierwistek_delta)/(2*a)
    print("Pierwiastki: " + str(x1),  str(x2))