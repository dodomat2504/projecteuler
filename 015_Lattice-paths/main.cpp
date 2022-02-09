#include <iostream>
#include "pascalscherdiamant.h"


int main() {
    int n;
    std::cin >> n;


    PascalscherDiamant p(n);

    std::cout << "Ergebnis: " << p.Ergebnis() << std::endl;

    return 0;
}
