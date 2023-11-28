#pragma once
#include <string>

using namespace std;

class SuborPraca
{
private:
	string nazovSuboru;
public:
	SuborPraca(string nazov);
	~SuborPraca() = default;
	void zapisDoSuboru(const char* retazec);
	void doplnDoSuboru(const char* retazec);
	void vypisOdIntervalu(int prvy, int druhy);
	string vypisKonkretneSlovoRiadku(int poradieSlova, int poradieRiadku);
	void vypisSubor();
};

