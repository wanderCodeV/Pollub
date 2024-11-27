#include <iostream>
#include <vector>

using namespace std;

int binary_sum(int a, int b)
{
    int carry = 0;
    while(b > 0)
    {
        carry = (a & b);
        a = a ^ b;
        b = carry << 1;
    }
    return a;
}

int binary_multiplication(int a, int b)
{
    int result = 0;
    while(b > 0)
    {
        if (b & 1 == 1)
            result = binary_sum(result, a);
        b = b >> 1;
        a = a << 1;
    }
    return result;
}

int main() 
{
    int a, b;
    cout << "Podaj dwie liczby a i b: ";
    cin >>  a >> b;
    cout << binary_multiplication(a, b);

}

/*
5 = 101
9 = 1001
45 = 101101 = 32 + 8 + 4 + 1 = 45
5 * 9 = 45


    0101
    1001
    ----
    0101
   0000
  0000
 0101
 -------
    0101
 0101
 -------
 0101101



2 = 10
3 = 11
2 * 3 = 6 = 110 = 4 + 2 = 5

 10
 11
---
 10
10
---
100

2 and 3
10
11
--
10


*/