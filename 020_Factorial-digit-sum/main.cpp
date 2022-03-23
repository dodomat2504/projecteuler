#include <iostream>
#include "../string_math.h"


int main() {
    Number factorialOfHundret("1");

    for (int i = 1; i <= 100; i++) {
        Number factor(std::to_string(i));
        factorialOfHundret *= factor;
    }

    int sum = 0;
    for (char c : factorialOfHundret.toString()) sum += std::stoi(std::to_string(c))-48;

    std::cout << "Sum: " << sum << std::endl;

    return 0;
}
