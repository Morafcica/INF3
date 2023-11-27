#pragma once
#include <string>


using namespace std;

class Zamestnanec
{

private:
	string meno;
	string priezvisko;
	int pocetOdpracovanychDni;
	int* odpracovaneHodiny;
	double platZaHodinu;
public:
	Zamestnanec(string priez, string meno, int pocetDni, double plat)
		: priezvisko(priez), meno(meno), pocetOdpracovanychDni(pocetDni), platZaHodinu(plat), odpracovaneHodiny(nullptr) {}
	~Zamestnanec() { delete[] odpracovaneHodiny; };
	void vygenerujPocetOdpracovanychHodin();
	void pridajKoeficientPriplatku(double priplatok);
};

