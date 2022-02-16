#include <iostream>
#include "../string_math.h"

const int ASCII = 48;
const int exponent = 1000;

int main() {
    Number n("1");
    const Number m("2");

    for (int i = 0; i < exponent; i++) n *= m;

    int sum = 0;
    const std::string str = n.toString();

    for (int i = 0; i < str.length(); i++) sum += str[i] - ASCII;

    std::cout << "Summe: " << sum << std::endl;

    return 0;
}
