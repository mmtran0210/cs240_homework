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
    // Calculate the new size of the merged array
    int newSize = a->size + b->size;
    
    // Create a new array to hold the merged values
    int *newValues = new int[newSize];
    
    // indices for the three arrays
    int i = 0, j = 0, k = 0;
    
    // Merge the two arrays 
    while (i < a->size && j < b->size) {
        if (a->values[i] < b->values[j]) {
            newValues[k++] = a->values[i++];
        } else if (a->values[i] > b->values[j]) {
            newValues[k++] = b->values[j++];
        } else {
            // If the values are equal, only add one to avoid duplicates
            newValues[k++] = a->values[i++];
            j++;
        }
    }
    // Add any remaining values from the first array
    while (i < a->size) {
        newValues[k++] = a->values[i++];
    }
    // Add any remaining values from the second array
    while (j < b->size) {
        newValues[k++] = b->values[j++];
    }
    // Delete the old values array
    delete[] a->values;

    // Update the size and values
    a->size = k;
    a->values = new int[a->size];
    for (int i = 0; i < a->size; i++) {
        a->values[i] = newValues[i];
    }
    // Delete the temp newValues array
    delete[] newValues;
}