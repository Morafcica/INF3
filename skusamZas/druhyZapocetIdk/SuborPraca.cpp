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
void SuborPraca::vypisKonkretneSlovoRiadku(int poradieSlova, int poradieRiadku)
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
				citac >> riadok;	//tu si zoberie riadok vo formate "Meno Priezvisko Vek Plat"
			}
		}

		citac.close();
	}

	const char* riadokVPoli = riadok.c_str(); //museli sme pretypovat

	char* inputCopy = new char[strlen(riadokVPoli) + 1]; //dymamicka alokacia (lebo new) potom treba vymazat
	strcpy(inputCopy, riadokVPoli); //vlozi riadok do pola

	const char* delimiter = " ";
	const char* token = strtok(inputCopy, delimiter); //funguje podobne ako funkcia split()

	int poradie{ 1 };
	while (token != nullptr) {
		if (poradie == poradieSlova) { //vyberie konkretny prvok pola
			cout << token << endl;
		}

		token = strtok(nullptr, delimiter); //netusim ako toto funguje, ma v sebe vzdy len 1 prvok ktory sa meni??????
		poradie++;
	}

	delete[] inputCopy;
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
