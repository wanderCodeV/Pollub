# Automat komórkowy

def print_array(arr, n):
    for i in range(n):
        print(arr[i], end='')
    print()

n = 81
prev_arr = [' '] * (n + 1)
curr_arr = [' '] * (n + 1)

curr_arr[n // 2] = 'o'

for _ in range(40):  
    print_array(curr_arr, n)
    prev_arr = curr_arr[:]
    for j in range(1, n - 1):
        if prev_arr[j - 1] == prev_arr[j + 1]:
            curr_arr[j] = ' '
        else:
            curr_arr[j] = 'o'
