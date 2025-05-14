// Mariia Nyzhnyk grupa 1.4/8
// Zadanie 2 - Klasa Radio
#pragma once
#include <iostream>

class Radio
{
public:
	Radio();
	~Radio();
	void Wlacz(bool status);
	void Info();
	void ZmienStacje(int posnowaStacja);
	void DodajStacje(int posNowaStacja, float czestStacja);

private:
	std::string producent;
	int rozmiarPamieci;
	float* pamiec;
	int aktualnaStacja;
	bool wlaczona;
};