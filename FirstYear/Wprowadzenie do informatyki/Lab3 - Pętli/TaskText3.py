import random

akthp = 100
maxhp = 100
zloto = 50
poziom = 1
exp = 0
napoje = 1

def losuj_obrazenia(min_obr, max_obr):
    return random.randint(min_obr, max_obr)

def leczenie():
    global akthp, maxhp
    koszt = random.randint(5, 20)
    if zloto >= koszt:
        akthp = maxhp
        print("Odpoczywasz w tawernie i regenerujesz życie. Koszt:", koszt, "złota.")
    else:
        print("Brak złota na odpoczynek!")

def kup_miksture():
    global zloto, napoje
    koszt = 10
    if zloto >= koszt:
        zloto -= koszt
        napoje += 1
        print("Kupiono miksturę leczniczą.")
    else:
        print("Brak złota na miksturę!")

def walka(przeciwnik_hp, przeciwnik_obr_min, przeciwnik_obr_max, nagroda_zloto, nagroda_exp):
    global akthp, exp, zloto, napoje, poziom, maxhp
    kolej_gracza = random.choice([True, False])

    while akthp > 0 and przeciwnik_hp > 0:
        if kolej_gracza:
            print("\nTwoja kolej! Wybierz akcję:")
            akcja = input("1. Atak\n2. Użyj mikstury (pozostało: " + str(napoje) + ")\nWybór: ")

            if akcja == '1':
                obrazenia_gracza = losuj_obrazenia(5, 15)
                przeciwnik_hp -= obrazenia_gracza
                print("Zadajesz", obrazenia_gracza, "obrażeń. Przeciwnik ma teraz", max(0, przeciwnik_hp), "życia.")
            elif akcja == '2' and napoje > 0:
                akthp = min(maxhp, akthp + 20)
                napoje -= 1
                print("Używasz mikstury. Twoje życie wynosi teraz:", akthp)
            else:
                print("Nieprawidłowy wybór lub brak mikstur.")
        else:
            obrazenia_przeciwnika = losuj_obrazenia(przeciwnik_obr_min, przeciwnik_obr_max)
            akthp -= obrazenia_przeciwnika
            print("Przeciwnik atakuje i zadaje", obrazenia_przeciwnika, "obrażeń. Twoje życie:", max(0, akthp))

        kolej_gracza = not kolej_gracza

    if akthp > 0:
        zloto += nagroda_zloto
        exp += nagroda_exp
        print("\nWygrałeś! Zdobywasz", nagroda_zloto, "złota i", nagroda_exp, "doświadczenia.")

        if exp >= 100:
            exp -= 100
            poziom += 1
            maxhp += 10
            akthp = maxhp
            print("Awansujesz na poziom", poziom, "i zwiększasz swoje życie do", maxhp, "punktów.")
    else:
        print("\nPrzegrałeś walkę...")

while True:
    print("\n--- Główne Menu ---")
    print("1. Prześpij się w tawernie")
    print("2. Kup miksturę leczniczą (10 złota)")
    print("3. Walka z przeciwnikiem prostym")
    print("4. Walka z przeciwnikiem trudnym")
    print("5. Walka z finałowym przeciwnikiem")
    print("6. Wyjście z gry")
    wybor = input("Wybierz akcję: ")

    if wybor == '1':
        leczenie()
    elif wybor == '2':
        kup_miksture()
    elif wybor == '3':
        print("\nWalka z przeciwnikiem prostym!")
        walka(30, 3, 8, 10, 20)
    elif wybor == '4':
        print("\nWalka z trudnym przeciwnikiem!")
        walka(60, 5, 12, 20, 40)
    elif wybor == '5':
        if poziom >= 3:
            print("\nWalka z finałowym przeciwnikiem!")
            walka(100, 10, 20, 50, 100)
        else:
            print("Musisz osiągnąć poziom 3, aby zmierzyć się z finałowym przeciwnikiem!")
    elif wybor == '6':
        print("Opuszczasz grę. Do zobaczenia!")
        break
    else:
        print("Nieprawidłowy wybór, spróbuj ponownie.")
