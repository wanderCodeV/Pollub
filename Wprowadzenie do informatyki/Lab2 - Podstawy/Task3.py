num = int(input("Podaj liczbe od 0 do 999: "))
if num < 0 or num > 999:
    print("Nieprawidlowe dane wejsciowe")
else:
    setki = num // 100
    dzesiatki = num % 100 // 10
    jednosci = num % 10
    suma = setki + dzesiatki + jednosci
    print( "Suma cyfr: " + str(suma) + " setki: " + str(setki) + " dziesiątki: " + str(dzesiatki) + " jedności: " + str(jednosci))