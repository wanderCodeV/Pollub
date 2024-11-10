import random
n = 6
win = [0] * n

for i in range (n):
    win[i] = random.randint(1, 40)

num = []

while (len(num) != 6):
    curr_num = int(input("Podaj liczbe w zakresie 1-40: "))
    if not(1 <= curr_num <= 40):
        print("Liczba nie jest ")
        i -= 1
    else:
        num.append(curr_num)

cnt = 0
for elem in num:
    if elem == win[i]:
        cnt += 1

print(num)
print(win)

if cnt <= 3:
    print("Przegral")
elif cnt == 4:
    print("Wygrana 50zl")
elif cnt == 5:
    print("Wygrana 400zl")
else:
    print("Wygrana 2000zl")
