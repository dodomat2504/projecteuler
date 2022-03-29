#include <iostream>
#include "../string_math.h"


int main() {
    Number prev2(1);
    Number prev1(1);
    int counter = 3;

    while ((prev1 + prev2).toString().length() < 1000) {
        const Number zw = prev1 + prev2;
        prev2 = prev1;
        prev1 = zw;
        counter++;
    }

    std::cout << "Index: " << counter << std::endl;

    return 0;
}