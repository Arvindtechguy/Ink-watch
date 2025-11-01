/*
 * Ink-watch - E-ink Display Watch with Arduino
 * 
 * A smartwatch project featuring:
 * - E-ink display for low power consumption
 * - Real-time clock functionality
 * - Built-in games (Snake, Pong)
 * - Menu-driven interface
 * - Battery monitoring
 * 
 * Author: Arvindtechguy
 * License: MIT
 */

#include <Wire.h>
#include <SPI.h>

// Pin definitions
#define BUTTON_UP 2
#define BUTTON_DOWN 3
#define BUTTON_SELECT 4
#define BUTTON_BACK 5
#define BATTERY_PIN A0

// Display settings (adjust based on your e-ink display)
#define DISPLAY_WIDTH 200
#define DISPLAY_HEIGHT 200

// Menu states
enum MenuState {
  MENU_CLOCK,
  MENU_GAMES,
  MENU_SETTINGS,
  MENU_BATTERY,
  GAME_SNAKE,
  GAME_PONG
};

// Global variables
MenuState currentState = MENU_CLOCK;
int menuSelection = 0;
unsigned long lastUpdate = 0;
unsigned long lastButtonPress = 0;
const unsigned long DEBOUNCE_DELAY = 200;

// Clock variables
int hours = 12;
int minutes = 0;
int seconds = 0;

void setup() {
  Serial.begin(9600);
  
  // Initialize buttons
  pinMode(BUTTON_UP, INPUT_PULLUP);
  pinMode(BUTTON_DOWN, INPUT_PULLUP);
  pinMode(BUTTON_SELECT, INPUT_PULLUP);
  pinMode(BUTTON_BACK, INPUT_PULLUP);
  
  // Initialize battery monitoring
  pinMode(BATTERY_PIN, INPUT);
  
  // Initialize display (placeholder for actual e-ink initialization)
  initDisplay();
  
  Serial.println("Ink-watch initialized!");
  displayClock();
}

void loop() {
  unsigned long currentTime = millis();
  
  // Handle button inputs
  handleButtons();
  
  // Update display based on current state
  switch (currentState) {
    case MENU_CLOCK:
      updateClock();
      break;
    case MENU_GAMES:
      displayGameMenu();
      break;
    case MENU_SETTINGS:
      displaySettings();
      break;
    case MENU_BATTERY:
      displayBattery();
      break;
    case GAME_SNAKE:
      runSnakeGame();
      break;
    case GAME_PONG:
      runPongGame();
      break;
  }
  
  // Small delay to prevent excessive CPU usage
  delay(10);
}

void initDisplay() {
  // Placeholder for e-ink display initialization
  // This will depend on your specific e-ink display module
  // Common options: Waveshare, Adafruit, Good Display
  Serial.println("Display initialized");
}

void handleButtons() {
  unsigned long currentTime = millis();
  
  if (currentTime - lastButtonPress < DEBOUNCE_DELAY) {
    return;
  }
  
  if (digitalRead(BUTTON_UP) == LOW) {
    lastButtonPress = currentTime;
    handleUpButton();
  }
  else if (digitalRead(BUTTON_DOWN) == LOW) {
    lastButtonPress = currentTime;
    handleDownButton();
  }
  else if (digitalRead(BUTTON_SELECT) == LOW) {
    lastButtonPress = currentTime;
    handleSelectButton();
  }
  else if (digitalRead(BUTTON_BACK) == LOW) {
    lastButtonPress = currentTime;
    handleBackButton();
  }
}

void handleUpButton() {
  if (currentState == MENU_CLOCK) {
    menuSelection = (menuSelection - 1 + 4) % 4;
    displayMainMenu();
  }
  Serial.println("UP");
}

void handleDownButton() {
  if (currentState == MENU_CLOCK) {
    menuSelection = (menuSelection + 1) % 4;
    displayMainMenu();
  }
  Serial.println("DOWN");
}

void handleSelectButton() {
  switch (menuSelection) {
    case 0:
      currentState = MENU_CLOCK;
      displayClock();
      break;
    case 1:
      currentState = MENU_GAMES;
      displayGameMenu();
      break;
    case 2:
      currentState = MENU_SETTINGS;
      displaySettings();
      break;
    case 3:
      currentState = MENU_BATTERY;
      displayBattery();
      break;
  }
  Serial.println("SELECT");
}

void handleBackButton() {
  currentState = MENU_CLOCK;
  displayClock();
  Serial.println("BACK");
}

void updateClock() {
  unsigned long currentTime = millis();
  
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
    
    displayClock();
  }
}

void displayClock() {
  // Placeholder for e-ink display update
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

void displayMainMenu() {
  Serial.println("=== MAIN MENU ===");
  Serial.println(menuSelection == 0 ? "> Clock" : "  Clock");
  Serial.println(menuSelection == 1 ? "> Games" : "  Games");
  Serial.println(menuSelection == 2 ? "> Settings" : "  Settings");
  Serial.println(menuSelection == 3 ? "> Battery" : "  Battery");
}

void displayGameMenu() {
  Serial.println("=== GAMES ===");
  Serial.println("1. Snake");
  Serial.println("2. Pong");
  Serial.println("Press BACK to return");
}

void displaySettings() {
  Serial.println("=== SETTINGS ===");
  Serial.println("Time format: 24h");
  Serial.println("Display mode: Normal");
  Serial.println("Press BACK to return");
}

void displayBattery() {
  int batteryValue = analogRead(BATTERY_PIN);
  float voltage = batteryValue * (5.0 / 1023.0);
  int percentage = map(batteryValue, 0, 1023, 0, 100);
  
  Serial.println("=== BATTERY ===");
  Serial.print("Voltage: ");
  Serial.print(voltage);
  Serial.println("V");
  Serial.print("Level: ");
  Serial.print(percentage);
  Serial.println("%");
}

void runSnakeGame() {
  Serial.println("Snake game running...");
  // Snake game implementation placeholder
}

void runPongGame() {
  Serial.println("Pong game running...");
  // Pong game implementation placeholder
}
