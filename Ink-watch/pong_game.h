/*
 * Pong Game for Ink-watch
 * 
 * Classic Pong game optimized for e-ink display
 * Single-player mode against AI
 */

#ifndef PONG_GAME_H
#define PONG_GAME_H

#include <Arduino.h>

// Game settings
#define PONG_WIDTH 40
#define PONG_HEIGHT 20
#define PADDLE_HEIGHT 4
#define PADDLE_SPEED 1
#define BALL_SPEED 1
#define AI_DIFFICULTY 3 // Higher = easier (AI reaction delay)

class PongGame {
private:
  struct Ball {
    float x;
    float y;
    float vx;
    float vy;
  };
  
  Ball ball;
  int playerPaddle;
  int aiPaddle;
  int playerScore;
  int aiScore;
  unsigned long lastUpdate;
  unsigned long aiLastMove;
  bool gameRunning;
  
public:
  PongGame() {
    reset();
  }
  
  void reset() {
    // Reset ball to center
    ball.x = PONG_WIDTH / 2;
    ball.y = PONG_HEIGHT / 2;
    ball.vx = 1;
    ball.vy = random(0, 2) ? 1 : -1;
    
    // Reset paddles
    playerPaddle = PONG_HEIGHT / 2 - PADDLE_HEIGHT / 2;
    aiPaddle = PONG_HEIGHT / 2 - PADDLE_HEIGHT / 2;
    
    // Reset scores
    playerScore = 0;
    aiScore = 0;
    
    lastUpdate = 0;
    aiLastMove = 0;
    gameRunning = true;
  }
  
  void update(unsigned long currentTime) {
    if (!gameRunning) return;
    
    if (currentTime - lastUpdate >= 100) {
      lastUpdate = currentTime;
      
      // Update ball position
      ball.x += ball.vx * BALL_SPEED;
      ball.y += ball.vy * BALL_SPEED;
      
      // Top and bottom wall collision
      if (ball.y <= 0 || ball.y >= PONG_HEIGHT - 1) {
        ball.vy = -ball.vy;
      }
      
      // Player paddle collision
      if (ball.x <= 1 && ball.y >= playerPaddle && ball.y < playerPaddle + PADDLE_HEIGHT) {
        ball.vx = abs(ball.vx);
        // Add some randomness to ball direction
        ball.vy += (random(-10, 10) / 20.0);
      }
      
      // AI paddle collision
      if (ball.x >= PONG_WIDTH - 2 && ball.y >= aiPaddle && ball.y < aiPaddle + PADDLE_HEIGHT) {
        ball.vx = -abs(ball.vx);
        // Add some randomness to ball direction
        ball.vy += (random(-10, 10) / 20.0);
      }
      
      // Score points
      if (ball.x <= 0) {
        aiScore++;
        resetBall();
      } else if (ball.x >= PONG_WIDTH - 1) {
        playerScore++;
        resetBall();
      }
      
      // Update AI paddle
      updateAI(currentTime);
      
      // Check for game over
      if (playerScore >= 5 || aiScore >= 5) {
        gameRunning = false;
      }
    }
  }
  
  void resetBall() {
    ball.x = PONG_WIDTH / 2;
    ball.y = PONG_HEIGHT / 2;
    ball.vx = random(0, 2) ? 1 : -1;
    ball.vy = random(0, 2) ? 1 : -1;
  }
  
  void updateAI(unsigned long currentTime) {
    if (currentTime - aiLastMove >= 100 * AI_DIFFICULTY) {
      aiLastMove = currentTime;
      
      // Simple AI: follow the ball
      int paddleCenter = aiPaddle + PADDLE_HEIGHT / 2;
      
      if (ball.y < paddleCenter - 1 && aiPaddle > 0) {
        aiPaddle -= PADDLE_SPEED;
      } else if (ball.y > paddleCenter + 1 && aiPaddle < PONG_HEIGHT - PADDLE_HEIGHT) {
        aiPaddle += PADDLE_SPEED;
      }
    }
  }
  
  void movePaddleUp() {
    if (playerPaddle > 0) {
      playerPaddle -= PADDLE_SPEED;
    }
  }
  
  void movePaddleDown() {
    if (playerPaddle < PONG_HEIGHT - PADDLE_HEIGHT) {
      playerPaddle += PADDLE_SPEED;
    }
  }
  
  void draw() {
    // Print to serial for debugging
    Serial.println("=== PONG ===");
    Serial.print("Player: ");
    Serial.print(playerScore);
    Serial.print(" | AI: ");
    Serial.println(aiScore);
    
    for (int y = 0; y < PONG_HEIGHT; y++) {
      for (int x = 0; x < PONG_WIDTH; x++) {
        // Draw borders
        if (y == 0 || y == PONG_HEIGHT - 1) {
          Serial.print("-");
        }
        // Draw player paddle
        else if (x == 0 && y >= playerPaddle && y < playerPaddle + PADDLE_HEIGHT) {
          Serial.print("|");
        }
        // Draw AI paddle
        else if (x == PONG_WIDTH - 1 && y >= aiPaddle && y < aiPaddle + PADDLE_HEIGHT) {
          Serial.print("|");
        }
        // Draw ball
        else if ((int)ball.x == x && (int)ball.y == y) {
          Serial.print("O");
        }
        // Draw center line
        else if (x == PONG_WIDTH / 2 && y % 2 == 0) {
          Serial.print(":");
        }
        else {
          Serial.print(" ");
        }
      }
      Serial.println();
    }
    
    if (!gameRunning) {
      Serial.println("GAME OVER!");
      if (playerScore > aiScore) {
        Serial.println("You Win!");
      } else {
        Serial.println("AI Wins!");
      }
    }
  }
  
  bool isGameRunning() {
    return gameRunning;
  }
  
  int getPlayerScore() {
    return playerScore;
  }
  
  int getAIScore() {
    return aiScore;
  }
};

#endif
