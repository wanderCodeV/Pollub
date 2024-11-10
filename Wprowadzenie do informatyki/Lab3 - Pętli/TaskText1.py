import random
import math

def print_desk(length, player, cnt):
    if length != 0:
        iloraz = math.ceil(length / 20)
        if length % 20 == 0:
            iloraz += 1
        print('_'*iloraz*20*2)
        board = [". ", ". ", "a ", ". ", ". ", ". ", ". ", ". ", ". ", "b ", ". ", ". ", ". ", "e ", ". ", ". ", ". ", "c ", ". ", "d ",] * iloraz
        for i in range(cnt):
            board[player[i]] = str(i + 1) + ' ' 
        board_string = ''.join(board)  
        print(board_string)
        for i in range (iloraz*20):
            print(i % 10, end=' ')
        print()
        print('-'*iloraz*20*2)
    
cnt = int(input("Ilosc graczej: "))

player = [0]*cnt
wait_list = [0] * cnt
win = -1
last_player = 0
while win == -1:
    for i in range (cnt) :
        if wait_list[i] == 0:
            if player[i] % 20 == 13:
                print("Jesteś w pulapce!, zeby wydostac wyrzuc 4(")
                roll = random.randint(1, 4)
                print("Wyrzucona liczba: ", roll)
                if roll == 4:
                    print("Udało Ci się wydostać z pułapki!")
                else:
                    print("Nie udało się wydostać z pułapki. Tracisz turę.")
                    continue

            liczba = random.randint(1, 4)
            print("Gracz", i + 1, ", Wyrzucona liczba:", liczba)
            player[i] += liczba
    
            if player[i] % 20 == 2:
                player[i] += 5
                print("Pozdrawiam, 5 krokow do przodu")
            elif player[i] % 20 == 9:
                wait_list[i] = random.randint(1, 3)
                print("Ohhh, czekasz ", wait_list[i])
            elif player[i] % 20 == 13:
                print("Jesteś w pulapce!, zeby wydostac wyrzuc 4(")
                roll = random.randint(1, 4)
                print("Wyrzucona liczba: ", roll)
                if roll == 4:
                    print("Udało Ci się wydostać z pułapki!")
                else:
                    print("Nie udało się wydostać z pułapki. Tracisz turę.")
            elif player[i] % 20 == 17:
                player[i] = 0
            elif player[i] % 20 == 19:  
                win = i
            
            if player[i] > last_player:
                last_player = player[i]
        else:
            wait_list[i] -= 1
            print("Gracz", i + 1, " czeka :(")
    print_desk (last_player, player, cnt)
    input("Naciśnij Enter, aby kontynuować...")
    print("\n\n\n\n")
print("*"*50)
print("Gracz ", win + 1, " wygral")
print("*"*50)

