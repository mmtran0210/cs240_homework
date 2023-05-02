#include <iostream>
#include "set.h"

using std::cout;
using std::cin;
using std::endl;
#include"set.h"  // expected cpplint error message here
using namespace Project3Problem3;  // expected cpplint error message here

int main() {
  // Test Set class with int type
  int values1[] = {1, 8, 2, 6, 3};
  Set<int> set1(5, values1);
  cout << "set1: ";
  set1.Print();

  int values2[] = {6, 4, 1};
  Set<int> set2(3, values2);
  cout << "set2: ";
  set2.Print();

  Set<int> intersection = set1.Intersection(set2);
  cout << "set1.Intersection(set2): ";
  intersection.Print();

  cout << "set1 == set2: " << (set1 == set2 ? "true" : "false") << endl;

// Test Set class with char type
char values3[] = {'a', 'c'};
Set<char> set3(2, values3);
cout << "set3: ";
set3.Print();

char values4[] = {'a', 'c', 'l', 'm'};
Set<char> set4(4, values4);
cout << "set4: ";
set4.Print();

Set<char> intersection_char = set3.Intersection(set4);
cout << "set3.Intersection(set4): ";
intersection_char.Print();

cout << "set3 == set4: " << (set3 == set4 ? "true" : "false") << endl;
  return 0;
}