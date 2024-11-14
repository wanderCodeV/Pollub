def check_pass_semestr(marks):
    for curr_mark in marks:
        if curr_mark < 3:
            return False
    return True

def calculate_avarege_mark(marks):
    n = len(marks)
    sum = 0
    for curr_mark in marks:
        sum += curr_mark
    return sum / n

marks = []

print("1 - dodanie nowej oceny[2 - 5]\n2 - sprawdzenie zaliczenia semestru")
print("3 - obliczenie oceny szredniej\n4 - sortowamnie ocen\n5 - wyswietllic wszystkie oceny")
print("Inna - wyjscie z programu")
while True:
    op = int(input("Podaj komende: "))
    if op == 1:
        curr_mark = float(input("\tPodaj ocene: "))
        marks.append(curr_mark)
    elif op == 2:
        if check_pass_semestr(marks):
            print("\tSemestr zaliczony")
        else:
            print("\tSemestr nie zaliczony")
    elif op == 3:
        print("\tOcena srednia: ", calculate_avarege_mark(marks))
    elif op == 4:
        marks.sort()
    elif op == 5:
        print("\tOceny: ", marks)
    else:
        break
print("Koniec")

