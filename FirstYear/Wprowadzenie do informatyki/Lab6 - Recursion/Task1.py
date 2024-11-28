import math

def print_permutation(line, p = 0):
    if p != len(str_inp):
        for i in range (p, len(line)):
            line[i], line[p] = line[p], line[i]
            print_permutation(line, p + 1)
            line[i], line[p] = line[p], line[i]
    else:
        print(line)

str_inp = list(input("Podaj slowo: "))
print_permutation(str_inp)