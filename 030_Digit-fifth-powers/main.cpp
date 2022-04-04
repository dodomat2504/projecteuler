#include <iostream>
#include <cmath>
#include <ctime>

bool usable(const int n, const int power = 5) {
    const std::string n_str = std::to_string(n);
    int sumOfPowers = 0;
    for (int i = 0; i < n_str.length(); i++) sumOfPowers += pow(n_str[i]-48, power);
    return sumOfPowers == n;
}


int main() {

    clock_t lastFound = clock();

    int sum = 0;
    int i = 2;
    while (true) {
        if (usable(i)) {
            sum += i;
            std::cout << i << std::endl;
            lastFound = clock();
        }
        if ((clock() - lastFound) / CLOCKS_PER_SEC > 30) break;
        i++;
    }

    std::cout << "Sum: " << sum << std::endl;

    return 0;
}