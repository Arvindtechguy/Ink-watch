/*
 * Example: Basic Clock Configuration
 * 
 * This example demonstrates a minimal Ink-watch setup
 * with just the clock functionality - no games or extras.
 * Perfect for testing your hardware setup.
 */

#include <Wire.h>
#include <SPI.h>

// Pin definitions - adjust for your setup
#define BUTTON_UP 2
#define BUTTON_DOWN 3
#define BUTTON_SELECT 4
#define BUTTON_BACK 5

// Simplified clock variables
int hours = 12;
int minutes = 0;
int seconds = 0;
unsigned long lastUpdate = 0;

void setup() {
  Serial.begin(9600);
  
  // Initialize buttons with internal pull-ups
  pinMode(BUTTON_UP, INPUT_PULLUP);
  pinMode(BUTTON_DOWN, INPUT_PULLUP);
  pinMode(BUTTON_SELECT, INPUT_PULLUP);
  pinMode(BUTTON_BACK, INPUT_PULLUP);
  
  Serial.println("=== Ink-watch Clock Demo ===");
  Serial.println("Use UP/DOWN to adjust hours");
  Serial.println("Use SELECT to toggle format");
  displayTime();
}

void loop() {
  unsigned long currentTime = millis();
  
  // Update clock every second
  if (currentTime - lastUpdate >= 1000) {
    lastUpdate = currentTime;
    
    seconds++;
    if (seconds >= 60) {
      seconds = 0;
      minutes++;
      
      if (minutes >= 60) {
        minutes = 0;
        hours++;
        
        if (hours >= 24) {
          hours = 0;
        }
      }
    }
    
    displayTime();
  }
  
  // Handle button inputs for time adjustment
  if (digitalRead(BUTTON_UP) == LOW) {
    hours = (hours + 1) % 24;
    displayTime();
    delay(200); // Debounce
  }
  
  if (digitalRead(BUTTON_DOWN) == LOW) {
    hours = (hours - 1 + 24) % 24;
    displayTime();
    delay(200); // Debounce
  }
  
  delay(10);
}

void displayTime() {
  Serial.print("Time: ");
  if (hours < 10) Serial.print("0");
  Serial.print(hours);
  Serial.print(":");
  if (minutes < 10) Serial.print("0");
  Serial.print(minutes);
  Serial.print(":");
  if (seconds < 10) Serial.print("0");
  Serial.println(seconds);
}
