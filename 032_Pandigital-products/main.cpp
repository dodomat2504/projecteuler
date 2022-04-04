#include <iostream>

bool isValidNumber(const int n) {
    const std::string nmb = std::to_string(n);
    for (int i = 0; i < nmb.length()-1; i++) {
        for (int j = i+1; j < nmb.length(); j++) {
            if (nmb[i]==nmb[j] || nmb[i] == '0' || nmb[j] == '0') return false;
        }
    }
    return true;
}


int main() {

    int sum = 0;

    for (int produkt = 1234; produkt <= 9876; produkt++) {
        if (!isValidNumber(produkt)) continue;

        for (int faktor1 = 2; faktor1 <= 98; faktor1++) {
            if (!isValidNumber(faktor1)) continue;
            if (produkt % faktor1 != 0) continue;

            const int faktor2 = produkt / faktor1;

            const std::string combinedNum = std::to_string(faktor1)+std::to_string(faktor2)+std::to_string(produkt);
            if (combinedNum.length() != 9) continue;

            if (isValidNumber(std::stoi(combinedNum))) {
                std::cout << "F1: " << faktor1 << ", F2: " << faktor2 << ", P: " << produkt << " Works! " << combinedNum << std::endl;
                sum += produkt;
                break;
            }
        }
    }

    std::cout << "Sum: " << sum << std::endl;

    return 0;
}