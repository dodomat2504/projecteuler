#include <iostream>

const int MAXSTEPS = 40;


static void getPathsCount(const int stepsLeft, int& counter, const int x = 0, const int y = 0) {
    if (stepsLeft == 0 && x == 20 && y == 20) { counter++; return; }
    if (x >= MAXSTEPS || y >= MAXSTEPS) return;
    getPathsCount(stepsLeft-1, counter, x+1, y);
    getPathsCount(stepsLeft-1, counter, x, y+1);
}

int main() {

    int counter = 0;
    getPathsCount(MAXSTEPS, counter);

    std::cout << "Num of Routes: " << counter << std::endl;

    return 0;
}

/*
 * Since you always have to go 2*n steps:
 * Count of Possible Routes = 2*n over n = 137846528820
 */
