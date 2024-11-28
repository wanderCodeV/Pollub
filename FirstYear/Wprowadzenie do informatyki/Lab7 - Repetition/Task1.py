flag = -1
sum = 0
cnt = 0
num = int(input("Enter digit: "))

while not (num < 0 and flag == -1):
    if num == 0:
        flag *= -1

    elif flag == 1:
        sum += num
        cnt += 1
    num = int(input("Enter digit: "))

if cnt != 0:
    print("Avarege: ", sum / cnt)
else:
    print("No number added")
