#include "string_math.h"
#include <iostream>

static const int ASCII_HUSO = 48;


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
        const int summA = num1[i] - ASCII_HUSO; // ASCII wirklich huso
        const int summB = num2[i] - ASCII_HUSO;

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

}

Number Number::operator*=(const Number& n) {

}

Number Number::operator/(const Number& n) const {

}
