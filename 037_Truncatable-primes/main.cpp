#include <iostream>
// const bool fales = false; <- Dynge Sebi

static bool contains(const std::string& s, const char c) {
    for (int i = 0; i < s.length(); i++) if (s[i] == c) return true;
    return false;
}

static bool possibleNumber(const int n) {
    const std::string n_str = std::to_string(n);
    if (contains(n_str, '0') || contains(n_str, '2') || contains(n_str, '4') || contains(n_str, '6') || contains(n_str, '8')) return false;
    if (n_str[0] == '1' || n_str[n_str.length()-1] == '1') return false;
    return true;
}

static bool isPrime(const int n) {
    if (n % 2 == 0 || n < 2) return false;
    for (int i = 3; i <= n/2; i+=2) if (n % i == 0) return false;
    return true;
}


int main() {

    int counter = 0;
    int i = 11;

    int sum = 0;

    while (counter < 12) {
        if (!possibleNumber(i)) { i++; continue; }
        bool prime = true;

        // left to right
        const std::string i_str = std::to_string(i);

        for (int j = 0; j < i_str.length()-1; j++) {
            std::string s = "";
            for (int c = j; c < i_str.length()-1; c++) {
                s += i_str[c];
            }
            const int zw = std::stoi(s);
            if (!isPrime(zw)) { prime = false; break; }
        }
        
        // right to left
        for (int j = i_str.length()-1; j >= 0; j--) {
            std::string s = "";
            for (int c = j; c >= 0; c--) {
                s = i_str[c] + s;
            }
            const int zw = std::stoi(s);
            if (!isPrime(zw)) { prime = false; break; }
        }

        if (prime) { sum += i; counter++; }
                
        i++;
    }

    std::cout << "Sum: " << sum << std::endl;

    return 0;
}