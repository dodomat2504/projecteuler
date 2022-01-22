#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>


template<const unsigned int size>
class Window {
private:
    int arr[size];

    long maxProductEver = 0;
    int lastElementIndex = 0;


    bool containsZero() const {
        for (int i = 0; i < size; i++) if (arr[i] == 0) return true;
        return false;
    }

    void updateProduct() {
        if (!containsZero()) {
            long product = 1;
            for (int i = 0; i < size; i++) {
                product *= arr[i];
            }
            if (product > maxProductEver) maxProductEver = product;
        }
    }
public:
    Window<size>() {
        for (int i = 0; i < size; i++) arr[i] = 0;
    }
    ~Window<size>() {}

    void addNum(const int num) {
        arr[lastElementIndex++ % size] = num;
        updateProduct();
    }



    long getMaxProductEver() const { return maxProductEver; }

};

#endif // WINDOW_H
