#include <iostream>
#include <cmath>

static void swap(std::string& str, const int i1, const int i2) {
    if (i1 >= str.length() || i2 >= str.length() || i1 < 0 || i2 < 0) throw std::invalid_argument("String index out of bounds.");
    const char c = str[i1];
    str[i1] = str[i2];
    str[i2] = c;
}

int main() {

    for (int i = 0; i < 10; i++) {
        const int PERM = 1 + i;
        std::string number = "0123456789";
        const int LEN = number.length();

        for (int c = 1; c < PERM; c++) {
            for (int index = LEN - 1; index >= 0; index--) {
                const int reverseIndex = LEN - 1 - index;

                if ((c % PERM) % ((int) pow(2, reverseIndex)) == 0) {
                    if (index != 0) swap(number, index-1, index);
                    else {
                        for (int i = LEN-1; i > 0; i--) swap(number, i-1, i);
                    }
                }
            }
        }

        std::cout << "Permutation" << PERM << ": " << number << std::endl;
    }


    /*
       0 0 0 0 0 0 0 0 0 0 -> 0 1 2 3 4 5 6 7 8 9
       0 0 0 0 0 0 0 0 0 1 -> 0 1 2 3 4 5 6 7 9 8
       0 0 0 0 0 0 0 0 1 0 -> 0 1 2 3 4 5 6 8 7 9
       0 0 0 0 0 0 0 0 1 1 -> 0 1 2 3 4 5 6 8 9 7
       0 0 0 0 0 0 0 1 0 0 -> 0 1 2 3 4 5 8 6 7 9
       0 0 0 0 0 0 0 1 0 1 -> 0 1 2 3 4 5 8 6 9 7
       0 0 0 0 0 0 0 1 1 0 -> 0 1 2 3 4 5 8 7 6 9
       0 0 0 0 0 0 0 1 1 1 -> 0 1 2 3 4 5 8 7 9 6
       0 0 0 0 0 0 1 0 0 0 -> 0 1 2 3 4 8 5 6 7 9
    */

    return 0;
}
