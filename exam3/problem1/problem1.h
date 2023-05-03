// My Tran - CSCE 240 

#ifndef _PROBLEM1_H_
#define _PROBLEM1_H_

namespace Project3Problem1 {
    template <typename T>
    T Median(const T* arr, int n) {
        T* temp_arr = new T[n];
        for (int i = 0; i < n; ++i) {
            temp_arr[i] = arr[i];
        }
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {
                if (temp_arr[j] > temp_arr[j + 1]) {
                    T temp = temp_arr[j];
                    temp_arr[j] = temp_arr[j + 1];
                    temp_arr[j + 1] = temp;
                }
            }
        }
        T median;
        if (n % 2 == 0) {
            median = (temp_arr[n / 2 - 1] + temp_arr[n / 2]) / 2;
        } else {
            median = temp_arr[n / 2];
        }
        delete[] temp_arr;
        return median;
    }
}

#endif // _PROBLEM1_H_