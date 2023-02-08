#include <cmath>
#include <cstdlib>
#include <iostream>

int NumDigits(int n) {
  if (n == 0) {
    return 1;
  }
  int count = 0;
  if (n < 0) {
    count = 1;
    n = abs(n);
  }
  while (n > 0) {
    count++;
    n /= 10;
  }
  return count;
}

bool FindAndReplace(int& x, int find, int replace) {
  // check if the second and third arguments are positive integers
  if (find <= 0 || replace <= 0) return false;
  
  // check if the number of digits in find is less than the number of digits in replace
  std::string findStr = std::to_string(find);
  std::string replaceStr = std::to_string(replace);
  if (findStr.length() < replaceStr.length()) return false;

  // convert the integer to a string for easier manipulation
  std::string xStr = std::to_string(x);
  
  // find and replace all occurrences of the find integer within the xStr string
  std::string::size_type pos = xStr.rfind(findStr);
  while (pos != std::string::npos) {
    xStr.replace(pos, findStr.length(), replaceStr);
    pos = xStr.rfind(findStr, pos - 1);
  }
  
  // convert the modified string back to an integer and store it in the original x variable
  x = std::stoi(xStr);
  
  return true;
}

int main() {

}
