#include "string_math.h"
#include <iostream>

static const int ASCII = 48;


Number::Number(const std::string& numberAsString) {
    _lengthOfStr = numberAsString.length();
    _str = numberAsString;
}

const std::string& Number::toString() const { return _str; }

int Number::length() const { return _lengthOfStr; }

std::ostream& Number::operator<<(std::ostream& stout) const {
    stout << _str;
    return stout;
}

Number Number::operator+(const Number& n) const {
    std::string num1 = _str, num2 = n.toString();
    const int longerStringLength = num1.length() > num2.length() ? num1.length() : num2.length();

    if (num1.length() > num2.length()) {
        std::string zw = "";
        for (int i = 0; i < longerStringLength - num2.length(); i++) zw += "0";
        num2 = zw + num2;
    } else if (num1.length() < num2.length()) {
        std::string zw = "";
        for (int i = 0; i < longerStringLength - num1.length(); i++) zw += "0";
        num1 = zw + num1;
    }

    std::string ergebnis = "";
    int uebertrag = 0;
    for (int i = longerStringLength - 1; i >= 0; i--) {
        const int summA = num1[i] - ASCII; // ASCII wirklich huso
        const int summB = num2[i] - ASCII;

        int summe = summA + summB + uebertrag;
        uebertrag = 0;
        while (summe >= 10) {
            uebertrag++;
            summe-=10;
        }

        ergebnis = std::to_string(summe) + ergebnis;
    }

    if (uebertrag > 0) ergebnis = std::to_string(uebertrag) + ergebnis;

    return Number(ergebnis);
}

Number Number::operator+=(const Number &n) {
    _str = (*this + n).toString();
    _lengthOfStr = _str.length();
    return *this;
}


Number Number::operator-(const Number& n) const {

}

Number Number::operator*(const Number& n) const {
    const std::string num1 = _str;
    const std::string num2 = n.toString();

    Number sum;

    for (int i = 0; i < num1.length(); i++) {
        const int fakt1 = num1[i] - ASCII;

        int uebertrag = 0;
        std::string product = "";

        for (int j = 0; j < num2.length(); j++) {
            const int fakt2 = num2[num2.length() - 1 - j] - ASCII;
            int prod = fakt1 * fakt2 + uebertrag;
            uebertrag = 0;
            while (prod >= 10) {
                uebertrag++;
                prod-=10;
            }

            product = std::to_string(prod) + product;
        }
        if (uebertrag > 0) product = std::to_string(uebertrag) + product;

        for (int z = 0; z < num1.length()-i-1; z++) product += "0";

        sum += Number(product);
    }

    return sum;
}

Number Number::operator*=(const Number& n) {
    const std::string newStr = ((*this) * n).toString();
    this->_str = newStr;
    this->_lengthOfStr = _str.length();
    return *this;
}

Number Number::operator/(const Number& n) const {

}
