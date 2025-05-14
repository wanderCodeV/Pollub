// Mariia Nyzhnyk grupa 1.4/8
// Zadanie 2 - Klasa Radio
#include "radio.h"

Radio::Radio()
{
	producent = "Politechnika Lubelska";
	rozmiarPamieci = 10;
	pamiec = new float[10];
	aktualnaStacja = 0;
	wlaczona = false;
	for (int i = 0; i < rozmiarPamieci; i++)
		pamiec[i] = 0;
	pamiec[0] = 153.23f;
}

Radio::~Radio()
{
	producent.clear();
	delete[] pamiec;
}

void Radio::Wlacz(bool status)
{
	wlaczona = status;
}

void Radio::Info()
{
	if (wlaczona)
	{
		std::cout << "Radio jest wlaczone" << std::endl;
		std::cout << "Aktualna stacja " << aktualnaStacja << ": " << pamiec[aktualnaStacja] << " Hz" << std::endl;
	}
	else
	{
		std::cout << "Radio jest wylaczone" << std::endl;
	}
}

void Radio::ZmienStacje(int posnowaStacja)
{
	if (posnowaStacja >= 0 && posnowaStacja < 10)
	{
		aktualnaStacja = posnowaStacja;
	}
	else
	{
		std::cout << "Bladna stacja!\nNumer stacji musi byc w przedziale [0,10]" << std::endl;
	}
}

void Radio::DodajStacje(int posNowaStacja, float czestStacja)
{
	if (posNowaStacja >= 0 && posNowaStacja < 10)
	{
		if (czestStacja > 40)
		{
			pamiec[posNowaStacja] = czestStacja;
		}
		else
			std::cout << "Bledna czestotliwosc, musi byc wieksz niz 40" << std::endl;
	}
	else
	{
		std::cout << "Bladna stacja!\nNumer stacji musi byc w przedziale [0,10]" << std::endl;
	}
}
