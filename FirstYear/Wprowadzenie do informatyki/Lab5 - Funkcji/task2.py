tab = []
print("1 - dodanie elementu na koniec\n2 - usuniencie elementu z konca")
print("3 - wyswietlemie wynik\nInna - wyjscie z programu")
while True:
    op = int(input("Podaj komende: "))
    if op == 1:
        curr_elem = int(input("\tPodaj ocene: "))
        tab.append(curr_elem)
    elif op == 2:
        tab.pop()
    elif op == 3:
        print(sum(tab))
    else:
        break