#include <iostream>
#include <ctime>

const int max_1p = 200;
const int max_2p = 100;
const int max_5p = 40;
const int max_10p = 20;
const int max_20p = 10;
const int max_50p = 4;
const int max_1P = 2;
const int max_2P = 1;

const int LOWER_COUNTER = 0;
const int UPPER_COUNTER = 0;


int main() {

    const int goal = 200;

    int sumOfPossibilities = 0;
    int counter = 0;

    clock_t start = clock();

    for (int p1 = 0; p1 <= max_1p; p1++) {
        for (int p2 = 0; p2 <= max_2p; p2++) {
            if (p1 + 2*p2 > goal) break;

            for (int p5 = 0; p5 <= max_5p; p5++) {
                if (p1 + 2*p2 + 5*p5 > goal) break;

                for (int p10 = 0; p10 <= max_10p; p10++) {
                    if (p1 + 2*p2 + 5*p5 + 10*p10 > goal) break;

                    for (int p20 = 0; p20 <= max_20p; p20++) {
                        if (p1 + 2*p2 + 5*p5 + 10*p10 + 20*p20 > goal) break;

                        for (int p50 = 0; p50 <= max_50p; p50++) {
                            if (p1 + 2*p2 + 5*p5 + 10*p10 + 20*p20 + 50*p50 > goal) break;

                            for (int P1 = 0; P1 <= max_1P; P1++) {
                                if (p1 + 2*p2 + 5*p5 + 10*p10 + 20*p20 + 50*p50 + 100*P1 > goal) break;

                                for (int P2 = 0; P2 <= max_2P; P2++) 
                                    if (p1 + 2*p2 + 5*p5 + 10*p10 + 20*p20 + 50*p50 + 100*P1 + 200*P2 == goal) sumOfPossibilities++;
                            }
                        }
                    }
                }
            }
        }
    }

    clock_t end = clock();

    std::cout << "Laufzeit: " << (end-start)*1000000 / CLOCKS_PER_SEC << std::endl;

    std::cout << "Sum: " << sumOfPossibilities << std::endl;

    return 0;
}
