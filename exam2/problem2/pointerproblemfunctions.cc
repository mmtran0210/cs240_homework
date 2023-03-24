// Copyright 2023 Minh My Tran
// Merge function implemented by Minh My Tran
// Print function implemented by bhipp
#include"pointerproblemfunctions.h"
#include<iostream>
using std::cout;
using std::endl;
#include<iomanip>
using std::setw;

// do not modify the implementation of the Print function
void Print(const SortedDynamicArray * nums) {
  for ( int i = 0; i < nums->size; ++i )
    cout << setw(4) << nums->values[i];
  cout << endl;
}

// implement the Merge function (described in pointerproblemfunctions.h) here
void Merge(SortedDynamicArray * const a, const SortedDynamicArray * const b) {
    int newSize = a->size + b->size;
    int *newValues = new int[newSize];
    int i = 0, j = 0, k = 0;
    while (i < a->size && j < b->size) {
        if (a->values[i] < b->values[j]) {
            newValues[k++] = a->values[i++];
        } else {
            newValues[k++] = b->values[j++];
        }
    }
    while (i < a->size) {
        newValues[k++] = a->values[i++];
    }
    while (j < b->size) {
        newValues[k++] = b->values[j++];
    }
    delete[] a->values;
    a->size = newSize;
    a->values = newValues;
}