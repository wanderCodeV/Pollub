

answer = 0
wybor = 10
while wybor != 0:
    wybor = int(input("Podaj operacje (0 - wyjscie, 1 [+], 2 [-], 3 [*], 4 [/], 5[^]): "))

    
    if wybor == 1:
        num = int(input("Podaj liczbe do dodania: "))
        answer += num
    elif wybor == 2:
        num = int(input("Podaj liczbe do odejmowania: "))
        answer -= num
    elif wybor == 3:
        num = int(input("Podaj liczbe do mnożenia: "))
        answer *= num
    elif wybor == 4:
        num = int(input("Podaj liczbe do dzielenia: "))
        while num == 0:
            num = int(input("Liczba musi być != 0!\nPodaj liczbe do odejmowania: "))
        answer /= num
    elif wybor == 5:
        num = int(input("Podaj wykladnik potegi: "))
        base = answer
        for i in range (num):
            answer *= base
    elif wybor != 0:
        print("Nieprawidłowa operacja")
    
    if 0 < wybor <= 5:
        print(answer)
print("Dziekujemy za skorzystanie z naszego kalkulatora")