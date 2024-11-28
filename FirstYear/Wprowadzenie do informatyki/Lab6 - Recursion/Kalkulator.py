def odliczj_rekurencyjmie(wartosc):
    if wartosc >= 0:
        print('Odliczam: ' + str(wartosc))
        wartosc = wartosc - 1
        odliczj_rekurencyjmie(wartosc)

x = int(input('Od jakiej wartosci odliczac? '))
odliczj_rekurencyjmie(x)