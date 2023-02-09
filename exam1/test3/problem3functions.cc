// Minh My Tran - CSCE 240 003 - Exam 1 

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

int NumDigits(int n) {
  // If n is zero, return 1
  if (n == 0) return 1;
  
  //  log base 10 of the absolute value of n
  int log10_n = floor(log10(abs(n)));
  
  // Return log10_n + 1 as the result
  return log10_n + 1;
}

bool FindAndReplace(int &x, int find, int replace) {
  if (find < 0 || replace < 0 || to_string(replace).length() > to_string(find).length()) {
    return false;
  }

  string xStr = to_string(x);
  string findStr = to_string(find);
  string replaceStr = to_string(replace);
  int findLength = findStr.length();
  int replaceLength = replaceStr.length();
  int findStart = xStr.length() - findLength;

  for (int i = findStart; i >= 0; i--) {
    if (xStr.substr(i, findLength) == findStr) {
      xStr.replace(i, findLength, replaceStr);
    }
  }

  x = stoi(xStr);
  return true;
}



