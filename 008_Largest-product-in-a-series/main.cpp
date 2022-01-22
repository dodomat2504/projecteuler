#include <iostream>
#include <fstream>
#include "window.h"

static const std::string filename = "number.txt";
static const unsigned int anzAdjNums = 13;
static const int ascii_offset = -48;


void init(Window<anzAdjNums> &w, std::ifstream &reader) {

    for (int i = 0; i < anzAdjNums; i++) {
        const int zahl = std::stoi(std::to_string((char) reader.get() + ascii_offset));
        w.addNum(zahl);
    }

}

int main() {
    Window<anzAdjNums> w;
    std::ifstream reader(filename, std::ios::in);
    if (!reader) throw std::runtime_error("File does not exist!");

    init(w, reader);

    while (true) {
        const char c = reader.get();
        if (reader.eof()) break;

        const int zahl = std::stoi(std::to_string(c + ascii_offset));
        w.addNum(zahl);

    }

    reader.close();

    std::cout << "Biggest Product: " << w.getMaxProductEver() << std::endl;


    return 0;
}
