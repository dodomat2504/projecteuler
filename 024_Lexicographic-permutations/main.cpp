#include <iostream>
#include <cmath>

static void swap(std::string& str, const int i1, const int i2) {
    if (i1 >= str.length() || i2 >= str.length() || i1 < 0 || i2 < 0) throw std::invalid_argument("Lösch dich");
    const char c = str[i1];
    str[i1] = str[i2];
    str[i2] = c;
}


int main() {

    const int PERM = 1000000;
    std::string s = "0123456789";


    for (int i = 2; i <= PERM; i++) {
        
        int pivot = -1;

        for (int j = s.length() - 1; j > 0; j--) {
            if (s[j-1] < s[j]) {
                pivot = j-1;
                break;
            }
        }
        if (pivot == -1) break;

        int successor = -1;

        for (int j = s.length() - 1; j > pivot; j--) {
            if (s[j] > s[pivot]) {
                successor = j;
                break;
            }
        }

        swap(s, pivot, successor);

        for (int j = 0; j < ceil((s.length() - 1 - (pivot + 1))/2.0); j++) swap(s, pivot + 1 + j, s.length() - 1 - j);
    }


    std::cout << "Permutation" << PERM << ": " << s << std::endl;

    return 0;
}
