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

static int indexOf(const std::vector<int>& vec, const int data) {
    for (int i = 0; i < vec.size(); i++) if (vec[i] == data) return i;
    return -1;
}

int lengthOfReciprocalCycleOf(const int n) {
    int dividend = 1;
    std::vector<int> dividends;
    int length = 0;

    while (true) {
        const int r = dividend - ((int) dividend/n) * n;

        if (r == 0) break;

        dividend = 10*r;
        const int indexOfDividendInVector = indexOf(dividends, dividend);

        if (indexOfDividendInVector != -1) {
            length = dividends.size() - indexOfDividendInVector;
            break;
        } else dividends.push_back(dividend);
    }

    return length;
}
