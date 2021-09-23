#include <iostream>


const int max3DigitNum = 999;

/// @brief Checks if the number is a palindrome
/// @returns bool
bool isPalindrome(const int i) {
    const std::string num = std::to_string(i);

    for (int i = 0; i < num.length() / 2; i++)
        if (num[i] != num[num.length()-1 - i]) return false;
    return true;
}

int main() {

    int biggest_palindrome = 0;

    for (int fact1 = 100; fact1 <= max3DigitNum; fact1++)
        for (int fact2 = 100; fact2 <= max3DigitNum; fact2++) {
            const int prod = fact1 * fact2;

            if (isPalindrome(prod) && prod > biggest_palindrome) biggest_palindrome = prod;
        }

    std::cout << "Biggest prod: " << biggest_palindrome << std::endl;

    return 0;
}
