#include <iostream>

static int NextPrime(const bool* arr, const int length, const int i) {
    for (int j = i+1; j < length; j++) if (arr[j]) return j;
    return -1;
}

static int find(const int* arr, const int l, const int r, const int data) {
    // Binary Search
    const int mid = (l+r)/2;
    if (arr[mid] == data) return mid;
    if (r == l) return -1;
    if (arr[mid] < data) return find(arr, mid + 1, r, data);
    if (arr[mid] > data) return find(arr, l, mid, data);
    return -1;
}

static bool contains(const int* arr, const int length, const int data) { return find(arr, 0, length-1, data) != -1; }

int rotate(const int n) {
    std::string num = std::to_string(n);
    const char save = num[num.length()-1];
    for (int i = num.length()-1; i > 0; i--) {
        num[i%num.length()] = num[(i-1)%num.length()];// 123
    }
    num[0] = save;
    return std::stoi(num);
}


int main() {

    const int grenze = 1000000;
    bool* siebchen = new bool[grenze];
    int primeCounter = 0;

    siebchen[0] = false;
    for (int i = 1; i < grenze; i++) siebchen[i] = true;

    for (int i = 0; i < grenze; i++) {
        const int n = i+1;
        if (siebchen[i]) {
            for (int j = i+n; j < grenze; j+=n) siebchen[j] = false;
            primeCounter++;
        }
    }
    
    int primes[primeCounter];
    primes[0] = 2;

    int lastPrimeIndex = 1;
    for (int i = 1; i < primeCounter; i++) {
        lastPrimeIndex = NextPrime(siebchen, grenze, lastPrimeIndex);
        primes[i] = lastPrimeIndex+1;
    }
    
    delete [] siebchen;

    int counter = 0;

    for (int primeI = 0; primeI < primeCounter; primeI++) {
        const int numLength = std::to_string(primes[primeI]).length();
        if (numLength > 1) {
            int zwNum = primes[primeI];
            bool foundShit = false;
            for (int i = 1; i < numLength; i++) {
                const int rotated = rotate(zwNum);
                if (!contains(primes, primeCounter, rotated)) break;
                zwNum = rotated;
                if (i + 1 == numLength) foundShit = true;
            }
            if (foundShit) counter++;
        } else counter++;
    }

    std::cout << "Counter: " << counter << std::endl;

    return 0;
}
