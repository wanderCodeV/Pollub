import random
import math

board = [".", ".", ".", ".", ".", "a", ".", ".", ".", ".", "b", ".", ".", ".", ".", "e", ".", ".", "c", "d"]

def print_desk(length, player, cnt):
    if length != 0:
        iloraz = math.ceil(length / len(board))
        if length % len(board) == 0:
            iloraz += 1
        print('_' * iloraz * len(board) * 2)

        display_board = board * iloraz
        for i in range(cnt):
            display_board[player[i]] = str(i + 1)

        board_string = ' '.join(display_board)
        print(board_string)
        for i in range(iloraz * len(board)):
            print(i % 10, end=' ')
        print()
        print('-' * iloraz * len(board) * 2)

cnt = int(input("Ilość graczy: "))

player = [0] * cnt 
wait_list = [0] * cnt  
win = -1
last_player = 0

while win == -1:
    for i in range(cnt):
        if wait_list[i] == 0:
            if board[player[i] % len(board)] == "e":
                print(f"Gracz {i + 1} jest w pułapce! Aby się wydostać, musisz wyrzucić 4.")
                roll = random.randint(1, 4)
                print("Wyrzucona liczba:", roll)
                if roll == 4:
                    print("Udało Ci się wydostać z pułapki!")
                else:
                    print("Nie udało się wydostać z pułapki. Tracisz turę.")
                    continue

            liczba = random.randint(1, 4)
            print(f"Gracz {i + 1}, wyrzucona liczba: {liczba}")
            player[i] += liczba

            pos = player[i] % len(board)
            if board[pos] == "a":
                player[i] += 5
                print("Pozdrawiam, 5 kroków do przodu!")
            elif board[pos] == "b":
                wait_list[i] = random.randint(1, 3)
                print(f"Ohhh, czekasz {wait_list[i]} tur.")
            elif board[pos] == "e":
                print("Jesteś w pułapce! Aby się wydostać, musisz wyrzucić 4.")
                roll = random.randint(1, 4)
                print("Wyrzucona liczba:", roll)
                if roll == 4:
                    print("Udało Ci się wydostać z pułapki!")
                else:
                    print("Nie udało się wydostać z pułapki. Tracisz turę.")
            elif board[pos] == "c":
                player[i] = 0
                print("Wracasz na start.")
            elif board[pos] == "d":
                win = i
                break  
            if player[i] > last_player:
                last_player = player[i]
        else:
            wait_list[i] -= 1
            print("Gracz", str(i + 1), " czeka :(")
    
    print_desk(last_player, player, cnt)
    input("Naciśnij Enter, aby kontynuować...")
    print("\n\n\n\n")

print("*" * 50)
print("Gracz ", str(win + 1)," wygrał!")
print("*" * 50)
