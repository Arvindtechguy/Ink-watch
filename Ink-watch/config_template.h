/*
 * Configuration Template for Ink-watch
 * 
 * Copy this file to config.h and customize for your setup
 * DO NOT commit your personal config.h file
 */

#ifndef CONFIG_H
#define CONFIG_H

// ============================================
// DISPLAY CONFIGURATION
// ============================================

// Select your display type (uncomment ONE):
// #define DISPLAY_WAVESHARE_154_V2    // Waveshare 1.54" v2
// #define DISPLAY_WAVESHARE_213_V2    // Waveshare 2.13" v2
// #define DISPLAY_ADAFRUIT_154        // Adafruit 1.54"
#define DISPLAY_CUSTOM                 // Custom/Generic display

// Display dimensions (pixels)
#define DISPLAY_WIDTH 200
#define DISPLAY_HEIGHT 200

// Display refresh settings
#define DISPLAY_FULL_REFRESH_INTERVAL 60000  // Full refresh every 60 seconds
#define DISPLAY_PARTIAL_REFRESH true         // Enable partial refresh if supported

// ============================================
// PIN CONFIGURATION
// ============================================

// E-Ink Display Pins (SPI)
#define EPD_CS_PIN 10
#define EPD_DC_PIN 9
#define EPD_RST_PIN 8
#define EPD_BUSY_PIN 7

// Button Pins
#define BUTTON_UP 2
#define BUTTON_DOWN 3
#define BUTTON_SELECT 4
#define BUTTON_BACK 5

// Analog Pins
#define BATTERY_PIN A0

// Optional Pins
#define VIBRATION_PIN 6      // Vibration motor (optional)
#define BUZZER_PIN 7         // Piezo buzzer (optional)
#define LED_PIN 13           // Status LED (optional)

// ============================================
// RTC CONFIGURATION
// ============================================

// Select RTC type (uncomment ONE):
#define RTC_DS3231              // DS3231 (recommended)
// #define RTC_DS1307           // DS1307 (basic)
// #define RTC_PCF8523          // PCF8523 (low power)

// RTC I2C Address
#define RTC_I2C_ADDRESS 0x68

// ============================================
// POWER MANAGEMENT
// ============================================

// Battery monitoring
#define BATTERY_VOLTAGE_DIVIDER_RATIO 2.0  // Adjust based on your resistor values
#define BATTERY_MIN_VOLTAGE 3.3            // Minimum safe voltage
#define BATTERY_MAX_VOLTAGE 4.2            // Maximum charge voltage

// Sleep mode settings
#define ENABLE_SLEEP_MODE true
#define SLEEP_TIMEOUT 30000                // Sleep after 30 seconds of inactivity
#define WAKE_ON_BUTTON true                // Wake on button press

// Power saving
#define DISABLE_LED_IN_SLEEP true
#define REDUCE_CLOCK_SPEED false           // Reduce CPU speed in sleep

// ============================================
// FEATURE CONFIGURATION
// ============================================

// Enable/disable features
#define FEATURE_CLOCK true
#define FEATURE_GAMES true
#define FEATURE_SNAKE true
#define FEATURE_PONG true
#define FEATURE_BATTERY_MONITOR true
#define FEATURE_SETTINGS true

// Future features (not yet implemented)
#define FEATURE_ALARMS false
#define FEATURE_TIMER false
#define FEATURE_STOPWATCH false
#define FEATURE_WEATHER false
#define FEATURE_NOTIFICATIONS false

// ============================================
// GAME CONFIGURATION
// ============================================

// Snake game settings
#define SNAKE_GRID_SIZE 20
#define SNAKE_SPEED 300                    // Milliseconds per move
#define SNAKE_INITIAL_LENGTH 3

// Pong game settings
#define PONG_WIDTH 40
#define PONG_HEIGHT 20
#define PONG_AI_DIFFICULTY 3               // 1=hard, 5=easy

// ============================================
// UI CONFIGURATION
// ============================================

// Menu settings
#define MENU_ITEMS 4
#define MENU_TIMEOUT 10000                 // Return to clock after 10s

// Display settings
#define SHOW_SECONDS true                  // Show seconds on clock
#define CLOCK_FORMAT_24H true              // true=24h, false=12h
#define DATE_FORMAT_DMY true               // true=DD/MM, false=MM/DD

// Animations
#define ENABLE_ANIMATIONS false            // Screen transitions (slow on e-ink)
#define ANIMATION_SPEED 50

// ============================================
// DEBUGGING
// ============================================

// Debug output
#define DEBUG_ENABLED true
#define DEBUG_SERIAL_BAUD 9600
#define DEBUG_VERBOSE false                // Extra debug info

// Debug features
#define DEBUG_BUTTON_STATES false
#define DEBUG_DISPLAY_UPDATES false
#define DEBUG_BATTERY_READINGS false
#define DEBUG_GAME_STATE false

// Performance monitoring
#define MONITOR_LOOP_TIME false
#define MONITOR_MEMORY_USAGE false

// ============================================
// ADVANCED SETTINGS
// ============================================

// Button debounce
#define BUTTON_DEBOUNCE_DELAY 200          // Milliseconds

// SPI Settings
#define SPI_SPEED 4000000                  // 4MHz (adjust if needed)

// I2C Settings
#define I2C_SPEED 100000                   // 100kHz standard mode

// Watchdog timer
#define ENABLE_WATCHDOG false
#define WATCHDOG_TIMEOUT 8000              // 8 seconds

// ============================================
// MACROS AND HELPERS
// ============================================

#if DEBUG_ENABLED
  #define DEBUG_PRINT(x) Serial.print(x)
  #define DEBUG_PRINTLN(x) Serial.println(x)
#else
  #define DEBUG_PRINT(x)
  #define DEBUG_PRINTLN(x)
#endif

#if DEBUG_VERBOSE
  #define VERBOSE_PRINT(x) Serial.print(x)
  #define VERBOSE_PRINTLN(x) Serial.println(x)
#else
  #define VERBOSE_PRINT(x)
  #define VERBOSE_PRINTLN(x)
#endif

// ============================================
// VALIDATION
// ============================================

// Check for conflicting configurations
#if !FEATURE_CLOCK && !FEATURE_GAMES
  #error "At least one feature must be enabled"
#endif

#if DISPLAY_WIDTH < 100 || DISPLAY_HEIGHT < 100
  #warning "Display resolution seems low, some features may not work well"
#endif

#if SNAKE_GRID_SIZE * 10 > DISPLAY_WIDTH
  #warning "Snake grid may be too large for display"
#endif

#endif // CONFIG_H
