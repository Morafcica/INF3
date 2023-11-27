#include "Hrac.h"
#include <ctime>
#include "SuborPraca.h"

int Hrac::getOdohrateMinuty()
{
	int odohrateMinuty{ 0 };

	for (int i = 0; i < pocetZapasov; i++) {
		odohrateMinuty += odohranyCas[i];
	}


	return odohrateMinuty;
}

double Hrac::getUzitocnostHraca()
{

	return (double)(getOdohrateMinuty() / pocetZapasov / pocetZltychKariet);
}

void Hrac::vygenerujMinuty()
{
	if (odohranyCas == nullptr) 
	{
		odohranyCas = new int[pocetZapasov];
	}

	srand(static_cast<unsigned>(time(0)));


	for (int i = 0; i < pocetZapasov; i++) 
	{
		int nahodneCislo = (rand() % 48) + 2;
		odohranyCas[i] = nahodneCislo;
	}
}

void Hrac::zapisDoSuboru()
{
	SuborPraca sp("subor.txt");


	string celyRetazec;

	celyRetazec.append(meno + " ");
	celyRetazec.append(priezvisko + " ");
	celyRetazec.append("<" + to_string(pocetZltychKariet) + "> ");
	celyRetazec.append(to_string(getOdohrateMinuty()) + " ");
	celyRetazec.append("[" + to_string(pocetZapasov) + "] - ");

	for (int i = 0; i < pocetZapasov; i++)
	{
		celyRetazec.append(to_string(odohranyCas[i]) + " ");
	}

	sp.doplnDoSuboru(celyRetazec.c_str());


}
