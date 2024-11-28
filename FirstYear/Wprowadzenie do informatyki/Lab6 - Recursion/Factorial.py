def silnia(wartosc):
    if wartosc >= 1:
        return wartosc * silnia(wartosc - 1)
    else:
        return 1

x = int(input('Podaj licze: '))
wynik = silnia(x)
print(str(x) + '! = ' + str(wynik))