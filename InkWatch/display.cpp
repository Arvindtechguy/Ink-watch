/*
 * Display driver implementation
 */

#include "display.h"

// Display buffer
uint8_t displayBuffer[BUFFER_SIZE];

// Simple 5x7 font for basic characters
const uint8_t font5x7[][5] = {
  {0x00, 0x00, 0x00, 0x00, 0x00}, // Space
  {0x00, 0x00, 0x5F, 0x00, 0x00}, // !
  {0x00, 0x07, 0x00, 0x07, 0x00}, // "
  {0x14, 0x7F, 0x14, 0x7F, 0x14}, // #
  {0x24, 0x2A, 0x7F, 0x2A, 0x12}, // $
  {0x23, 0x13, 0x08, 0x64, 0x62}, // %
  {0x36, 0x49, 0x56, 0x20, 0x50}, // &
  {0x00, 0x08, 0x07, 0x03, 0x00}, // '
  {0x00, 0x1C, 0x22, 0x41, 0x00}, // (
  {0x00, 0x41, 0x22, 0x1C, 0x00}, // )
  {0x2A, 0x1C, 0x7F, 0x1C, 0x2A}, // *
  {0x08, 0x08, 0x3E, 0x08, 0x08}, // +
  {0x00, 0x80, 0x70, 0x30, 0x00}, // ,
  {0x08, 0x08, 0x08, 0x08, 0x08}, // -
  {0x00, 0x00, 0x60, 0x60, 0x00}, // .
  {0x20, 0x10, 0x08, 0x04, 0x02}, // /
  {0x3E, 0x51, 0x49, 0x45, 0x3E}, // 0
  {0x00, 0x42, 0x7F, 0x40, 0x00}, // 1
  {0x72, 0x49, 0x49, 0x49, 0x46}, // 2
  {0x21, 0x41, 0x49, 0x4D, 0x33}, // 3
  {0x18, 0x14, 0x12, 0x7F, 0x10}, // 4
  {0x27, 0x45, 0x45, 0x45, 0x39}, // 5
  {0x3C, 0x4A, 0x49, 0x49, 0x31}, // 6
  {0x41, 0x21, 0x11, 0x09, 0x07}, // 7
  {0x36, 0x49, 0x49, 0x49, 0x36}, // 8
  {0x46, 0x49, 0x49, 0x29, 0x1E}, // 9
  {0x00, 0x00, 0x14, 0x00, 0x00}, // :
};

void initDisplay() {
  // Initialize SPI pins
  pinMode(EPD_CS, OUTPUT);
  pinMode(EPD_DC, OUTPUT);
  pinMode(EPD_RST, OUTPUT);
  pinMode(EPD_BUSY, INPUT);
  
  // Reset display
  digitalWrite(EPD_RST, LOW);
  delay(200);
  digitalWrite(EPD_RST, HIGH);
  delay(200);
  
  clearDisplay();
  Serial.println(F("Display initialized"));
}

void clearDisplay() {
  memset(displayBuffer, 0xFF, BUFFER_SIZE); // White
}

void updateDisplayBuffer() {
  // In a real implementation, this would send the buffer to the e-ink display
  // For now, we'll just simulate it
  // This would use SPI to communicate with the display controller
  Serial.println(F("Display updated"));
}

void drawPixel(int x, int y, bool color) {
  if (x < 0 || x >= DISPLAY_WIDTH || y < 0 || y >= DISPLAY_HEIGHT) {
    return;
  }
  
  int index = (y * DISPLAY_WIDTH + x) / 8;
  int bit = 7 - (x % 8);
  
  if (color) {
    displayBuffer[index] &= ~(1 << bit); // Black
  } else {
    displayBuffer[index] |= (1 << bit);  // White
  }
}

void drawLine(int x0, int y0, int x1, int y1, bool color) {
  int dx = abs(x1 - x0);
  int dy = abs(y1 - y0);
  int sx = x0 < x1 ? 1 : -1;
  int sy = y0 < y1 ? 1 : -1;
  int err = dx - dy;
  
  while (true) {
    drawPixel(x0, y0, color);
    
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

void drawRect(int x, int y, int w, int h, bool color) {
  drawLine(x, y, x + w - 1, y, color);
  drawLine(x + w - 1, y, x + w - 1, y + h - 1, color);
  drawLine(x + w - 1, y + h - 1, x, y + h - 1, color);
  drawLine(x, y + h - 1, x, y, color);
}

void drawFilledRect(int x, int y, int w, int h, bool color) {
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      drawPixel(x + j, y + i, color);
    }
  }
}

void drawChar(int x, int y, char c, bool color) {
  if (c < ' ' || c > ':') return;
  
  int index = c - ' ';
  for (int i = 0; i < 5; i++) {
    uint8_t line = font5x7[index][i];
    for (int j = 0; j < 8; j++) {
      if (line & (1 << j)) {
        drawPixel(x + i, y + j, color);
      }
    }
  }
}

void drawString(int x, int y, const char* str, bool color) {
  int cursorX = x;
  while (*str) {
    drawChar(cursorX, y, *str, color);
    cursorX += 6;
    str++;
  }
}

void drawLargeDigit(int x, int y, int digit, bool color) {
  // Draw a large digit (scaled 3x)
  if (digit < 0 || digit > 9) return;
  
  int index = digit + 16; // '0' is at index 16 in font5x7
  for (int i = 0; i < 5; i++) {
    uint8_t line = font5x7[index][i];
    for (int j = 0; j < 8; j++) {
      if (line & (1 << j)) {
        drawFilledRect(x + i * 3, y + j * 3, 3, 3, color);
      }
    }
  }
}

void displayStartup() {
  clearDisplay();
  drawString(20, 50, "Ink-watch", true);
  drawString(15, 70, "Initializing...", true);
  updateDisplayBuffer();
}
