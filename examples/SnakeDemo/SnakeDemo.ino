/*
 * Example: Snake Game Demo
 * 
 * Standalone demo of the Snake game
 * Uses Serial Monitor for display
 */

#include "snake_game.h"

#define BUTTON_UP 2
#define BUTTON_DOWN 3
#define BUTTON_SELECT 4
#define BUTTON_BACK 5

SnakeGame game;
unsigned long lastDraw = 0;

void setup() {
  Serial.begin(9600);
  
  pinMode(BUTTON_UP, INPUT_PULLUP);
  pinMode(BUTTON_DOWN, INPUT_PULLUP);
  pinMode(BUTTON_SELECT, INPUT_PULLUP);
  pinMode(BUTTON_BACK, INPUT_PULLUP);
  
  Serial.println("=== Snake Game Demo ===");
  Serial.println("Controls:");
  Serial.println("UP/DOWN - Change direction");
  Serial.println("SELECT - Restart");
  Serial.println("BACK - Exit");
  Serial.println();
  
  randomSeed(analogRead(0));
  game.reset();
}

void loop() {
  unsigned long currentTime = millis();
  
  // Handle input
  if (digitalRead(BUTTON_UP) == LOW) {
    game.handleInput(0); // UP
    delay(100);
  }
  if (digitalRead(BUTTON_DOWN) == LOW) {
    game.handleInput(1); // DOWN
    delay(100);
  }
  if (digitalRead(BUTTON_SELECT) == LOW) {
    Serial.println("\n=== Restarting Game ===\n");
    game.reset();
    delay(300);
  }
  if (digitalRead(BUTTON_BACK) == LOW) {
    Serial.println("\n=== Game Exited ===");
    while(true) { delay(1000); }
  }
  
  // Update game
  game.update(currentTime);
  
  // Draw every 500ms
  if (currentTime - lastDraw >= 500) {
    lastDraw = currentTime;
    Serial.print("\033[2J\033[H"); // Clear screen (may not work on all terminals)
    game.draw();
  }
}
