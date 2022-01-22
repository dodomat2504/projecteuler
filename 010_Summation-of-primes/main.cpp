#include <iostream>
#include <fstream>
#include <sstream>

const std::string filename = "primes.txt";


int main() {
    std::ifstream reader(filename, std::ios::in);
    if (!reader) throw std::invalid_argument("File does not exist!");
    std::string data;

    std::getline(reader, data);

    std::string prime_str;
    std::stringstream data_stream(data);

    unsigned long long sum = 0;

    while (std::getline(data_stream, prime_str, ',')) {
        const unsigned long prime = std::stoul(prime_str);
        sum+=prime;
    }

    std::cout << "Sum: " << sum << std::endl;


    reader.close();

    return 0;
}
