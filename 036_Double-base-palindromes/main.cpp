#include <iostream>

static bool isPalindrome(const std::string& n) {
    for (int i = 0; i < n.length()/2; i++) if (n[i] != n[n.length()-1-i]) return false;
    return true;
}

static std::string decToBin(const int d) { // Dividend / Divisor = Int-Quotient + Rest/Divisor -> Rest = Dividend - Divisor*Int-Quotient
    std::string s = "";
    int zw = d;
    while (zw != 0) {
        const int r = zw - 2 * (zw/2);
        zw /= 2;
        s = std::to_string(r) + s;
    }
    return s;
}

int main() {

    int sum = 0;

    for (int i = 1; i < 1000000; i+=2) {
        const std::string base10Num = std::to_string(i);
        const std::string base2Num = decToBin(i);
        if (isPalindrome(base10Num) && isPalindrome(base2Num)) sum += i;
    }

    std::cout << "Sum: " << sum << std::endl;

    return 0;
}