#pragma once
class Pole
{
	private:
		int* pole;
		int pocetPrvkov;
		int rozsahHodnot;
	public:
		Pole(int aPocetPrvkov, int aRozsahHodnot);
		~Pole();
		int vypisNajvacsie();
		int vypisNajmensie();
};

