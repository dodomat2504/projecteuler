#include <iostream>
#include "../SumOfSquaresAndSquareOfSums.h"


int main() {

    const int lastNum = 100;


    const int SuOfSq = SumOfSquares(lastNum);
    const int SqOfSu = SquareOfSums(lastNum);

    std::cout << "SuOfSq: " << SuOfSq << std::endl;
    std::cout << "SqOfSu: " << SqOfSu << std::endl;

    std::cout << "Diff: " << SqOfSu - SuOfSq << std::endl;

    return 0;
}
