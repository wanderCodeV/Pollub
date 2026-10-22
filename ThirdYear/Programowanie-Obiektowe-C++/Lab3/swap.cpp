#include <iostream>

template <typename T>
void mySwap (T& a, T& b)
{
    T temp;
    temp=a;
    a=b;
    b=temp;
}

int main ()
{
    int a=6;
    int b=8;
    std::cout << "przed: " << a << " " << b << std::endl;
    mySwap<int>(a,b);
    std::cout << "po: " << a << " " << b << std::endl;

    return 0;
}