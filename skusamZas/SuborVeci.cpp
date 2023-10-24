#include "SuborVeci.h"
#include <iostream>
#include <fstream> 


using namespace std;

SuborVeci::SuborVeci(string nazovSuboru) {
    this->nazovSuboru = nazovSuboru;
}

SuborVeci::~SuborVeci() {

}

void SuborVeci::vypisOdIntervalu(int prvy, int druhy) {
    if (prvy <= druhy) {
        ifstream subor(nazovSuboru);
        if (subor.is_open()) {
            int cislo;
            int pozicia = 1;
            while (subor >> cislo) {
                if (pozicia >= prvy && pozicia <= druhy) {
                    cout << cislo << endl;
                }
                if (pozicia >= druhy) {
                    break;
                }
                pozicia++;
            }
            subor.close();
        }
        else {
            cout << "daco se doebalo" << endl;
        }
    }
    else {
        cout << "daco se doebalo" << endl;
    }
}

void SuborVeci::zapisDoSuboru(int cislo) {
    ofstream subor(nazovSuboru, ios::app); // ios::app piseme na koniec suboru bo by sa cely prepisal
    if (subor.is_open()) {
        subor << cislo << endl;
        subor.close();
    }
    else {
        cout << "daco se doebalo" << endl;
    }
}

void SuborVeci::vypisCelySubor() {
    ifstream subor(nazovSuboru);
    if (subor.is_open()) {
        int cislo;
        while (subor >> cislo) {
            cout << cislo << endl;
        }
        subor.close();
    }
    else {
        cout << "daco se doebalo" << endl;
    }
}