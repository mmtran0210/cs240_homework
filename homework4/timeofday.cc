// Minh My Tran - CSCE 240

#include "timeofday.h"
#include <iostream>

TimeOfDay::TimeOfDay(int hour, int minute, int second) {
  hour_ = 0;
  minute_ = 0;
  second_ = 0;
  SetHour(hour);
  SetMinute(minute);
  SetSecond(second);
}

void TimeOfDay::Print(bool military_time, bool display_seconds) const {
  int hour = hour_;
  std::string am_pm = "a.m.";
  if (military_time == false) {
    if (hour == 0) {
      hour = 12;
    } else if (hour > 12) {
      hour -= 12;
      am_pm = "p.m.";
    } else if (hour == 12) {
      am_pm = "p.m.";
    }
  }
  std::cout << hour << ":";
  if (minute_ < 10) {
    std::cout << "0";
  }
  std::cout << minute_;
  if (display_seconds) {
    std::cout << ":";
    if (second_ < 10) {
      std::cout << "0";
    }
    std::cout << second_;
  }
  std::cout << " " << am_pm << std::endl;
}

void TimeOfDay::SetHour(int hour) {
  if (hour >= 0 && hour <= 23) {
    hour_ = hour;
  }
}

void TimeOfDay::SetMinute(int minute) {
  if (minute >= 0 && minute <= 59) {
    minute_ = minute;
  }
}

void TimeOfDay::SetSecond(int second) {
  if (second >= 0 && second <= 59) {
    second_ = second;
  }
}

int TimeOfDay::GetHour() const {
  return hour_;
}

int TimeOfDay::GetMinute() const {
  return minute_;
}

int TimeOfDay::GetSecond() const {
  return second_;
}

bool TimeOfDay::operator<(const TimeOfDay& other) const {
  if (hour_ < other.hour_) {
    return true;
  } else if (hour_ == other.hour_) {
    if (minute_ < other.minute_) {
      return true;
    } else if (minute_ == other.minute_) {
      return second_ < other.second_;
    }
  }
  return false;
}