// Minh My Tran - CSCE 240

#include <iostream>
#include "timeinterval.h"

TimeInterval::TimeInterval() : start_(0, 0, 0), end_(0, 0, 0) {}

TimeInterval::TimeInterval(const TimeOfDay& start_time_of_day,
                           const TimeOfDay& end_time_of_day) {
 if (end_time_of_day < start_time_of_day) {
    start_ = end_ = start_time_of_day;
  } else {
    start_ = start_time_of_day;
    end_ = end_time_of_day;
  }
}

TimeInterval::TimeInterval(const TimeOfDay &start,int length,const std::string &units){
     this->start_=start; 
     int hour=start_.GetHour(); 
     int minute=start_.GetMinute(); 
     int second=start_.GetSecond(); 

     if(units=="seconds"){
        second+=length; 
        while(second>=60){
            second-=60; 
            minute++; 
        }
        while(minute>=60){
            minute-=60; 
            hour++; 
        }
     }
     else if(units=="minutes"){
        minute+=length; 
        while(minute>=60){
            minute-=60; 
            hour++; 
        }
     }
     else if(units=="hours"){
         hour+=length;  
     }

     if(hour<24){
         this->end_=TimeOfDay(hour,minute,second);  
     }else{
         this->end_=this->start_;  
     }
}



TimeOfDay TimeInterval::GetStartTime() const {
     return start_; 
}

TimeOfDay TimeInterval::GetEndTime() const { 
    return end_; 
}

void TimeInterval::SetStartTime(const TimeOfDay& new_start) {
   if (!(new_start < GetEndTime())) return; 

   this->start_ = new_start; 
}

void TimeInterval::SetEndTime(const TimeOfDay &new_end){
   if(new_end < GetStartTime()) return; 

   this->end_=new_end; 
}

void TimeInterval::SetEndTime(int length,const std::string &units){
     int hour=start_.GetHour(); 
     int minute=start_.GetMinute(); 
     int second=start_.GetSecond(); 

     if(units=="seconds"){
        second+=length; 
        while(second>=60){
            second-=60; 
            minute++; 
        }
        while(minute>=60){
            minute-=60; 
            hour++; 
        }
     }
     else if(units=="minutes"){
        minute+=length; 
        while(minute>=60){
            minute-=60; 
            hour++; 
        }
     }
     else if(units=="hours"){
         hour+=length;  
     }

     if(hour<24){
         this->end_=TimeOfDay(hour,minute,second);  
     }else{
         this->end_=this->start_;  
     }
}

void TimeInterval::Print(bool military_time,bool display_seconds) const{
   std::cout<<"Start time: ";  
   this->start_.Print(military_time,display_seconds);  
   std::cout<<"End time: ";  
   this->end_.Print(military_time,display_seconds);  
}

