
#include <iostream>
#include "MemLeak.h" 
#include "Skupina.h"
#include "Student.h"
int main() {
    Skupina skupina;
    Student s1("Janko", "Mrkvicka", 12);
    Student s2("Jozko", "Mrkvicka", 12);
    Student s3("Ferko", "Mrkvicka", 11);
    skupina.Pridaj(s1);
    skupina.Pridaj(s2);
    skupina.Pridaj(s3);
    skupina.InfoSkupina();
    
    skupina.Vyluc(13);
    std::cout << "\nPo vyluceni:\n";
    skupina.InfoSkupina();


    //_CrtDumpMemoryLeaks();

    return 0;
}

