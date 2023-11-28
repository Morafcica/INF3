
#include <iostream>
#include <algorithm> // Include the <algorithm> header for std::sort
#include "SuborPraca.h"
#include "Hrac.h"
#include <vector>

bool nachadzaSaVZozname(int* pole, int prvok);

int main(int argc, char* argv[])
{   
    srand(static_cast<unsigned>(time(0)));
    SuborPraca sp("subor.txt");

    Hrac* zoznamHracov = new Hrac[5];

    for (int riadok = 1; riadok <= 5; riadok++) 
    {
        string meno{};
        string priezvisko{};
        int pocetZapasov{};
        int pocetZltych{};

        for (int slovo = 1; slovo <= 4; slovo++)
        {


            switch (slovo)
            {
            case 1:
                meno = sp.vypisKonkretneSlovoRiadku(slovo, riadok);
                break;
            case 2:
                priezvisko = sp.vypisKonkretneSlovoRiadku(slovo, riadok);
                break;
            case 3:
                pocetZapasov = stoi(sp.vypisKonkretneSlovoRiadku(slovo, riadok));
                break;
            case 4:
                pocetZltych = stoi(sp.vypisKonkretneSlovoRiadku(slovo, riadok));
                break;
            default:
                break;
            }

        }

        zoznamHracov[riadok - 1] = Hrac(meno, priezvisko, pocetZapasov, pocetZltych);
    }

    for (int i = 0; i < 5; i++)
    {
        zoznamHracov[i].vygenerujMinuty();
    }

    Hrac* pomocnyZoznam = new Hrac[5];
    int* zoznamVybranychCisel = new int[4];

    int poradieZoznamu{ 0 };
    while (true)
    {
        int najvyssieCislo{ 0 };

        for (int i = 0; i < 4; i++)
        {
            if (zoznamHracov[i].getUzitocnostHraca() < zoznamHracov[i + 1].getUzitocnostHraca())
            {
                najvyssieCislo = zoznamHracov[i + 1].getUzitocnostHraca();
            }

          
        }

        for (int i = 0; i < 4; i++)
        {
            for (int j = i + 1; j < 4; j++)
            {
                if (zoznamHracov[i].getUzitocnostHraca() < zoznamHracov[j].getUzitocnostHraca())
                {
                    if (!nachadzaSaVZozname(zoznamVybranychCisel, j))
                    {
                        najvyssieCislo = j;
                    }
                }
            }

            zoznamVybranychCisel[i] = najvyssieCislo;
        }

        for (int i = 0; i < 5; i++)
        {
            pomocnyZoznam[i] = zoznamHracov[zoznamVybranychCisel[i]];
        }

        break;
        
    }

    for (int i = 0; i < 5; i++) 
    {
        pomocnyZoznam[i].zapisDoSuboru();
    }


    delete[] zoznamHracov;
    delete[] pomocnyZoznam;
    delete[] zoznamVybranychCisel;

    return 0;
}

bool nachadzaSaVZozname(int* pole, int cislo)
{
    for (int i = 0; i < 5; i++)
    {
        if (pole[i] == cislo)
        {
            return true;
        }
    }

    return false;
}