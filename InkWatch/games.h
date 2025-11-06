/*
 * Games module - Snake and Pong
 */

#ifndef GAMES_H
#define GAMES_H

#include "config.h"

// Snake game
struct SnakeSegment {
  int x;
  int y;
};

extern SnakeSegment snake[SNAKE_MAX_LENGTH];
extern int snakeLength;
extern int snakeDirection; // 0=up, 1=right, 2=down, 3=left
extern int foodX, foodY;
extern int snakeScore;
extern bool snakeGameOver;

void initSnakeGame();
void updateSnakeGame();
void handleSnakeInput(bool up, bool down, bool select, bool back);

// Pong game
extern int paddleY;
extern int ballX, ballY;
extern int ballDX, ballDY;
extern int pongScore;
extern bool pongGameOver;

void initPongGame();
void updatePongGame();
void handlePongInput(bool up, bool down, bool select, bool back);

// Settings screen
void displaySettings();

#endif
