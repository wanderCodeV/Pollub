// Lab5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "darray.h"

using namespace std;

int main()
{
    darray<int> vec;
    vec.push_back(15);
    vec.push_back(27);
    vec.push_back(34);
    vec.print();
    
}


/*
int* nazwa = new int(6); //pojedyncza liczba
delete nazwa;

int* tablica = new int[10]; //tablica

tablica[0] = 10;
*tablica = 10;
tablica[1] = 5;
*(tablica + 1) = 5;
delete[] tablica;
*/