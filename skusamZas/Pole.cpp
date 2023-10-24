#include "Pole.h"
#include <stdlib.h>
#include <ctime>

Pole::Pole(int aPocetPrvkov, int aRozsahHodnot)
{
	pocetPrvkov = aPocetPrvkov;
	rozsahHodnot = aRozsahHodnot;
	pole = new int[pocetPrvkov];

	srand(static_cast<unsigned>(time(0))); //totog vypise random random cislo bo c++ si inicializuje jedny random cisla ???????????

	for (int i = 0; i < pocetPrvkov; i++) 
	{
		int nahodneCislo = (rand() % (rozsahHodnot + rozsahHodnot)) - aRozsahHodnot;
		pole[i] = nahodneCislo;
	}

}

Pole::~Pole()
{

}

int Pole::vypisNajvacsie()
{
	int aktualneNajvyssie = rozsahHodnot - rozsahHodnot * 2;
	for (int i = 0; i < pocetPrvkov; i++) 
	{
		if (pole[i] > aktualneNajvyssie)
		{
			aktualneNajvyssie = pole[i];
		}
	}

	return aktualneNajvyssie;
}

int Pole::vypisNajmensie()
{
	int aktualneNajmensie = rozsahHodnot;
	for (int i = 0; i < pocetPrvkov; i++)
	{
		if (pole[i] < aktualneNajmensie)
		{
			aktualneNajmensie = pole[i];
		}
	}

	return aktualneNajmensie;
}
