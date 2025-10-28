/*
 * E-Ink Display Driver for Ink-watch
 * 
 * Abstract interface for e-ink displays
 * Supports common e-ink display modules:
 * - Waveshare e-Paper displays
 * - Adafruit e-ink displays
 * - Good Display modules
 */

#ifndef EINK_DISPLAY_H
#define EINK_DISPLAY_H

#include <Arduino.h>
#include <SPI.h>

// Display configuration
// Uncomment the line matching your display type
// #define WAVESHARE_1_54_V2
// #define WAVESHARE_2_13_V2
// #define ADAFRUIT_154_MONO

// Default settings (adjust based on your display)
#ifndef DISPLAY_WIDTH
#define DISPLAY_WIDTH 200
#endif

#ifndef DISPLAY_HEIGHT
#define DISPLAY_HEIGHT 200
#endif

// Pin definitions (adjust based on your wiring)
#define EPD_CS_PIN 10
#define EPD_DC_PIN 9
#define EPD_RST_PIN 8
#define EPD_BUSY_PIN 7

class EInkDisplay {
private:
  int width;
  int height;
  uint8_t* frameBuffer;
  
public:
  EInkDisplay() : width(DISPLAY_WIDTH), height(DISPLAY_HEIGHT) {
    // Allocate frame buffer
    int bufferSize = (width * height) / 8;
    frameBuffer = new uint8_t[bufferSize];
    clearBuffer();
  }
  
  ~EInkDisplay() {
    delete[] frameBuffer;
  }
  
  void init() {
    // Initialize SPI
    SPI.begin();
    
    // Initialize pins
    pinMode(EPD_CS_PIN, OUTPUT);
    pinMode(EPD_DC_PIN, OUTPUT);
    pinMode(EPD_RST_PIN, OUTPUT);
    pinMode(EPD_BUSY_PIN, INPUT);
    
    // Hardware reset
    digitalWrite(EPD_RST_PIN, HIGH);
    delay(200);
    digitalWrite(EPD_RST_PIN, LOW);
    delay(10);
    digitalWrite(EPD_RST_PIN, HIGH);
    delay(200);
    
    Serial.println("E-Ink display initialized");
  }
  
  void clearBuffer() {
    int bufferSize = (width * height) / 8;
    memset(frameBuffer, 0xFF, bufferSize); // 0xFF = white
  }
  
  void setPixel(int x, int y, bool black) {
    if (x < 0 || x >= width || y < 0 || y >= height) return;
    
    int byteIndex = (y * width + x) / 8;
    int bitIndex = 7 - (x % 8);
    
    if (black) {
      frameBuffer[byteIndex] &= ~(1 << bitIndex);
    } else {
      frameBuffer[byteIndex] |= (1 << bitIndex);
    }
  }
  
  void drawLine(int x0, int y0, int x1, int y1, bool black) {
    // Bresenham's line algorithm
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = x0 < x1 ? 1 : -1;
    int sy = y0 < y1 ? 1 : -1;
    int err = dx - dy;
    
    while (true) {
      setPixel(x0, y0, black);
      
      if (x0 == x1 && y0 == y1) break;
      
      int e2 = 2 * err;
      if (e2 > -dy) {
        err -= dy;
        x0 += sx;
      }
      if (e2 < dx) {
        err += dx;
        y0 += sy;
      }
    }
  }
  
  void drawRect(int x, int y, int w, int h, bool black, bool filled) {
    if (filled) {
      for (int i = 0; i < h; i++) {
        drawLine(x, y + i, x + w - 1, y + i, black);
      }
    } else {
      drawLine(x, y, x + w - 1, y, black);
      drawLine(x, y + h - 1, x + w - 1, y + h - 1, black);
      drawLine(x, y, x, y + h - 1, black);
      drawLine(x + w - 1, y, x + w - 1, y + h - 1, black);
    }
  }
  
  void drawCircle(int x0, int y0, int radius, bool black) {
    int x = radius;
    int y = 0;
    int err = 0;
    
    while (x >= y) {
      setPixel(x0 + x, y0 + y, black);
      setPixel(x0 + y, y0 + x, black);
      setPixel(x0 - y, y0 + x, black);
      setPixel(x0 - x, y0 + y, black);
      setPixel(x0 - x, y0 - y, black);
      setPixel(x0 - y, y0 - x, black);
      setPixel(x0 + y, y0 - x, black);
      setPixel(x0 + x, y0 - y, black);
      
      if (err <= 0) {
        y += 1;
        err += 2 * y + 1;
      }
      if (err > 0) {
        x -= 1;
        err -= 2 * x + 1;
      }
    }
  }
  
  void drawChar(int x, int y, char c, bool black) {
    // Simple 5x7 character drawing (placeholder)
    // In a real implementation, you would use a font library
    drawRect(x, y, 5, 7, black, false);
  }
  
  void drawString(int x, int y, const char* str, bool black) {
    int cursorX = x;
    while (*str) {
      drawChar(cursorX, y, *str, black);
      cursorX += 6; // 5 pixel width + 1 pixel spacing
      str++;
    }
  }
  
  void drawDigit(int x, int y, int digit, int size, bool black) {
    // Simple 7-segment style digit drawing
    // This is a placeholder - implement with proper font rendering
    char buf[2];
    buf[0] = '0' + digit;
    buf[1] = '\0';
    drawString(x, y, buf, black);
  }
  
  void update() {
    // Send frame buffer to display
    // This is a placeholder - actual implementation depends on your display
    Serial.println("Display updated");
  }
  
  void sleep() {
    // Put display in deep sleep mode to save power
    Serial.println("Display entering sleep mode");
  }
  
  int getWidth() { return width; }
  int getHeight() { return height; }
};

#endif
