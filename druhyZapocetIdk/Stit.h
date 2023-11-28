#pragma once
#include <string>
#include <iostream>

using namespace std;

class Stit
{
private:
	char* menoStitu = nullptr;
	int nadmorska_vyska = 0;

public:
	Stit(const char* pmenoStitu=nullptr, int pnadmorskaVyska = 0) : nadmorska_vyska(pnadmorskaVyska) {
		if (pmenoStitu) {
			menoStitu = new char[strlen(pmenoStitu) + 1];
			strcpy(menoStitu, pmenoStitu);
		}
	}
	Stit(int pnadmorskaVyska) : nadmorska_vyska(pnadmorskaVyska) {}
	Stit(const Stit& zdroj) {
		if (zdroj.menoStitu) {
			menoStitu = new char[strlen(zdroj.menoStitu) + 1];
			strcpy(menoStitu, zdroj.menoStitu);
		}
		nadmorska_vyska = zdroj.nadmorska_vyska;
	}
	Stit& operator=(const Stit& zdroj) {
		if (this != &zdroj) {
			if (menoStitu) {
				delete[] menoStitu;
			}
			if (zdroj.menoStitu) {
				menoStitu = new char[strlen(zdroj.menoStitu) + 1];
				strcpy(menoStitu, zdroj.menoStitu);
			}
			nadmorska_vyska = zdroj.nadmorska_vyska;
		}
		return *this;
	}
	~Stit() {
		delete[] menoStitu;
		menoStitu = nullptr;
	}
	void vypis() {
		if (menoStitu) {
			cout << menoStitu << " " << nadmorska_vyska << endl;
		}
		else {
			cout << "Nie je stit." << endl;
		}
	}
};

