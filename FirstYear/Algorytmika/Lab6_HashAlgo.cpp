#include <iostream>
#include <fstream>

using namespace std;

void KarpRabin(string napis, string wzor)
{
    int dn = napis.size();
    int dw = wzor.size();
    int hashW = 0, hashR = 0, hashT;
    int b = 64; 
    int p = 33554393; 

    for (int i = 0; i < dw; i++)
    {
        hashW = (hashW * b + wzor[i]) % p;
        hashR = (hashR * b + napis[i]) % p;
    }

    int bM1 = 1;
    for (int i = 1; i <= dw - 1; i++)
        bM1 = (b * bM1) % p;

    bool found = false;
    for (int i = 0; i <= dn - dw; i++)
    {
        if (hashW == hashR)
        {
            int j = 0;
            while (j < dw && wzor[j] == napis[i + j])
                j++;
            if (j == dw)
            {
                found = true;
                cout << i << " ";
            }
        }

        if (i < dn - dw)
        {
            hashR = (hashR + p - napis[i] * bM1 % p) % p; 
            hashR = (hashR * b + napis[i + dw]) % p;      
        }
    }

    if(!found)
    {
        cout << -1 ;
    }
}
int main()
{
    ifstream file;
    file.open("tekst.txt");
    string example, text;
    file >> example;

    int num = 1;
    while(file >> text)
    {
        cout << "Wiersz " << num << ": " ;
        KarpRabin(text, example);
        cout << endl;
        num++;
    }
}