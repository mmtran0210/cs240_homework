// Minh My Tran - CSCE 240 

#include "length.h"

// Constructor with default arguments
Length::Length(double value, string units) {
    if (value < 0) {
        this->value = 0;
    } else {
        this->value = value;
    }

    if (units == "inches" || units == "centimeters") {
        this->units = units;
    } else {
        this->units = "inches";
    }
}

// Accessor functions
double Length::GetValue() const { 
    return value; }

string Length::GetUnits() const { 
    return units; }

// Mutator functions
void Length::SetValue(double value) {
    if (value >= 0) {
        this->value = value;
    }
}

void Length::SetUnits(string units) {
    if (units == "inches" || units == "centimeters") {
        this->units = units;
    }
}

// Convert function
void Length::Convert(string newUnits) {
    if (newUnits == "inches" || newUnits == "centimeters") {
        if (units == "inches" && newUnits == "centimeters") {
            value *= 2.54;
        } else if (units == "centimeters" && newUnits == "inches") {
            value /= 2.54;
        }
        units = newUnits;
    }
}

// Overloaded + operator
Length Length::operator+(const Length& other) const {
    double newValue = value;
    string newUnits = units;

    if (other.units != units) {
        if (units == "inches") {
            newValue += other.value / 2.54;
        } else { // units == "centimeters"
            newValue += other.value * 2.54;
        }
    } else { // other.units == units
        newValue += other.value;
    }

    return Length(newValue, newUnits);
}

// Overloaded == operator
bool Length::operator==(const Length& other) const {
    double thisValueInches = (units == "inches") ? value : value / 2.54;
    double otherValueInches = (other.units == "inches") ? other.value : other.value / 2.54;

    return thisValueInches == otherValueInches;
}

// Overloaded < operator
bool Length::operator<(const Length& other) const {
    double thisValueInches = (units == "inches") ? value : value / 2.54;
    double otherValueInches = (other.units == "inches") ? other.value : other.value / 2.54;

    return thisValueInches < otherValueInches;
}

std::ostream& operator<<(std::ostream& os, const Length& length) {
    os << length.GetValue() << " " << length.GetUnits();
    return os;
}