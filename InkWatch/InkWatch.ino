/*
 * Ink-watch - E-ink Display Watch with Arduino
 * 
 * An Arduino-based smartwatch with e-ink display featuring:
 * - Real-time clock
 * - Games (Snake, Pong)
 * - Menu navigation system
 * 
 * Hardware Requirements:
 * - Arduino board (Nano/Uno/ESP32)
 * - E-ink display (2.9" or similar)
 * - RTC module (DS3231 or DS1307)
 * - Buttons for input (3-4 buttons recommended)
 * - Battery management circuit
 */

#include "config.h"
#include "display.h"
#include "rtc_time.h"
#include "menu.h"
#include "games.h"

// System state
SystemState currentState = STATE_CLOCK;
unsigned long lastUpdateTime = 0;
unsigned long lastButtonCheck = 0;

void setup() {
  Serial.begin(9600);
  Serial.println(F("Ink-watch Starting..."));
  
  // Initialize hardware
  initButtons();
  initDisplay();
  initRTC();
  
  // Show startup screen
  displayStartup();
  delay(2000);
  
  Serial.println(F("Initialization complete"));
}

void loop() {
  unsigned long currentTime = millis();
  
  // Check buttons periodically
  if (currentTime - lastButtonCheck >= BUTTON_CHECK_INTERVAL) {
    lastButtonCheck = currentTime;
    handleButtons();
  }
  
  // Update display based on current state
  if (currentTime - lastUpdateTime >= getUpdateInterval()) {
    lastUpdateTime = currentTime;
    updateDisplay();
  }
  
  // Low power delay
  delay(10);
}

// Get update interval based on current state
unsigned long getUpdateInterval() {
  switch (currentState) {
    case STATE_CLOCK:
      return CLOCK_UPDATE_INTERVAL;
    case STATE_MENU:
      return MENU_UPDATE_INTERVAL;
    case STATE_GAME_SNAKE:
    case STATE_GAME_PONG:
      return GAME_UPDATE_INTERVAL;
    default:
      return 1000;
  }
}

// Update display based on current state
void updateDisplay() {
  switch (currentState) {
    case STATE_CLOCK:
      displayClock();
      break;
    case STATE_MENU:
      displayMenu();
      break;
    case STATE_GAME_SNAKE:
      updateSnakeGame();
      break;
    case STATE_GAME_PONG:
      updatePongGame();
      break;
    case STATE_SETTINGS:
      displaySettings();
      break;
  }
}

// Handle button inputs
void handleButtons() {
  static unsigned long lastDebounceTime = 0;
  unsigned long currentTime = millis();
  
  if (currentTime - lastDebounceTime < DEBOUNCE_DELAY) {
    return;
  }
  
  // Read button states
  bool btnSelect = digitalRead(BTN_SELECT) == LOW;
  bool btnUp = digitalRead(BTN_UP) == LOW;
  bool btnDown = digitalRead(BTN_DOWN) == LOW;
  bool btnBack = digitalRead(BTN_BACK) == LOW;
  
  if (btnSelect || btnUp || btnDown || btnBack) {
    lastDebounceTime = currentTime;
    
    switch (currentState) {
      case STATE_CLOCK:
        if (btnSelect) {
          currentState = STATE_MENU;
          initMenu();
        }
        break;
        
      case STATE_MENU:
        if (btnUp) menuUp();
        if (btnDown) menuDown();
        if (btnSelect) {
          SystemState newState = menuSelect();
          if (newState != STATE_MENU) {
            currentState = newState;
            if (newState == STATE_GAME_SNAKE) initSnakeGame();
            if (newState == STATE_GAME_PONG) initPongGame();
          }
        }
        if (btnBack) {
          currentState = STATE_CLOCK;
        }
        break;
        
      case STATE_GAME_SNAKE:
        handleSnakeInput(btnUp, btnDown, btnSelect, btnBack);
        if (btnBack) currentState = STATE_MENU;
        break;
        
      case STATE_GAME_PONG:
        handlePongInput(btnUp, btnDown, btnSelect, btnBack);
        if (btnBack) currentState = STATE_MENU;
        break;
        
      case STATE_SETTINGS:
        if (btnBack) currentState = STATE_MENU;
        break;
    }
  }
}

// Initialize button pins
void initButtons() {
  pinMode(BTN_SELECT, INPUT_PULLUP);
  pinMode(BTN_UP, INPUT_PULLUP);
  pinMode(BTN_DOWN, INPUT_PULLUP);
  pinMode(BTN_BACK, INPUT_PULLUP);
}
