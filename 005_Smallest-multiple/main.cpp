#include <iostream>

/*
 * If a number is divisible by ... it is also divisible by:
 * - 20: 10,5,4,2
 * - 19
 * - 18: 9,6,3,2
 * - 17
 * - 16: 8,4,2
 * - 15: 5,3
 * - 14: 7,2
 * - 13
 * - 12: 6,2
 * - 11
 */

const int lowerEdge = 2;
const int upperEdge = 20;


int main() {

    int num = upperEdge;

    while (true) {
        bool cont = false;

        for (int i = 19; i >= 11; i--) {
            if (num % i != 0) {
                num += upperEdge;
                cont = true;
                break;
            }
        }

        if (cont) continue;
        break;
    }

    std::cout << num << " is divisible by every number between " << lowerEdge << " and " << upperEdge << std::endl;

    return 0;
}
