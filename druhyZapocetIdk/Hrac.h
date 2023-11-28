#pragma once
#include <string>

using namespace std;

class Hrac
{
private:
	string meno;
	string priezvisko;
	int pocetZapasov;
	int pocetZltychKariet;
	int* odohranyCas;
public:
	Hrac() = default;
	Hrac(string aMeno, string aPriezvisko, int aPocetZapasov, int aPocetZltychKariet)
		: meno(aMeno), priezvisko(aPriezvisko), pocetZapasov(aPocetZapasov), pocetZltychKariet(aPocetZltychKariet), odohranyCas(nullptr) {}
	~Hrac() 
	{
		delete[] odohranyCas;
		odohranyCas = nullptr;
	}
	int getOdohrateMinuty();
	double getUzitocnostHraca();
	void vygenerujMinuty();
	void zapisDoSuboru();
};

