#include <iostream>
#include <fstream>
#include <sstream>

const std::string filename = "matrix.txt";
const unsigned short matrixDimensions = 20;
const int anzFaktoren = 4;

const bool DEBUG = true;


void init(int** const matrix) {
    std::ifstream reader(filename, std::ios::in);
    if (!reader) throw std::invalid_argument("This file does not exist!");

    std::string line;
    int z = 0;
    while (std::getline(reader, line)) {
        std::stringstream line_stream(line);
        std::string num_str;
        int s = 0;

        while (std::getline(line_stream, num_str, ',')) {
            const int num = std::stoi(num_str);
            matrix[z][s] = num;
            if (DEBUG) std::cout << "[" << z << "][ " << s << "] = " << num << std::endl;
            s++;
        }
        z++;
    }

    reader.close();
}


int main() {
    int** const matrix = new int*[matrixDimensions];
    for (int i = 0; i < matrixDimensions; i++) matrix[i] = new int[matrixDimensions];

    init(matrix);

    long maxProd = 0;

    // horizontally check
    for (int z = 0; z < matrixDimensions; z++) {
        for (int s = 0; s < matrixDimensions - anzFaktoren; s++) {
            const long prod = matrix[z][s]*matrix[z][s+1]*matrix[z][s+2]*matrix[z][s+3];
            if (prod > maxProd) maxProd = prod;
        }
    }

    // vertically check
    for (int s = 0; s < matrixDimensions; s++) {
        for (int z = 0; z < matrixDimensions - anzFaktoren; z++) {
            const long prod = matrix[z][s]*matrix[z+1][s]*matrix[z+2][s]*matrix[z+3][s];
            if (prod > maxProd) maxProd = prod;
        }
    }

    // topleft to downright check
    for (int z = 0; z < matrixDimensions - anzFaktoren; z++) {
        for (int s = 0; s < matrixDimensions - anzFaktoren; s++) {
            const long prod = matrix[z][s]*matrix[z+1][s+1]*matrix[z+2][s+2]*matrix[z+3][s+3];
            if (prod > maxProd) maxProd = prod;
        }
    }

    // topright to downleft check
    for (int z = 0; z < matrixDimensions - anzFaktoren; z++) {
        for (int s = anzFaktoren; s < matrixDimensions; s++) {
            const long prod = matrix[z][s]*matrix[z+1][s-1]*matrix[z+2][s-2]*matrix[z+3][s-3];
            if (prod > maxProd) maxProd = prod;
        }
    }


    std::cout << "MaxProduct: " << maxProd << std::endl;

    for (int i = 0; i < matrixDimensions; i++) delete [] matrix[i];
    delete [] matrix;

    return 0;
}
