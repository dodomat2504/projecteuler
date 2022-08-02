#ifndef STRING_MATH_H
#define STRING_MATH_H

/// @author Dominik Mandok
/// @date 12.02.2022

#include <string>


class Number {
protected:
    int _lengthOfStr;
    std::string _str;

public:
    Number(const std::string& = "");
    Number(const int);

    const std::string& toString() const;

    /// @returns the length of the number
    int length() const;

    static Number pow(const int, const int);

    Number operator+(const Number&) const;
    Number operator+=(const Number&);
    Number& operator=(const Number&);
    Number operator-(const Number&) const;
    Number operator*(const Number&) const;
    Number operator*=(const Number&);
    Number operator/(const Number&) const;
    std::ostream& operator<<(std::ostream&) const;

    bool operator==(const Number&) const;
    bool operator<(const Number&) const;
};

#endif // STRING_MATH_H
