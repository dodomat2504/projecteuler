#include <iostream>
#include "../string_math.h"
#include <set>
#include <ctime>


int main() {
    std::set<Number> s;

    const clock_t start = clock();

    for (int a = 2; a <= 100; a++) {
        for (int b = 2; b <= 100; b++) {
            const Number n = Number::pow(a, b);
            s.insert(n);
        }
    }

    const clock_t end = clock();

    std::cout << "Laufzeit: " << (end-start)*1000 / CLOCKS_PER_SEC << "ms" << std::endl;

    std::cout << "Size: " << s.size() << std::endl;

    return 0;
}