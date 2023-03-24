
// Minh My Tran - CSCE 240


#ifndef _LENGTH_H_
#define _LENGTH_H_

#include <string>
#include <iostream>
using std::string;
using std::ostream;
using namespace std;

class Length {
private:
    double value;
    string units;

public:
    // Constructor with default arguments
    Length(double value = 0.0, string units = "inches");

    // Accessor functions
    double GetValue() const;
    string GetUnits() const;

    // Mutator functions
    void SetValue(double value);
    void SetUnits(string units);

    // Convert function
    void Convert(string newUnits);
        // Overloaded operators
    Length operator+(const Length& other) const;
    bool operator==(const Length& other) const;
    bool operator<(const Length& other) const;

};
// Overloaded << operator (non-member function)
ostream& operator<<(ostream& os, const Length& length);


#endif // _LENGTH_H_