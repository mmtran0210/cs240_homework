// My Tran - CSCE 240 

#ifndef PROBLEM1_H
#define PROBLEM1_H

#include <algorithm>
#include <vector>

namespace Project3Problem1 {
    template <typename T>
    T Median(const T* array, int n) {
        std::vector<T> v(array, array + n);
        std::sort(v.begin(), v.end());
        if (n % 2 == 0) {
            return (v[n / 2 - 1] + v[n / 2]) / 2;
        } else {
            return v[n / 2];
        }
    }
}

#endif