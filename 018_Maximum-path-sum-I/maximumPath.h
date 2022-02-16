#ifndef MAXIMUMPATH_H
#define MAXIMUMPATH_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <cmath>


static int summeVon1BisN(const int N) {
    int sum = 0;
    for (int i = 1; i <= N; i++) sum += i;
    return sum;
}

static int reiheDesIndex(const int index, const int anzRows) {
    int r = 1;
    while (r <= anzRows) {
        if (summeVon1BisN(r) <= index) r++;
        else break;
    }
    return r;
}

int getMaxPathFromTree(std::ifstream& filestream) {
    std::string line;
    std::getline(filestream, line);
    filestream.close();
    std::stringstream linestream(line);
    std::string num;

    std::vector<int> nums;

    while (std::getline(linestream, num, ',')) nums.push_back(std::stoi(num));
    const int anzahlNums = nums.size();
    const int anzRows = (sqrt(8 * anzahlNums + 1) - 1) / 2;

    for (int i = anzahlNums - 1 - anzRows; i >= 0; i--) {
        const int reihe = reiheDesIndex(i, anzRows);
        const int biggerSideValue = nums[i+reihe] > nums[i+reihe+1] ? nums[i+reihe] : nums[i+reihe+1];
        nums[i] += biggerSideValue;
    }

    return nums[0];
}

#endif // MAXIMUMPATH_H
