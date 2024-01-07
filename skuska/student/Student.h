
#pragma once
#include <iostream>

 class Student {
    private:
        char* Meno;
        char* Priezvisko;
        int ID;

    public:
        Student(const char* meno, const char* priezvisko, int id); //konverzny
        Student(const Student& other);  // Kopírovací konstruktor
        ~Student();                     // Destruktor
        Student& operator=(const Student& other);  // Operátor priradenia
        int getID() const;
        void Info() const;
    };

