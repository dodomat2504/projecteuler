#include <iostream>


int main() {

    long numWithLongestChain = 0, longestChain = 0;

    for (long i = 1; i < 1000000; i++) {
        long counter = 0;

        long long N = i;
        while (N != 1) {
            if (N % 2 == 0) N /= 2;
            else N = 3*N + 1;

            counter++;
        }
        if (counter > longestChain) {
            longestChain = counter;
            numWithLongestChain = i;
        }
    }

    std::cout << "Num: " << numWithLongestChain << std::endl;

    return 0;
}
