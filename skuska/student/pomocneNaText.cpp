#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include "MemoryLeak.h"

using namespace std;

//mame napriklad slovo ahoj
// toto ho vypise ako
// a
// h
// o
// j
void vypisSlovoPoPismenach(const std::string& infix)
{
    for (auto c : infix)
        cout << c << endl;
}

/*
* Mame napriklad 22.11.2023
* tak vypise 22 11 2023 vzdy do noveho riadka
*/
void vypisSlovaPodlaDelimitera(string slovo, char delimiter)
{
    istringstream stream(slovo);
    string cast;

    while (getline(stream, cast, delimiter)) {
        cout << "Cast: " << cast << endl;
    }
}


int main() {
    std::string veta = "22.11.2023";

    vypisSlovaPodlaDelimitera(veta, '.');

    return 0;
}

