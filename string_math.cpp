#include "string_math.h"


Number::Number(const std::string& numberAsString) {
    _lengthWoNullT = numberAsString.length();
    _lengthOfStr = _lengthWoNullT + 1;
    _str = new char*[_lengthOfStr];
    for (int i = 0; i < _lengthWoNullT; i++) *(_str[i]) = numberAsString[i];
    *(_str[_lengthOfStr-1]) = '\0';
}

std::string Number::toString() const { return *_str; }

int Number::length() const { return _lengthWoNullT; }

extern std::ostream& operator<<(std::ostream& stout, const Number& n) {
    char out[n.length()+1];
    out[n.length()] = '\0';
    for (int i = 0; i < n.length(); i++) out[i] = ;
    stout << out;
}
