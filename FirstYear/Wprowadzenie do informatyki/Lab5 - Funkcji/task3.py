
def find_min(tab):
    print("Pierwsza najwiejsza: ", tab[0])
    print("Druga najwiejsza: ", tab[1])

def delete_elem(tab):
    for i in range (0, len(tab)-3):
        tab[i] = tab[i + 2]
    tab.pop()
    tab.pop()


n = int(input("Podaj ilosc: "))
tab = []
for i in range (n):
    tab.append(int(input("Podaj wartosc: ")))

tab.sort()

find_min(tab)
delete_elem(tab)

print(tab)

