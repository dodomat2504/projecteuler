#include <iostream>


static int anzTeiler(const long long num) {
    int anz = 1; // 1, weil num % num == 0
    for (long i = 1; i*2 <= num; i++) {
        if (num % i == 0) anz++;
    }
    return anz;
}

int main() {
    int maxCounter = 0;
    long long num = 0;
    long wdh = 1;

    while (maxCounter <= 500) {
        num += wdh++;

        const int anz = anzTeiler(num);
        if (anz > maxCounter) {
            maxCounter = anz;
            std::cout << "newmax: " << maxCounter << " at " << num << std::endl;
        }
    }

    std::cout << "Found: über 500 Teiler at " << num << std::endl;

    return 0;
}
