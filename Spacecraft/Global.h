#ifndef GLOBAL_H
#define GLOBAL_H

extern bool gameState;
extern bool asteroid;
extern bool laser;
extern bool isMovingLeft;
extern bool isMovingRight;
extern bool isMovingUp;
extern bool isMovingDown;
extern bool* keyStates;

extern float deltaTime;
extern const double fps;
extern const double refreshRate;
extern double speed;
extern double oldTimeSinceStart; 

extern Point asteroidCoords, asteroidMove, asteroidMovespeed, projectilePosition, projectileMove;
extern Spaceship spaceship;

extern char chars[50][2];
extern char lifes[3];

extern int score;
extern int lifesCount;

#endif//GLOBAL_H