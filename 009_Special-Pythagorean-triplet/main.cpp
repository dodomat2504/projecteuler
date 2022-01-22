#include <iostream>

const int AMin = 50;
const int AMax = 400;

const int BMin = 50;
const int BMax = 400;

const int CMin = 280;
const int CMax = 900;


int main() {

    for (int a = AMin; a <= AMax; a++) {
        if (a % ((AMax-AMin)/10) == 0) std::cout << "Weitere 10% getestet" << std::endl;
        for (int b = BMin; b <= BMax; b++) {
            for (int c = CMin; c <= CMax; c++) {
                // if (c == CMin) std::cout << "a=" << a << "b=" << b << "c=" << c << "\n";
                const int leftside = a*a + b*b;
                const int rightside = c*c;
                const int sum = a+b+c;

                if (leftside == rightside && sum==1000) {
                    std::cout << "Erg: a: " << a << " b: " << b << " c: " << c << std::endl;
                    std::cout << "Product: " << a*b*c << std::endl;
                    return 0;
                }
            }
        }
    }
    std::cerr << "Nix gefunden!" << std::endl;

    return 1;
}
