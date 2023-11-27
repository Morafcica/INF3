
#include <iostream>
#include "SuborPraca.h"
#include "Hrac.h"

int main(int argc, char* argv[])
{
    Hrac h1("Martin", "Fakan", 5, 3);
    Hrac h2("Fekete", "Pepe", 17, 4);
    Hrac h3("Estenem", "Lsgan", 2, 7);


    h1.vygenerujMinuty();
    h2.vygenerujMinuty();
    h3.vygenerujMinuty();

    h1.zapisDoSuboru();
    h2.zapisDoSuboru();
    h3.zapisDoSuboru();



    return 0;
}