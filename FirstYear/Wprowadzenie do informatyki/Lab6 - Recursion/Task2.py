
def tower_honei(n, start, help, target):
    if n == 1:
        print("Disk 1 from ", str(start), " to ", str(target))
        return
    tower_honei(n - 1, start, target, help )
    print("Disk ", str(n), " from ", str(start), " to ", str(target))
    tower_honei(n - 1, help, start, target)

n = int(input("Podaj ilosc dyskow: "))
tower_honei(n, 'I', 'II', 'III')