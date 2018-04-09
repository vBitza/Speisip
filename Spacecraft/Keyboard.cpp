#include <Gl/glut.h>
#include <gl\gl.h>
#include <gl\glu.h>
#include <iostream>
#include "freeglut.h"
#include "Point.h"
#include "Spaceship.h"
#include "Draw.h"
#include "Global.h"
#include "Engine.h"
using namespace std;

void keyOperations (void) {  
	if(keyStates['a']==true)
	{
		isMovingRight = false;
		isMovingLeft = !isMovingLeft;
	}
	if(keyStates['a']==false)
		isMovingLeft=false;
	if(keyStates['d']==true)
	{
		isMovingLeft = false;
		isMovingRight = !isMovingRight;
	}
	if(keyStates['d']==false)
		isMovingRight=false;
	if(keyStates['w']==true)
		isMovingUp = !isMovingUp;
	if(keyStates['w']==false)
		isMovingUp=false;
	if(keyStates['s']==true)
		isMovingDown = !isMovingDown;
	if(keyStates['s']==false)
		isMovingDown=false;
	if(keyStates['r']==true)
	{
		cout<<"HELLOL";
		if(gameState==false)
		{
			gameState = true;
			lifesCount=2;
			score = 0;
			speed = 15;
			asteroidMovespeed.y = -1;
			glTimer();
		}
	}
	if(keyStates['1']==true)
		shoot();
}  

void keyPress(unsigned char key, int x, int y) 
{
	keyStates[key] = true;  
}

void keyUp (unsigned char key, int x, int y) 
{  
	keyStates[key] = false;   
} 