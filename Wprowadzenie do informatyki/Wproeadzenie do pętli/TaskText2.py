import random

def draw_card():
    card = random.randint(2, 14)
    if card <= 10:
        return card
    elif card == 11:  # Walet
        return 2
    elif card == 12:  # Dama
        return 3
    elif card == 13:  # Król
        return 4
    else:  # As
        return 11

def check_persian_oczko(card1, card2):
    return card1 == 11 and card2 == 11

player1_score = 0
player1_card1 = 0
player1_card2 = 0
player1_stands = False

player2_score = 0
player2_card1 = 0
player2_card2 = 0
player2_stands = False

print("Tura gracza 1:")
card = draw_card()  
player1_card1 = card
player1_score += card
print("Gracz 1 wylosował: ", card)
print("Łączny wynik gracza 1: ", player1_score)

card = draw_card()  
player1_card2 = card
player1_score += card
print("Gracz 1 wylosował: ", card)
print("Łączny wynik gracza 1: ", player1_score)

if check_persian_oczko(player1_card1, player1_card2):
    print("Gracz 1 wygrywa z perskim oczkiem (dwa asy)!")
else:
    while not player1_stands and player1_score < 21:
        choice = input("Gracz 1: Dobierasz kolejną kartę? (y/n): ").lower()
        if choice == 'y':
            card = draw_card()
            player1_score += card
            print("Gracz 1 wylosował: ", card)
            print("Łączny wynik gracza 1: ", player1_score)
            if player1_score > 21:
                print("Gracz 1 przegrał! (wynik powyżej 21)")
                player1_stands = True
        else:
            player1_stands = True

print("\nTura gracza 2:")
card = draw_card() 
player2_card1 = card
player2_score += card
print("Gracz 2 wylosował: ", card)
print("Łączny wynik gracza 2: ", player2_score)

card = draw_card() 
player2_card2 = card
player2_score += card
print("Gracz 2 wylosował: ", card)
print("Łączny wynik gracza 2: ", player2_score)

if check_persian_oczko(player2_card1, player2_card2):
    print("Gracz 2 wygrywa z perskim oczkiem (dwa asy)!")
else:
    while not player2_stands and player2_score < 21:
        choice = input("Gracz 2: Dobierasz kolejną kartę? (y/n): ").lower()
        if choice == 'y':
            card = draw_card()
            player2_score += card
            print("Gracz 2 wylosował: ", card)
            print("Łączny wynik gracza 2: ", player2_score)
            if player2_score > 21:
                print("Gracz 2 przegrał! (wynik powyżej 21)")
                player2_stands = True
        else:
            player2_stands = True

print("\nKoniec gry")
if player1_score <= 21 and (player2_score > 21 or player1_score > player2_score):
    print("Gracz 1 wygrywa!")
elif player2_score <= 21 and (player1_score > 21 or player2_score > player1_score):
    print("Gracz 2 wygrywa!")
elif player1_score > 21 and player2_score > 21:
    print("Obaj gracze przegrali!")
else:
    print("Remis!")
