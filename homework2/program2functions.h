// Minh My Tran - CSCE 240 003

#ifndef _PROGRAM2FUNCTIONS_H_

#define _PROGRAM2FUNCTIONS_H_

bool LeapYear(int year);
int LastDayOfMonth(int month, int year = 0);
bool ValidDate(int month, int day, int year);
void NextDate(int &month, int &day, int &year);
void PreviousDate(int &month, int &day, int &year);

#endif  // _PROGRAM2FUNCTIONS_H_
