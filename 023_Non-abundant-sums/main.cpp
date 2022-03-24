#include <iostream>
#include <vector>
#include "../dmath.h"

const int Grenze = 28123;

static int binSearch(std::vector<int>& vec, const int value, const int l, const int r) {
    if (r == l) return -1;
    const int mid = (l+r)/2;
    if (vec[mid] == value) return mid;
    if (vec[mid] < value) return binSearch(vec, value, mid+1, r);
    if (vec[mid] > value) return binSearch(vec, value, l, mid);
    return -1;
}

static void binInsert(std::vector<int>& vec, const int value) {
    int l = 0, r = vec.size();
    if (r == l) { vec.push_back(value); return; }

    while (true) {
        const int mid = (l+r)/2;
        if (vec[mid] == value) break;

        if (r == l) {
            vec.insert(vec.begin()+mid, value);
            break;
        } else if (vec[mid] < value) {
            l = mid+1;
        } else {
            r = mid;
        }
    }
}

/// @brief Requires a sorted vector
static bool contains(std::vector<int>& vec, const int data) { return binSearch(vec, data, 0, vec.size()) != -1; }


int main() {
    std::vector<int> abundandNumbers;

    for (int i = 1; i < Grenze; i++) {
        const int sumOfDivs = sumOfDivisors(i);
        if (sumOfDivs > i) abundandNumbers.push_back(i);
    }

    std::vector<int> sumsOfAbundandNumbers;

    for (int i = 0; i < abundandNumbers.size(); i++) {
        const int summ1 = abundandNumbers[i];
        for (int j = i; j < abundandNumbers.size(); j++) {
            const int summ2 = abundandNumbers[j];
            const int sum = summ1 + summ2;
            if (sum > Grenze) break;
            binInsert(sumsOfAbundandNumbers, sum);
        }
    }

    long sum = 0;

    for (int i = 1; i <= Grenze; i++) if (!contains(sumsOfAbundandNumbers, i)) sum += i;

    std::cout << "Sum: " << sum << std::endl;

    return 0;
}
