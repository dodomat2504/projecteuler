#include <iostream>
#include <cmath>

static bool isPrime(const int n) {
    if (n % 2 == 0 || n < 2) return false;
    for (int i = 3; i <= n/2; i+=2) if (n % i == 0) return false;
    return true;
}

static int f(const int n, const int a, const int b) { return n*n + a*n + b; }

static int consecutivePrimes(const int a, const int b) {
    int n = 1;
    while (isPrime(f(n, a, b))) n++;
    return n-1;
}


int main() {

    // Formula: prime = n*n + a*n + b, with -1000 < a < 1000 and -1000 <= b <= 1000

    int longestChain = 0;
    int longest_a = 187, longest_b = 187;

    for (int a = -999; a < 1000; a++) {
        for (int b = -1000; b <= 1000; b++) {
            const int consPrimes = consecutivePrimes(a, b);
            if (consPrimes > longestChain) {
                longestChain = consPrimes;
                longest_a = a;
                longest_b = b;
            }
        }
        if (a % 20) std::cout << "Finished " << (a+999)/10.0 << "%" << std::endl;
    }

    std::cout << "Prod: " << longest_a*longest_b << std::endl;

    return 0;
}