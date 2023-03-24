// Minh My Tran - CSCE 240

#ifndef _TIMEINTERVAL_H
#define _TIMEINTERVAL_H

#include "timeofday.h"

class TimeInterval {
  private:
    TimeOfDay start_;
    TimeOfDay end_;

   public:
    TimeInterval();
    TimeInterval(const TimeOfDay& start_time_of_day,
                 const TimeOfDay& end_time_of_day);
    TimeInterval(const TimeOfDay& start_time_of_day,
                 int length,
                 const std::string& units);
    void Print(bool military_time = false, bool display_seconds = false) const;
    TimeOfDay GetStartTime() const;
    TimeOfDay GetEndTime() const;
    void SetStartTime(const TimeOfDay& start_time_of_day);
    void SetEndTime(const TimeOfDay& end_time_of_day);
    void SetEndTime(int length, const std::string &units);
    
};

#endif // _TIMEINTERVAL_H_