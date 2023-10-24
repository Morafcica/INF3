
#include <iostream>
#include "NacitanieSuboru.h"

int main(int argc, char* argv[])
{
    //NacitanieSuboru ns(argv[1]);
    NacitanieSuboru ns("../subor.txt");
    ns.nacitaj();
    std::cout << ns.vypisNajmensie() << std::endl;
}

