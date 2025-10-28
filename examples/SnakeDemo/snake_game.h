/*
 * Snake Game for Ink-watch
 * 
 * Classic Snake game optimized for e-ink display
 */

#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H

#include <Arduino.h>

// Game settings
#define SNAKE_GRID_SIZE 20
#define SNAKE_MAX_LENGTH 100
#define SNAKE_INITIAL_LENGTH 3
#define SNAKE_SPEED 300 // milliseconds per move

// Direction enumeration
enum Direction {
  DIR_UP,
  DIR_DOWN,
  DIR_LEFT,
  DIR_RIGHT
};

class SnakeGame {
private:
  struct Point {
    int x;
    int y;
  };
  
  Point snake[SNAKE_MAX_LENGTH];
  Point food;
  int snakeLength;
  Direction currentDirection;
  Direction nextDirection;
  unsigned long lastMove;
  bool gameOver;
  int score;
  
public:
  SnakeGame() {
    reset();
  }
  
  void reset() {
    // Initialize snake in the middle
    snakeLength = SNAKE_INITIAL_LENGTH;
    for (int i = 0; i < snakeLength; i++) {
      snake[i].x = SNAKE_GRID_SIZE / 2 - i;
      snake[i].y = SNAKE_GRID_SIZE / 2;
    }
    
    currentDirection = DIR_RIGHT;
    nextDirection = DIR_RIGHT;
    gameOver = false;
    score = 0;
    lastMove = 0;
    
    spawnFood();
  }
  
  void update(unsigned long currentTime) {
    if (gameOver) return;
    
    if (currentTime - lastMove >= SNAKE_SPEED) {
      lastMove = currentTime;
      currentDirection = nextDirection;
      moveSnake();
    }
  }
  
  void handleInput(int button) {
    // 0: UP, 1: DOWN, 2: LEFT, 3: RIGHT
    switch (button) {
      case 0:
        if (currentDirection != DIR_DOWN) nextDirection = DIR_UP;
        break;
      case 1:
        if (currentDirection != DIR_UP) nextDirection = DIR_DOWN;
        break;
      case 2:
        if (currentDirection != DIR_RIGHT) nextDirection = DIR_LEFT;
        break;
      case 3:
        if (currentDirection != DIR_LEFT) nextDirection = DIR_RIGHT;
        break;
    }
  }
  
  void moveSnake() {
    // Calculate new head position
    Point newHead = snake[0];
    
    switch (currentDirection) {
      case DIR_UP:
        newHead.y--;
        break;
      case DIR_DOWN:
        newHead.y++;
        break;
      case DIR_LEFT:
        newHead.x--;
        break;
      case DIR_RIGHT:
        newHead.x++;
        break;
    }
    
    // Check wall collision
    if (newHead.x < 0 || newHead.x >= SNAKE_GRID_SIZE ||
        newHead.y < 0 || newHead.y >= SNAKE_GRID_SIZE) {
      gameOver = true;
      return;
    }
    
    // Check self collision
    for (int i = 0; i < snakeLength; i++) {
      if (snake[i].x == newHead.x && snake[i].y == newHead.y) {
        gameOver = true;
        return;
      }
    }
    
    // Move snake body
    for (int i = snakeLength - 1; i > 0; i--) {
      snake[i] = snake[i - 1];
    }
    snake[0] = newHead;
    
    // Check food collision
    if (newHead.x == food.x && newHead.y == food.y) {
      if (snakeLength < SNAKE_MAX_LENGTH) {
        snakeLength++;
        score += 10;
      }
      spawnFood();
    }
  }
  
  void spawnFood() {
    bool validPosition = false;
    
    while (!validPosition) {
      food.x = random(SNAKE_GRID_SIZE);
      food.y = random(SNAKE_GRID_SIZE);
      
      validPosition = true;
      for (int i = 0; i < snakeLength; i++) {
        if (snake[i].x == food.x && snake[i].y == food.y) {
          validPosition = false;
          break;
        }
      }
    }
  }
  
  void draw() {
    // Print to serial for debugging
    Serial.println("=== SNAKE GAME ===");
    Serial.print("Score: ");
    Serial.println(score);
    
    for (int y = 0; y < SNAKE_GRID_SIZE; y++) {
      for (int x = 0; x < SNAKE_GRID_SIZE; x++) {
        bool isSnake = false;
        bool isHead = false;
        
        for (int i = 0; i < snakeLength; i++) {
          if (snake[i].x == x && snake[i].y == y) {
            isSnake = true;
            if (i == 0) isHead = true;
            break;
          }
        }
        
        if (isHead) {
          Serial.print("@");
        } else if (isSnake) {
          Serial.print("o");
        } else if (food.x == x && food.y == y) {
          Serial.print("*");
        } else {
          Serial.print(".");
        }
      }
      Serial.println();
    }
    
    if (gameOver) {
      Serial.println("GAME OVER!");
      Serial.print("Final Score: ");
      Serial.println(score);
    }
  }
  
  bool isGameOver() {
    return gameOver;
  }
  
  int getScore() {
    return score;
  }
};

#endif
