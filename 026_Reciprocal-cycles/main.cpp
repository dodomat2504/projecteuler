#include <iostream>
#include "../dmath.h"
#include <ctime>


int main() {

    int biggestD = -1, biggestDValue = 0;

    const clock_t start = clock();

    for (int d = 2; d < 1000; d++) {

        const int len = lengthOfReciprocalCycleOf(d);
        if (len > biggestDValue) {
            biggestDValue = len;
            biggestD = d;
        }

    }

    const clock_t end = clock();

    std::cout << "Laufzeit: " << (end-start)*1000 / CLOCKS_PER_SEC << "ms" << std::endl;

    std::cout << biggestD << " has the biggest value with: " << biggestDValue << std::endl;

    return 0;
}