// Minh My Tran - CSCE 240 003

#include <iostream>
#include "program2functions.cc"

using std::cin;
using std::cout;
using std::endl;

int main()
{
  int month1, day1, year1;
  int month2, day2, year2;
  char slash1, slash2;

  cin >> month1 >> slash1 >> day1 >> slash2 >> year1;
  cin >> month2 >> slash1 >> day2 >> slash2 >> year2;

  int m1 = month1, d1 = day1, y1 = year1;
  int m2 = month2, d2 = day2, y2 = year2;

  if (!ValidDate(month1, day1, year1) && !ValidDate(month2, day2, year2))
  {
    cout << month1 << "/" << day1 << "/" << year1 << " is not a valid date" << endl;
    cout << month2 << "/" << day2 << "/" << year2 << " is not a valid date" << endl;
    return 0;
  }
  else if (!ValidDate(month1, day1, year1))
  {
    cout << month1 << "/" << day1 << "/" << year1 << " is not a valid date" << endl;
    return 0;
  }
  else if (!ValidDate(month2, day2, year2))
  {
    cout << month2 << "/" << day2 << "/" << year2 << " is not a valid date" << endl;
    return 0;
  }

  int daysBetween = 0;
  if ((year1 < year2) || (year1 == year2 && month1 < month2) || (day1 < day2 && month1 == month2 && year1 == year2))
  {
    while (month1 != month2 || day1 != day2 || year1 != year2)
    {
      NextDate(month1, day1, year1);
      daysBetween++;
      if (month1 == month2 && day1 == day2 && year1 == year2)
      {
        break;
      }
      PreviousDate(month2, day2, year2);
      daysBetween++;
    }
  }
  else
  {
    while (month1 != month2 || day1 != day2 || year1 != year2)
    {
      PreviousDate(month1, day1, year1);
      daysBetween--;
      if (month1 == month2 && day1 == day2 && year1 == year2)
      {
        break;
      }
      NextDate(month2, day2, year2);
      daysBetween--;
    }
  }

  if (daysBetween == 0)
  {
    cout << m1 << "/" << d1 << "/" << y1 << " is 0 days before "
         << m2 << "/" << d2 << "/" << y2 << endl;
  }
  else if (daysBetween > 0)
  {
    cout << m1 << "/" << d1 << "/" << y1 << " is " << daysBetween
         << " days before " << m2 << "/" << d2 << "/" << y2 << endl;
  }
  else
  {
    cout << m1 << "/" << d1 << "/" << y1 << " is " << -daysBetween
         << " days after " << m2 << "/" << d2 << "/" << y2 << endl;
  }

  return 0;
}
