// My Tran - CSCE 240 

#ifndef _FACT_CHECKED_STATEMENT_H_
#define _FACT_CHECKED_STATEMENT_H_

#include<iostream>
#include"sentence.h"

namespace Project3Problem2 {

class FactCheckedStatement : public Sentence {
 public:
    
    // Constructor
    FactCheckedStatement(string s, double truth_value = 0) : Sentence(s) {
  if (s[0] < 'A' || s[0] > 'Z' || s.back() != '.') {
    string::operator=("This is an unverified statement.");
    tv = 0;
  } else {
    tv = (truth_value >= 0 && truth_value <= 1) ? truth_value : 0;
  }
}

  // Overloaded assignment operator
  FactCheckedStatement& operator=(const string& right) {
    if (right[0] >= 'A' && right[0] <= 'Z' && right.back() == '.') {
      string::operator=(right);
      tv = 0;
    }
    return *this;
  }

  // Getter for Truth
  double GetTruth() const { 
    return tv; }

  // Setter for Truth
  void SetTruth(double truth_value) {
    if (truth_value >= 0 && truth_value <= 1) {
      tv = truth_value;
    }
  }

 private:
  double tv;
};

// Overloaded stream insertion operator
std::ostream& operator<<(std::ostream& os, const FactCheckedStatement& s) {
  os << static_cast<string>(s) << " (" << s.GetTruth() * 100 << "% true)";
  return os;
}

}  // namespace Project3Problem2

#endif // _FACT_CHECKED_STATEMENT_H_