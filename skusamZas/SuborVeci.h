#pragma once
#include <string>


class SuborVeci
{
	private:
		std::string nazovSuboru;
	public:
		SuborVeci(std::string nazovSuborul);
		~SuborVeci();
		void vypisOdIntervalu(int prvy, int druhy);
		void zapisDoSuboru(int cislo);
		void vypisCelySubor();

};

