import random

memo = [1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8]

random.shuffle(memo)
opened = 0
while opened != 16:
    ind1 = int(input("Podaj pierwszy indeks, ktory chcesz sprawdzic: "))
    ind2 = int(input("Podaj drugi indeks, ktory chcesz sprawdzic: "))
    if ind1 == ind2:
        print("Jednakowe indeksy, sprobuj ponownie")
    elif memo[ind1] == memo[ind2]:
        print("Trafil")
        opened += 2
        memo[ind1] = memo[ind2] = 0
    else:
        print("Nie trafil")

print("Koniec gry!")
