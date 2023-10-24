#pragma once
#include <string>
class NacitanieSuboru
{
	private:
		std::string nazovSuboru;
		int* poleCisel;
		int pocetPrvkovPola;

	public:
		NacitanieSuboru(std::string nazovSuboru);
		~NacitanieSuboru();
		void nacitaj();
		int vypisNajmensie();
};

