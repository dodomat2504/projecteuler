#include <iostream>


int main() {

    const int base_num1 = 3;
    const int base_num2 = 5;
    const int end_num = 1000;

    /// \brief sum of all multiples
    long sum = 0;

    for (int i = base_num1; i < end_num; i+=base_num1)
        sum += i;

    for (int i = base_num2; i < end_num; i+=base_num2)
        // if the actual multiple is also a multiple of the first base_num, dont add it
        if (i % base_num1 != 0)
            sum += i;

    std::cout << "Sum: " << sum << std::endl;

    return 0;
}
