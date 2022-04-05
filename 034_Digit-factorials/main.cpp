#include <iostream>
#include <ctime>

static int fact(const int n) {
    int f = 1;
    for (int i = n; i >= 2; i--) f*=i;
    return f;
}

static int sumOfFacts(const int n) {
    int sum = 0;
    const std::string n_str = std::to_string(n);
    for (int i = 0; i < n_str.length(); i++) sum += fact((n_str[i]-48));
    return sum;
}


int main() {

    int sum = 0;

    const clock_t start = clock();
    
    for (int counter = 11; counter <= 40585; counter++) {
        if (counter == sumOfFacts(counter)) {
            sum += counter;
        }
    }
    
    const clock_t end = clock();

    std::cout << "Zeit: " << (end-start)*1000000/CLOCKS_PER_SEC << std::endl;

    std::cout << "Sum: " << sum << std::endl;

    return 0;
}