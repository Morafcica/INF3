#include "NacitanieSuboru.h"
#include <fstream>
#include <iostream>

using namespace std;

NacitanieSuboru::NacitanieSuboru(std::string nazovSuboru)
{
	this->nazovSuboru = nazovSuboru;
	this->poleCisel = nullptr;
}

NacitanieSuboru::~NacitanieSuboru()
{
	delete poleCisel;
}

void NacitanieSuboru::nacitaj()
{
	cout << "nenasiel subor" << endl;
	ifstream subor(nazovSuboru);
	cout << "daco asi nasiel no " << nazovSuboru << endl;
	while (subor.is_open()) 
	{
		cout << "uz je otvoreny" << endl;
		int pocetPrvkovPola;
		if (subor >> pocetPrvkovPola && poleCisel == nullptr) 
		{
			poleCisel = new int[pocetPrvkovPola];
			this->pocetPrvkovPola = pocetPrvkovPola;
		}

		for (int i = 0; i < pocetPrvkovPola; i++) {
			if (subor >> poleCisel[i]) {
				cout << "ulozilo sa: " << poleCisel[i] << endl;
			}
			else
			{
				break;
			}
		}

		subor.close();
	}
}

int NacitanieSuboru::vypisNajmensie()
{
	srand(time(0));
	int prveNahodne = rand() % pocetPrvkovPola - 1;
	int druheNahodne = rand() % pocetPrvkovPola - 1;
	int tretieNahodne = rand() % pocetPrvkovPola - 1;

	
	int najmensieCislo = poleCisel[prveNahodne];

	if (poleCisel[druheNahodne] < najmensieCislo) {
		najmensieCislo = poleCisel[druheNahodne];
	}

	if (poleCisel[tretieNahodne] < najmensieCislo) {
		najmensieCislo = poleCisel[tretieNahodne];
	}

	cout << "Najmensie cislo: " << najmensieCislo << endl;
	return najmensieCislo;
}
