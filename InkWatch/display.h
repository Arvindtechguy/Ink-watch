/*
 * Display driver interface for e-ink display
 */

#ifndef DISPLAY_H
#define DISPLAY_H

#include "config.h"

// Display buffer (1 bit per pixel for e-ink)
// For 128x250 display = 32000 bits = 4000 bytes
#define BUFFER_SIZE ((DISPLAY_WIDTH * DISPLAY_HEIGHT) / 8)

// Simple frame buffer
extern uint8_t displayBuffer[BUFFER_SIZE];

// Display functions
void initDisplay();
void clearDisplay();
void updateDisplayBuffer();
void drawPixel(int x, int y, bool color);
void drawLine(int x0, int y0, int x1, int y1, bool color);
void drawRect(int x, int y, int w, int h, bool color);
void drawFilledRect(int x, int y, int w, int h, bool color);
void drawChar(int x, int y, char c, bool color);
void drawString(int x, int y, const char* str, bool color);
void drawLargeDigit(int x, int y, int digit, bool color);
void displayStartup();

// Simple 5x7 font (you can expand this)
extern const uint8_t font5x7[][5];

#endif
