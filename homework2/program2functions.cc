// Minh My Tran - CSCE 240 003

#include <iostream>

bool LeapYear(int year) {
  return (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0));
}

int LastDayOfMonth(int month, int year = 0) {
  switch (month) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      return 31;
    case 4:
    case 6:
    case 9:
    case 11:
      return 30;
    case 2:
      if (LeapYear(year))
        return 29;
      else
        return 28;
    default:
      return 0;
  }
}

bool ValidDate(int month, int day, int year) {
  if (month < 1 || month > 12 || day < 1 || day > LastDayOfMonth(month, year))
    return false;
  else
    return true;
}

void NextDate(int &month, int &day, int &year) {
  int last_day_of_month = LastDayOfMonth(month, year);
  if (day < last_day_of_month) {
    day++;
  } else {
    day = 1;
    if (month < 12) {
      month++;
    } else {
      month = 1;
      year++;
    }
  }
}

void PreviousDate(int &month, int &day, int &year) {
  if (day > 1) {
    day--;
  } else {
    if (month > 1) {
      month--;
      day = LastDayOfMonth(month, year);
    } else {
      month = 12;
      day = 31;
      year--;
    }
  }
}
