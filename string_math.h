#ifndef STRING_MATH_H
#define STRING_MATH_H

/// @author Dominik Mandok
/// @date 12.02.2022

#include <string>



class Number {
private:
    /// @brief Length of the char** with nulltermination
    int _lengthOfStr;

    /// @brief Pointer to the string of numbers
    std::string _str;
public:
    Number(const std::string& = "");

    const std::string& toString() const;

    /// @returns the length of the number
    int length() const;

    Number operator+(const Number&) const;
    Number operator+=(const Number&);
    Number operator-(const Number&) const;
    Number operator*(const Number&) const;
    Number operator*=(const Number&);
    Number operator/(const Number&) const;
    std::ostream& operator<<(std::ostream&) const;
};

#endif // STRING_MATH_H






// cout << "Du dummer hurensohn cpp code" << endl; yalla hier ist der key to my heart, geh mal auf yt und such nach rick roll vertrau mir ist kein rickroll :D
