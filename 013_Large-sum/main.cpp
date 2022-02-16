#include <iostream>
#include "../string_math.h"
#include <fstream>

const std::string filename = "nums.txt";
const int anzNums = 100;

int main() {

    std::ifstream reader(filename, std::ios::in);
    std::string zahl;

    Number arr[anzNums];
    int zaehler = 0;
    while (std::getline(reader, zahl)) {
        arr[zaehler] = Number(zahl);
        zaehler++;
    }

    reader.close();

    Number erg("0");

    for (int i = 0; i < anzNums; i++) {
        erg += arr[i];
    }

    std::cout << "Lutscher: " << erg.toString() << std::endl;

    return 0;
}
