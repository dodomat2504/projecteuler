#include <iostream>
#include <thread>
#include <atomic>

const int anzCores = 8;
static void searcher(long long &result, const int startNum, std::atomic<bool> &finished, int &maxCounter) {
    long long numToTest = startNum-anzCores;
    while (true) {
        if (numToTest % 1000) if (finished) return;
        numToTest+=anzCores;

        int counter = 0;

        for (long long i = 1; i*2 <= numToTest; i++) {
            if (numToTest % i == 0) {
                counter++;
                if (counter > maxCounter) {
                    maxCounter = counter;
                    std::cout << "New MaxCounter: " << maxCounter << "at Num: " << numToTest << std::endl;
                }
                if (counter > 500) {
                    result = numToTest;
                    finished = true;
                    return;
                }
            }
        }

        if (numToTest > 999999999999) return;
    }
}



int main() {
    std::atomic<bool> finished(false);
    int maxCounter = 0;

    std::cout << "Num to start: ";
    long long num;
    std::cin >> num;

    long long t1_found = 0, t2_found = 0, t3_found = 0, t4_found = 0, t5_found = 0, t6_found = 0, t7_found = 0, t8_found = 0;

    std::thread t1(searcher, std::ref(t1_found), num+1, std::ref(finished), std::ref(maxCounter));
    std::thread t2(searcher, std::ref(t2_found), num+2, std::ref(finished), std::ref(maxCounter));
    std::thread t3(searcher, std::ref(t3_found), num+3, std::ref(finished), std::ref(maxCounter));
    std::thread t4(searcher, std::ref(t4_found), num+4, std::ref(finished), std::ref(maxCounter));
    std::thread t5(searcher, std::ref(t5_found), num+5, std::ref(finished), std::ref(maxCounter));
    std::thread t6(searcher, std::ref(t6_found), num+6, std::ref(finished), std::ref(maxCounter));
    std::thread t7(searcher, std::ref(t7_found), num+7, std::ref(finished), std::ref(maxCounter));
    std::thread t8(searcher, std::ref(t8_found), num+8, std::ref(finished), std::ref(maxCounter));

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
    t7.join();
    t8.join();



    std::cout << "Found: " << t1_found << "; " << t2_found << "; " << t3_found << "; " << t4_found << "; " << t5_found << "; " << t6_found << "; " << t7_found << "; " << t8_found << std::endl;

    return 0;
}
