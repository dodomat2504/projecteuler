#ifndef SUMOFSQUARESANDSQUAREOFSUMS_H
#define SUMOFSQUARESANDSQUAREOFSUMS_H


/// @brief Calculates the sum of numbers from 1 to <end>
static float sum(const int end) {
    return (end * end + end) / 2.0;
}

/// @brief Calcualtes the Square of the sum of the numbers from 1 to <end>
int SquareOfSums(const int end) {
    const int summ1 = end * end * end * end;
    const int summ2 = 2 * (end * end * end);
    const int summ3 = end * end;

    return (summ1 + summ2 + summ3) / 4;
}

/// @brief Calcualtes the Sum of the squares of the numbers from 1 to <end>
int SumOfSquares(const int end) {
    const float summ1 = end * (end + 1) * (2 * end + 1);

    return summ1 / 6;
}


#endif // SUMOFSQUARESANDSQUAREOFSUMS_H
