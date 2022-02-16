#include <iostream>
#include "maximumPath.h"

const std::string filename = "tree.txt";


int main() {
    std::ifstream reader(filename, std::ios::in);

    std::cout << "Ergebnis: " << getMaxPathFromTree(reader) << std::endl;

    return 0;
}
