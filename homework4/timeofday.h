// Minh My Tran - CSCE 240

#ifndef _TIMEOFDAY_H_
#define _TIMEOFDAY_H_

class TimeOfDay {
  private:
    int hour_;
    int minute_;
    int second_;

  public:
    TimeOfDay(int hour = 0, int minute = 0, int second = 0);
    void Print(bool military_time = false, bool display_seconds = false) const;
    void SetHour(int hour);
    void SetMinute(int minute);
    void SetSecond(int second);
    int GetHour() const;
    int GetMinute() const;
    int GetSecond() const;
    bool operator<(const TimeOfDay& other) const;
};

#endif // _TIMEOFDAY_H_