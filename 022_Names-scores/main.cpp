#include <iostream>
#include <fstream>
#include <sstream>


const std::string filename = "names.txt";
const int ASCII_OFFSET = 64;

// Selectionsort
void sort(std::string* array, const int N) {
    for (int i = 0; i < N; i++) {
        int smallest_index = i;
        std::string smallest = array[i];

        for (int j = i; j < N; j++) {
            if (array[j] < smallest) {
                smallest = array[j];
                smallest_index = j;
            }
        }

        array[smallest_index] = array[i];
        array[i] = smallest;
    }
}


int main() {
    std::ifstream reader(filename, std::ios::in);
    if (!reader) throw std::invalid_argument("Something went wrong");

    const int length = 5163;
    std::string* names_arr = new std::string[length];

    int counter = 0;
    while (std::getline(reader, names_arr[counter])) counter++;

    sort(names_arr, length);

    long sum = 0;

    for (int i = 0; i < length; i++) {

        int alph_sum = 0;
        for (char c : names_arr[i]) alph_sum += ((int) c) - ASCII_OFFSET;

        sum += alph_sum*(i+1);
    }

    std::cout << "Sum: " << sum << std::endl;

    return 0;
}