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

int main() 
{
    int a, b;
    cout << "Podaj dwie liczby a i b: ";
    cin >>  a >> b;
    cout << binary_sum(a, b);

}

/*
5 = 101
9 = 1001
14 = 1110 = 8 + 4 + 2 = 14
5 + 9 = 14

0010 - carry
----
0101
1001
----
1110

5 and 9 = 0101
          1001
      	  ----
      	  0001

5 xor 9 = 0101
          1001
          ----
          1100

a = 1100 = 12
b = 0001 << 1 = 0010 = 2


12 and 2 = 1100
	   0001
	   ----
	   0000

12 xor 2 = 1100
	   0001
	   ----
	   1101

a = 1101 = 14
b = 0000 << 0 = 0

*/