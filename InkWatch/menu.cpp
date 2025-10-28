/*
 * Menu system implementation
 */

#include "menu.h"
#include "display.h"

int currentMenuItem = 0;

void initMenu() {
  currentMenuItem = 0;
}

void displayMenu() {
  clearDisplay();
  
  // Title
  drawString(30, 10, "MENU", true);
  drawLine(10, 25, 118, 25, true);
  
  // Menu items
  int yPos = 40;
  for (int i = 0; i < MENU_ITEMS; i++) {
    if (i == currentMenuItem) {
      // Highlight selected item
      drawFilledRect(5, yPos - 2, 118, 12, true);
      drawString(10, yPos, menuItems[i], false);
    } else {
      drawString(10, yPos, menuItems[i], true);
    }
    yPos += 20;
  }
  
  // Instructions
  drawLine(10, 200, 118, 200, true);
  drawString(10, 210, "UP/DOWN: Navigate", true);
  drawString(10, 220, "SELECT: Choose", true);
  drawString(10, 230, "BACK: Exit", true);
  
  updateDisplayBuffer();
}

void menuUp() {
  currentMenuItem--;
  if (currentMenuItem < 0) {
    currentMenuItem = MENU_ITEMS - 1;
  }
}

void menuDown() {
  currentMenuItem++;
  if (currentMenuItem >= MENU_ITEMS) {
    currentMenuItem = 0;
  }
}

SystemState menuSelect() {
  switch (currentMenuItem) {
    case 0: return STATE_CLOCK;
    case 1: return STATE_GAME_SNAKE;
    case 2: return STATE_GAME_PONG;
    case 3: return STATE_SETTINGS;
    default: return STATE_MENU;
  }
}
