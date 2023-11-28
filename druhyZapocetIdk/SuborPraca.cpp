#include "SuborPraca.h"
#include <fstream>
#include <iostream>


SuborPraca::SuborPraca(string nazov)
{
	this->nazovSuboru = nazov;
}


/*
	Prepise cely subor a dosadi do neho novy retazec
*/
void SuborPraca::zapisDoSuboru(const char* retazec)
{
	ofstream zapisovac(this->nazovSuboru);
	if (zapisovac.is_open())
	{
		zapisovac << retazec << endl;
		zapisovac.close();
	}
}


/*
	Zoberie retazec a ten zapise na koniec suboru
	parameter musi byt ako const inak nepojde cez main
*/
void SuborPraca::doplnDoSuboru(const char* retazec)
{
	ofstream zapisovac(this->nazovSuboru, ios_base::app); //ios_base::app bude zapisovat na koniec (mod)
	if (zapisovac.is_open())
	{
		zapisovac << retazec << endl;
		zapisovac.close();
	}
}


/*
	Vypise riadky od jedneho intervalu po druhy
*/
void SuborPraca::vypisOdIntervalu(int prvy, int druhy)
{
	ifstream citac(nazovSuboru);
	if (prvy <= druhy) {
		int poradie{1};
		string riadok;

		while (citac.is_open()) {
			getline(citac, riadok);

			if (poradie >= prvy && poradie <= druhy) {
				cout << riadok << endl;
			}
			else if (poradie > druhy) {
				break;
			}


			poradie++;
		}

		citac.close();
	}
	else {
		cout << "druhy interval je vacsie alebo rovny prvemu" << endl;
	}
}


/*
	V subore sa nachdadza riadok nasledovne:
		Meno Priezvisko Vek Plat
	Metoda vypise podla poradina riadku (predstavme si poradie ludi)
	a podla poradia slova (1 = meno, 2 = priezvisko...)

	najprv si zo suboru zapise konkretny riadok a ten rozdeli do pola

*/
string SuborPraca::vypisKonkretneSlovoRiadku(int poradieSlova, int poradieRiadku)
{

	ifstream citac(this->nazovSuboru);
	string riadok;
	if (citac.is_open())
	{
		int poradie{ 1 };
		while (getline(citac, riadok))
		{
			if (poradie == poradieRiadku)
			{
				citac.close();
				break; 
			}
			poradie++;
		}

		citac.close();
	}

	string hladaneSlovo;
	int poradieHladaneho{ 1 };

	for (int i = 0; i < (int)riadok.length() + 1; i++)
	{
		if (i == (int)riadok.length() && !hladaneSlovo.empty())
		{
			return hladaneSlovo;
		}

		if (riadok[i] != ' ')
		{
			hladaneSlovo += riadok[i];
		}
		else
		{
			if (poradieHladaneho == poradieSlova)
			{
				return hladaneSlovo;
			}
			hladaneSlovo = "";

			poradieHladaneho++;
		}
	}

	return "";
}



/*
	Metoda vypise cely subor s tym ze bude pracovat s riadkami
	nie s pisenami
*/
void SuborPraca::vypisSubor()
{
	ifstream citac(this->nazovSuboru);
	if (citac.is_open()) 
	{
		string riadok;
		while (getline(citac, riadok))
		{
			cout << riadok << endl;
		}

		citac.close();
	}
}
