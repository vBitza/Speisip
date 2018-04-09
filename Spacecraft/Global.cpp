#include <Gl/glut.h>
#include <gl\gl.h>
#include <gl\glu.h>
#include <iostream>
#include "freeglut.h"
#include "Point.h"
#include "Spaceship.h"
#include "Draw.h"
#include "Global.h"
#include "Engine.h"\


bool gameState=true;
bool asteroid=false;
bool laser=false;
bool isMovingLeft=false;
bool isMovingRight=false;
bool isMovingUp=false;
bool isMovingDown=false;

float deltaTime;
const double fps = 60.0;
const double refreshRate = 1.0/ fps * 1000.0;
double speed=15;
Point asteroidCoords, asteroidMove, asteroidMovespeed={0,-1}, projectilePosition, projectileMove;
Spaceship spaceship;
 char chars[50][2]={'0','0','0','1','0','2','0','3','0','4','0','5','0','6','0','7','0','8','0','9','1',
	'0','1','1','1','2','1','3','1','5','1','5','1','6','1','7','1','8','1','9','2','0','2','1','2','2','2','3',
	'2','4','2','5','2','6','2','7','2','8','2','2','9','3','0','3','1','3','2','3','3','3','3','4','3','3','5',
	'3','6','3','7','3','8','3','3','9','4','0'};
 char lifes[3]={'1','2','3'};

int score=0;
int lifesCount=2;
double oldTimeSinceStart; 

bool* keyStates = new bool[256];