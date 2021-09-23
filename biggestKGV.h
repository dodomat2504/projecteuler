#ifndef IMPORTS_H
#define IMPORTS_H

#include <iostream>

static int ggT(const int n, const int m) {
    if (n <= 0 || m <= 0) throw std::invalid_argument("The numbers have to be bigger than 0!");
    if (n == m) return n;
    else if (n < m) return m % n == 0 ? n : ggT(n, m % n);
    else return n % m == 0 ? m :ggT(n % m, m);
}

static int kgv(const int n, const int m) { return (n * m) / ggT(n, m); }

/// @brief Calculates the biggest KGV of a range of numbers in O(n^2)
int biggestKGV(const int start, const int end) {
    int biggest = 0;

    for (int f1 = start; f1 <= end; f1++)
        for (int f2 = start; f2 <= end; f2++)
            if (f1 * f2 > biggest) biggest = f1 * f2;

    return biggest;
}


#endif // IMPORTS_H
