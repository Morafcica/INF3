#include <iostream>
#include "Pole.h"
#include "SuborVeci.h"

using namespace std;


void vypis();


int main()
{
    
    Pole pole(4, 100);

    cout << "Najvacsie cislo je " << pole.vypisNajvacsie() << endl;
    cout << "Najmensie cislo je " << pole.vypisNajmensie() << endl;


    SuborVeci suborVeci("subor.txt");
    suborVeci.zapisDoSuboru(44);
    suborVeci.vypisCelySubor();

    cout << "------------------------------------------------------------" << endl;


    suborVeci.vypisOdIntervalu(3, 6);

    return 0;
}
