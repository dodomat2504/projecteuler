#include "dmath.h"
#include <vector>


int sumOfDivisors(const int n) {
    int sumOfDivisors = 0;

    if (n % 2 == 0) {
        for (int i = 1; i <= n/2; i++) if (n % i == 0) sumOfDivisors+=i;
    } else {
        int smallestDivisor = -1;
        int counter = 1;

        while ((smallestDivisor == -1 || n / smallestDivisor != counter) && counter < n) {
            if (n % counter == 0) {
                sumOfDivisors+=counter;
                if (smallestDivisor == -1) smallestDivisor = counter;
            }
            counter+=2;
        }
        if (n / smallestDivisor == counter && n != counter) sumOfDivisors+=counter;
    }

    return sumOfDivisors;
}

int longestReciprocalCycle(const int divisor) {
    int dividend = 1;
    bool found = false;

    std::vector<int> dividends;
    dividends.push_back(dividend);
    

    while (!found) {

        // TODO

    }
}
