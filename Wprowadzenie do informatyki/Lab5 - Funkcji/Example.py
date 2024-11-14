def obsluz_mnozenie():
    liczba1 = int(input("Podaj pierwsza liczbe: "))
    liczba2 = int(input("Podaj druga liczbe: "))
    wynik = liczba1 * liczba2
    print('Wynik operacji wynosi: ' + str(wynik))

def obsluz_dzielenie():
    liczba1 = int(input("Podaj pierwsza liczbe: "))
    liczba2 = int(input("Podaj druga liczbe: "))
    if liczba2 != 0:
        wynik = liczba1 / liczba2
        print('Wynik operacji wynosi: ' + str(wynik))
    else:
        print('Dzeielenie przez zero!')

def podnies_do_potegi(podstawa, wykladnik):
    wynik = 0
    i = 0
    while i < wykladnik:
        wynik = wynik * podstawa
        i += 1
    return wynik

def obsluz_potegowanie():
    podstawa = -1
    wykladnik = -1
    while podstawa < 0 and wykladnik < 0 :
        podstawa = int(input("Podaj podstawa potegowania: "))
        wykladnik = int(input("Podaj wykladnik: "))

    wynik = podnies_do_potegi(podstawa, wykladnik)
    print('Wynik operacji wynosi: ' + str(wynik))

print('Witaj w kalkulatorze')
wybor = 1
while wybor != 0:
    wybor = int(input("Wybierz operacje(0 - wyjscie, 1 - mnozenie, 2 - dzielenie, 3 - potegowanie): "))
    if wybor == 1:
        obsluz_mnozenie()
    elif wybor == 2:
        obsluz_dzielenie()
    else:
        obsluz_potegowanie()