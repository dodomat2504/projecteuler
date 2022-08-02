#include <iostream>
#include <ctime>


int main() {

    int sum = 1;

    const clock_t start = clock();

    for (int width = 3; width <= 1001; width+=2) {
        sum += 4 * (width*width - 1.5*(width-1));
    }

    const clock_t end = clock();

    std::cout << "Laufzeit: " << (end-start)*1000000 / CLOCKS_PER_SEC << "ns" << std::endl;

    std::cout << "Sum: " << sum << std::endl;

    return 0;
}