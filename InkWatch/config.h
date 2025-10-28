/*
 * Configuration file for Ink-watch
 */

#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>

// System states
enum SystemState {
  STATE_CLOCK,
  STATE_MENU,
  STATE_GAME_SNAKE,
  STATE_GAME_PONG,
  STATE_SETTINGS
};

// Pin definitions - Adjust based on your hardware
#define BTN_SELECT 2
#define BTN_UP 3
#define BTN_DOWN 4
#define BTN_BACK 5

// E-ink display pins (SPI)
#define EPD_CS 10
#define EPD_DC 9
#define EPD_RST 8
#define EPD_BUSY 7

// Display dimensions (adjust for your e-ink display)
#define DISPLAY_WIDTH 128
#define DISPLAY_HEIGHT 250

// Timing constants
#define CLOCK_UPDATE_INTERVAL 60000  // Update clock every minute
#define MENU_UPDATE_INTERVAL 100     // Menu refresh rate
#define GAME_UPDATE_INTERVAL 200     // Game refresh rate
#define BUTTON_CHECK_INTERVAL 50     // Check buttons every 50ms
#define DEBOUNCE_DELAY 200           // Button debounce delay

// Menu items
#define MENU_ITEMS 4
const char* menuItems[MENU_ITEMS] = {
  "Clock",
  "Snake Game",
  "Pong Game",
  "Settings"
};

// Game constants
#define SNAKE_SIZE 3
#define SNAKE_MAX_LENGTH 50
#define PONG_PADDLE_HEIGHT 15
#define PONG_BALL_SIZE 3

#endif
