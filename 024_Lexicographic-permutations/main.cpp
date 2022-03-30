#include <iostream>
#include <cmath>


static void insert(std::vector<int>& vec, const int data) {
    int l = 0, r = vec.size()-1;
    if (vec.size() == 0) {
        vec.push_back(data);
        return;
    }

    int prev_mid = -1;
    while (true) {
        if (r == l) {
            vec.insert(vec.begin()+l, data);
            break;
        }

        const int mid = (r + l) / 2;
        if (mid == prev_mid) throw std::invalid_argument("Hä");
        prev_mid = mid;
        if (vec[mid] > data) r = mid;
        else if (vec[mid] < data) l = mid + 1;
        else throw std::invalid_argument("Nä");
    }
}

void rec(int& counter, std::vector<int>& numbers, const int depth) {
    
}


int main() {

    const int PERM = 1000000;
    std::string number = "0123456789";
    const int LEN = number.length();

    int counter = 0;

    std::cout << "Permutation" << PERM << ": " << number << std::endl;

    return 0;
}
