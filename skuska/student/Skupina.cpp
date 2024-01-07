#include "Skupina.h"
using namespace std;

Skupina::Skupina()
{
    pocetStudentov = 0;
    studenti = new Student * [3]; // 

}

Skupina::~Skupina()
{
    for (int i = 0; i < pocetStudentov; i++)
    {
        delete studenti[i];
    }
    delete[] studenti;
}

void Skupina::InfoSkupina()
{
    for (int i = 0; i < pocetStudentov; i++)
    {
        studenti[i]->Info();
    }
}
bool Skupina::nachadzaSa(int id)
{
    for (int i = 0; i < pocetStudentov; i++)
    {
        if (studenti[i]->getID() == id) {
            return true;
            
        }
    }
    return false;
}


void Skupina::Pridaj(const Student& novy)
{
    if (!nachadzaSa((novy.getID()))) {
        if (pocetStudentov >= 3) {
            Student** novePole = new Student * [pocetStudentov];
            for (int i = 0; i < pocetStudentov; i++) {
                novePole[i] = studenti[i];
            }
            delete[] studenti;
            studenti = novePole;
        }
        studenti[pocetStudentov] = new Student(novy); // Vytvorenie kópie študenta
        pocetStudentov++;
    }
    else {
        cout << "Student s danym ID uz existuje" << endl;
    }
}

void Skupina::Vyluc(int idVyluc)
{
    for (int i = 0; i < pocetStudentov; ++i) {
        //studenti[i].getID() == vyluceny.getID()
        if (studenti[i]->getID() == idVyluc) {
            delete studenti[i]; // Uvo¾nenie pamäte 
            // Presun posledneho studenta
            studenti[i] = studenti[pocetStudentov - 1];

            studenti[pocetStudentov - 1] = nullptr; 
            pocetStudentov--; 
            break; 

        }

    }
}