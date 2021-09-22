#include <iostream>


int main() {

    const int maxVal = 4000000;

    // Sum of all the even fib-nums
    long sum = 0;

    int fib_num = 1, prev_fib_num = 0;

    while (fib_num < maxVal) {

        // adds the fib-num if it is even (if even: add fib_num; else add 0)
        sum += (fib_num % 2 == 0) * fib_num;

        // Set the new fib_num and prev_fib_num
        const int zw = prev_fib_num;
        prev_fib_num = fib_num;
        fib_num = zw + prev_fib_num;
    }

    std::cout << "Sum of even fib-nums: " << sum << std::endl;

    return 0;
}
