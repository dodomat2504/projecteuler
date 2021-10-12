#include <iostream>
#include <cmath>


static bool isPrime(const unsigned long p) {
    if (p < 2) return false;
    if (p % 2 == 0 && p != 2) return false;
    unsigned short summand = 1;
    for (int div = 2; div <= (int) sqrt(p); div+=summand) {
        if (p % div == 0) return false;
    }
    return true;
}

/// @returns the next Prime number
static unsigned long NextPrime(const unsigned long p) {
    unsigned long nmb = p + 1;
    unsigned short summand = 1;
    if (nmb % 2 == 0 && nmb != 2) { nmb++; summand = 2; }
    while (!isPrime(nmb)) { nmb += summand; }
    return nmb;
}


const unsigned long FIRST_PRIME = 2;

int main() {

    unsigned long p = FIRST_PRIME;

    // after 10.000 times NextPrime: p == the 10.001th prime
    for (int i = 0; i < 10000; i++) { p = NextPrime(p); }

    std::cout << "10.001th Prime: " << p << std::endl;

    return 0;
}
