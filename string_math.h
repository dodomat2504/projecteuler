#ifndef STRING_MATH_H
#define STRING_MATH_H

/// @author Dominik Mandok
/// @date 12.02.2022

#include <string>



class Number {
private:
    /// @brief Length of the char** with nulltermination
    int _lengthOfStr;

    /// @brief Length of the char** without nulltermination
    int _lengthWoNullT;

    /// @brief Pointer to the string of numbers
    char** _str;
public:
    Number(const std::string&);

    std::string toString() const;

    /// @returns the length of the number
    int length() const;


    std::ostream& operator<<(std::ostream&) const;
};

#endif // STRING_MATH_H
