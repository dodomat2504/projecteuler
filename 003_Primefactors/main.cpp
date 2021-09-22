#include <iostream>


/// @brief Checks if a given Number is Prime
bool isPrime(const long long i) {
    if (i <= 0) return false;
    if (i % 2 == 0) {
        if (i == 2) return true;
        return false;
    } else {
        if (i == 1) return true;

        long long counter = 3;
        while (counter <= i/3) {
            if (i % counter == 0) return false;
            counter += 2;
        }
        return true;
    }
}


int main() {

    const long long numberToProcess = 600851475143;
    long long rest = numberToProcess;

    while (!isPrime(rest)) {

        int nextPrimefactor = 2;
        while (nextPrimefactor < rest/2) {
            if (rest % nextPrimefactor == 0 && isPrime(nextPrimefactor)) {
                break;
            } else {
                nextPrimefactor++;
            }
        }

        rest /= nextPrimefactor;
    }

    std::cout << "Highest Primefactor: " << rest << std::endl;

    return 0;
}
