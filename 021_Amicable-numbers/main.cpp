#include <iostream>


static int d(const int n) {
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
            counter++;
        }
        if (n / smallestDivisor == counter && n != counter) sumOfDivisors+=counter;
    }

    return sumOfDivisors;
}

static bool isAmicable(const int n) { return (d(d(n)) == n); }

static int AmicableOf(const int n) { if (isAmicable(n)) return d(n); else return -1; }

const int Grenze = 10000;

int main() {
    long sum = 0;
    bool alreadyUsed[Grenze];
    for (int i = 0; i < Grenze; i++) alreadyUsed[i] = false;

    for (int i = 2; i < Grenze; i++) {
        if (alreadyUsed[i]) continue;
        
        if (isAmicable(i)) {
            const long ami = AmicableOf(i);
            if (i == ami) continue;
            sum += i;
            sum += ami;
            if (ami < Grenze) alreadyUsed[ami] = true;
        }
    }

    std::cout << "Sum: " << sum << std::endl;
    
    return 0;
}
