/*
 * Real-time clock functions
 */

#ifndef RTC_TIME_H
#define RTC_TIME_H

#include "config.h"

// Time structure
struct TimeInfo {
  uint8_t hour;
  uint8_t minute;
  uint8_t second;
  uint8_t day;
  uint8_t month;
  uint16_t year;
  uint8_t dayOfWeek;
};

extern TimeInfo currentTime;

// RTC functions
void initRTC();
void updateTime();
void displayClock();
void setTime(uint8_t hour, uint8_t minute, uint8_t second);
void setDate(uint8_t day, uint8_t month, uint16_t year);

// Day of week names
extern const char* daysOfWeek[7];

#endif
