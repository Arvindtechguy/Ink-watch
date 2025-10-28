/*
 * Real-time clock implementation
 */

#include "rtc_time.h"
#include "display.h"

TimeInfo currentTime = {12, 0, 0, 1, 1, 2024, 1};

const char* daysOfWeek[7] = {
  "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"
};

void initRTC() {
  // In a real implementation, this would initialize I2C and communicate with RTC module
  // For now, we'll use a simple counter-based time
  Serial.println(F("RTC initialized"));
  
  // Set default time
  currentTime.hour = 12;
  currentTime.minute = 0;
  currentTime.second = 0;
  currentTime.day = 28;
  currentTime.month = 10;
  currentTime.year = 2025;
  currentTime.dayOfWeek = 2; // Tuesday
}

void updateTime() {
  // In a real implementation, read from RTC module
  // For simulation, increment based on millis()
  static unsigned long lastSecond = 0;
  unsigned long currentMillis = millis();
  
  if (currentMillis - lastSecond >= 1000) {
    lastSecond = currentMillis;
    
    currentTime.second++;
    if (currentTime.second >= 60) {
      currentTime.second = 0;
      currentTime.minute++;
      
      if (currentTime.minute >= 60) {
        currentTime.minute = 0;
        currentTime.hour++;
        
        if (currentTime.hour >= 24) {
          currentTime.hour = 0;
          currentTime.day++;
          currentTime.dayOfWeek = (currentTime.dayOfWeek + 1) % 7;
          
          // Simplified day rollover (doesn't handle different month lengths)
          if (currentTime.day > 31) {
            currentTime.day = 1;
            currentTime.month++;
            
            if (currentTime.month > 12) {
              currentTime.month = 1;
              currentTime.year++;
            }
          }
        }
      }
    }
  }
}

void displayClock() {
  updateTime();
  clearDisplay();
  
  // Draw date
  char dateStr[20];
  sprintf(dateStr, "%s %02d/%02d/%04d", 
          daysOfWeek[currentTime.dayOfWeek],
          currentTime.day, 
          currentTime.month, 
          currentTime.year);
  drawString(10, 20, dateStr, true);
  
  // Draw large time
  int xPos = 15;
  int yPos = 80;
  
  // Hours
  drawLargeDigit(xPos, yPos, currentTime.hour / 10, true);
  drawLargeDigit(xPos + 20, yPos, currentTime.hour % 10, true);
  
  // Colon
  drawFilledRect(xPos + 42, yPos + 10, 3, 3, true);
  drawFilledRect(xPos + 42, yPos + 18, 3, 3, true);
  
  // Minutes
  drawLargeDigit(xPos + 50, yPos, currentTime.minute / 10, true);
  drawLargeDigit(xPos + 70, yPos, currentTime.minute % 10, true);
  
  // Instructions
  drawString(10, 200, "Press SELECT", true);
  drawString(10, 210, "for menu", true);
  
  updateDisplayBuffer();
}

void setTime(uint8_t hour, uint8_t minute, uint8_t second) {
  currentTime.hour = hour;
  currentTime.minute = minute;
  currentTime.second = second;
}

void setDate(uint8_t day, uint8_t month, uint16_t year) {
  currentTime.day = day;
  currentTime.month = month;
  currentTime.year = year;
}
