/*
 * Games implementation
 */

#include "games.h"
#include "display.h"

// ===== SNAKE GAME =====
SnakeSegment snake[SNAKE_MAX_LENGTH];
int snakeLength;
int snakeDirection;
int foodX, foodY;
int snakeScore;
bool snakeGameOver;

void initSnakeGame() {
  snakeLength = 3;
  snakeDirection = 1; // Start moving right
  snakeScore = 0;
  snakeGameOver = false;
  
  // Initialize snake in the middle
  snake[0].x = 64;
  snake[0].y = 125;
  snake[1].x = 61;
  snake[1].y = 125;
  snake[2].x = 58;
  snake[2].y = 125;
  
  // Place food
  foodX = random(10, DISPLAY_WIDTH - 10);
  foodY = random(30, DISPLAY_HEIGHT - 30);
  
  Serial.println(F("Snake game initialized"));
}

void updateSnakeGame() {
  if (snakeGameOver) {
    clearDisplay();
    drawString(20, 100, "GAME OVER!", true);
    char scoreStr[20];
    sprintf(scoreStr, "Score: %d", snakeScore);
    drawString(30, 120, scoreStr, true);
    drawString(10, 200, "BACK to menu", true);
    updateDisplayBuffer();
    return;
  }
  
  // Move snake
  for (int i = snakeLength - 1; i > 0; i--) {
    snake[i] = snake[i - 1];
  }
  
  // Move head based on direction
  switch (snakeDirection) {
    case 0: snake[0].y -= SNAKE_SIZE; break; // Up
    case 1: snake[0].x += SNAKE_SIZE; break; // Right
    case 2: snake[0].y += SNAKE_SIZE; break; // Down
    case 3: snake[0].x -= SNAKE_SIZE; break; // Left
  }
  
  // Check wall collision
  if (snake[0].x < 0 || snake[0].x >= DISPLAY_WIDTH ||
      snake[0].y < 30 || snake[0].y >= DISPLAY_HEIGHT) {
    snakeGameOver = true;
    return;
  }
  
  // Check self collision
  for (int i = 1; i < snakeLength; i++) {
    if (snake[0].x == snake[i].x && snake[0].y == snake[i].y) {
      snakeGameOver = true;
      return;
    }
  }
  
  // Check food collision
  if (abs(snake[0].x - foodX) < SNAKE_SIZE && 
      abs(snake[0].y - foodY) < SNAKE_SIZE) {
    snakeScore += 10;
    if (snakeLength < SNAKE_MAX_LENGTH) {
      snakeLength++;
    }
    // New food position
    foodX = random(10, DISPLAY_WIDTH - 10);
    foodY = random(30, DISPLAY_HEIGHT - 30);
  }
  
  // Draw
  clearDisplay();
  
  // Score
  char scoreStr[20];
  sprintf(scoreStr, "Score: %d", snakeScore);
  drawString(5, 5, scoreStr, true);
  drawLine(0, 28, DISPLAY_WIDTH, 28, true);
  
  // Snake
  for (int i = 0; i < snakeLength; i++) {
    drawFilledRect(snake[i].x, snake[i].y, SNAKE_SIZE, SNAKE_SIZE, true);
  }
  
  // Food
  drawFilledRect(foodX, foodY, SNAKE_SIZE, SNAKE_SIZE, true);
  drawRect(foodX - 1, foodY - 1, SNAKE_SIZE + 2, SNAKE_SIZE + 2, true);
  
  updateDisplayBuffer();
}

void handleSnakeInput(bool up, bool down, bool select, bool back) {
  if (snakeGameOver && select) {
    initSnakeGame();
    return;
  }
  
  if (up && snakeDirection != 2) snakeDirection = 0;
  if (down && snakeDirection != 0) snakeDirection = 2;
  
  // Left/right could be mapped to select for turning
  static bool lastSelect = false;
  if (select && !lastSelect) {
    // Rotate direction clockwise
    snakeDirection = (snakeDirection + 1) % 4;
  }
  lastSelect = select;
}

// ===== PONG GAME =====
int paddleY;
int ballX, ballY;
int ballDX, ballDY;
int pongScore;
bool pongGameOver;

void initPongGame() {
  paddleY = DISPLAY_HEIGHT / 2 - PONG_PADDLE_HEIGHT / 2;
  ballX = DISPLAY_WIDTH / 2;
  ballY = DISPLAY_HEIGHT / 2;
  ballDX = 2;
  ballDY = 2;
  pongScore = 0;
  pongGameOver = false;
  
  Serial.println(F("Pong game initialized"));
}

void updatePongGame() {
  if (pongGameOver) {
    clearDisplay();
    drawString(20, 100, "GAME OVER!", true);
    char scoreStr[20];
    sprintf(scoreStr, "Score: %d", pongScore);
    drawString(30, 120, scoreStr, true);
    drawString(10, 200, "BACK to menu", true);
    updateDisplayBuffer();
    return;
  }
  
  // Move ball
  ballX += ballDX;
  ballY += ballDY;
  
  // Ball collision with top/bottom
  if (ballY <= 30 || ballY >= DISPLAY_HEIGHT - PONG_BALL_SIZE) {
    ballDY = -ballDY;
  }
  
  // Ball collision with paddle
  if (ballX <= 8 && 
      ballY >= paddleY && 
      ballY <= paddleY + PONG_PADDLE_HEIGHT) {
    ballDX = -ballDX;
    pongScore += 10;
    
    // Increase difficulty
    if (abs(ballDX) < 4) {
      ballDX = ballDX > 0 ? ballDX + 1 : ballDX - 1;
    }
  }
  
  // Ball collision with right wall (bounce back)
  if (ballX >= DISPLAY_WIDTH - PONG_BALL_SIZE) {
    ballDX = -ballDX;
  }
  
  // Ball missed by paddle
  if (ballX < 0) {
    pongGameOver = true;
    return;
  }
  
  // Draw
  clearDisplay();
  
  // Score
  char scoreStr[20];
  sprintf(scoreStr, "Score: %d", pongScore);
  drawString(5, 5, scoreStr, true);
  drawLine(0, 28, DISPLAY_WIDTH, 28, true);
  
  // Paddle
  drawFilledRect(3, paddleY, 3, PONG_PADDLE_HEIGHT, true);
  
  // Ball
  drawFilledRect(ballX, ballY, PONG_BALL_SIZE, PONG_BALL_SIZE, true);
  
  updateDisplayBuffer();
}

void handlePongInput(bool up, bool down, bool select, bool back) {
  if (pongGameOver && select) {
    initPongGame();
    return;
  }
  
  if (up && paddleY > 30) {
    paddleY -= 5;
  }
  if (down && paddleY < DISPLAY_HEIGHT - PONG_PADDLE_HEIGHT) {
    paddleY += 5;
  }
}

// ===== SETTINGS =====
void displaySettings() {
  clearDisplay();
  
  drawString(30, 10, "SETTINGS", true);
  drawLine(10, 25, 118, 25, true);
  
  drawString(10, 40, "Time: Set RTC", true);
  drawString(10, 60, "Display: E-ink", true);
  drawString(10, 80, "Version: 1.0", true);
  
  drawString(10, 220, "BACK to menu", true);
  
  updateDisplayBuffer();
}
