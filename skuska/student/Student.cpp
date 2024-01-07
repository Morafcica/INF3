#include "Student.h"
#include <cstring>

using namespace std;
Student::Student(const char* meno, const char* priezvisko, int id) {

    if (meno && *meno) { //kontrola vstupu
        Meno = new char[strlen(meno) + 1];
        strcpy(Meno, meno);
    }
    else {
        Meno = nullptr;
    }
    if (priezvisko && *priezvisko) {
        Priezvisko = new char[strlen(priezvisko) + 1];
        strcpy(Priezvisko, priezvisko);
    } 
    else {
        Priezvisko = nullptr;
    }
    ID = id;
    
}

// Kopírovací konstruktor
Student::Student(const Student& other) {
    ID = other.ID;

    Meno = new char[strlen(other.Meno) + 1];
    strcpy(Meno, other.Meno);

    Priezvisko = new char[strlen(other.Priezvisko) + 1];
    strcpy(Priezvisko, other.Priezvisko);
}

// Destruktor
Student::~Student() {
    delete[] Meno;
    delete[] Priezvisko;
}

// Operátor priradenia
Student& Student::operator=(const Student& other) {
    if (this != &other) {
        delete[] Meno;
        delete[] Priezvisko;

        ID = other.ID;
        Meno = new char[strlen(other.Meno) + 1];
        strcpy(Meno, other.Meno);

        Priezvisko = new char[strlen(other.Priezvisko) + 1];
        strcpy(Priezvisko, other.Priezvisko);
    }
    return *this;
}

int Student::getID() const
{
    return ID;
}

void Student::Info() const {
    cout << "priezvisko studenta: " << Priezvisko << "\n";
    cout << "meno studenta:       " << Meno << "\n";
    cout << "ID studenta:         " << ID << "\n";
}
