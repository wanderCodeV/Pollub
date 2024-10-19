print("Gra „Papier, nożyce, kamień”")
player1 = int(input("Gracz 1: Podaj symbol (0 – papier, 1 – nożyce, 2 – kamień): "))
player2 = int(input("Gracz 2: Podaj symbol (0 – papier, 1 – nożyce, 2 – kamień): "))
if player1 < 0 or player2 < 0 or player1 > 2 or player2 > 2:
    print("Nieprawidlowe dane wejsciowe")
else:
    if player1 == player2 :
        print("Remis!")
    else:
        result = player2 - player1
        if abs(result) == 2:
            result *= -1

        if result < 0:
            print("Wygral gracz 1")
        else:
            print("Wygral gracz 2")


# nożyce > papier 1 > 0
# nożyce < kamień 1 < 2
# kamień > nożyce 2 > 1
# kamien < papier 2 < 0