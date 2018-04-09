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


void spawnAsteroid(){
	if(!asteroid){
		while(true){
			bool collides = false;

			// Produce a temporary random coordinate
			Point tempAsteroidCoords = { asteroidCoords.x = rand() % 700 + 100,
				asteroidCoords.y = 800  };


			for(unsigned int a = 0; a <spaceship.cockpit.coord[0].x; a++){
				if(tempAsteroidCoords.x ==spaceship.cockpit.coord[0].x+spaceship.position.x &&
					tempAsteroidCoords.y == spaceship.cockpit.coord[0].y+spaceship.position.y){
						collides = true;
				}
			}

			// If it doesn't collide with the snake, then make it the real food coordinates
			if(collides == false){
				asteroidCoords.x = tempAsteroidCoords.x;
				asteroidCoords.y = tempAsteroidCoords.y;
				asteroid = true;

				break;
			}
		}
	}
	glPushMatrix();
	glTranslatef(asteroidCoords.x, asteroidCoords.y, 0 );
	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_POLYGON);
	glVertex2f( -6+asteroidMove.x,  -6+asteroidMove.y);
	glVertex2f( -6+asteroidMove.x,  6+asteroidMove.y);
	glVertex2f( 6+asteroidMove.x, 6+asteroidMove.y);
	glVertex2f( 6+asteroidMove.x,  -6+asteroidMove.y);
	glEnd();
	glPopMatrix();
}
void checkConditions(){

	if(lifesCount < 0)
	{
		cout<<"Game over";
		gameState = false;
		spaceship.position.x = 0;
		spaceship.position.y = 0;
		asteroidMove.x = 0;
		asteroidMove.y = 0;
	}

	if(spaceship.cockpit.coord[0].x+spaceship.position.x > 990 || spaceship.cockpit.coord[0].x+spaceship.position.x < 10
		|| spaceship.cockpit.coord[0].y+spaceship.position.y > 800 || spaceship.cockpit.coord[0].y+spaceship.position.y < 0)
	{
		cout<<"Game over";
		gameState = false;
		spaceship.position.x = 0;
		spaceship.position.y = 0;
		asteroidMove.x = 0;
		asteroidMove.y = 0;
	}

	if(asteroidCoords.y + asteroidMove.y < 0)
	{
		lifesCount=lifesCount-1;
		asteroid = false;
		asteroidMove.x = 0;
		asteroidMove.y = 0;
	}
}
void checkCollision()
{
	if(spaceship.cockpit.coord[0].x+projectilePosition.x >= asteroidCoords.x-10+asteroidMove.x && 
		spaceship.cockpit.coord[0].x+projectilePosition.x <= asteroidCoords.x+10+asteroidMove.x)
		if(spaceship.cockpit.coord[0].y+projectilePosition.y+ projectileMove.y>= asteroidCoords.y-1+asteroidMove.y && 
			spaceship.cockpit.coord[0].y+projectilePosition.y+ projectileMove.y <= asteroidCoords.y +10+asteroidMove.y)
		{
			asteroid=false;
			laser=false;
			score++;
			projectileMove.y=0;
			asteroidMovespeed.y=asteroidMovespeed.y-0.25;
			speed=speed+0.5;
			asteroidMove.x=0;
			asteroidMove.y=0;
		}
}
void update(float deltaTime)
{
	if(isMovingLeft) spaceship.position.x -=speed   /50 * deltaTime;

	if(isMovingRight) spaceship.position.x += speed /50 * deltaTime;

	if(isMovingDown) spaceship.position.y -= speed /50*  deltaTime;

	if(isMovingUp) spaceship.position.y += speed /50*  deltaTime;
}
void glTimer() {
	// Update display
	glutPostRedisplay();
	// Reset timer
	double timeSinceStart = glutGet(GLUT_ELAPSED_TIME);
	double deltaTime = timeSinceStart - oldTimeSinceStart;

	oldTimeSinceStart = timeSinceStart;

	update(deltaTime);
}
void shoot(void)
{
	if(laser == false)
	{
		projectilePosition.x=spaceship.position.x;
		projectilePosition.y=spaceship.position.y;
		laser = true;
		cout << "Shooting with laser" << endl;
	} 
}
void updateObjects(void)
{
	if (laser == true)
	{
		projectileMove.y = projectileMove.y + 10;
		checkCollision();
		if (projectileMove.y > 400 ) 
		{
			laser = false;
			projectileMove.y = 0;
		}
	}
	if(asteroid == true) 
	{
		if(asteroidMove.x+asteroidCoords.x > 800)
			asteroidMovespeed.x = -1;
		if(asteroidMove.x+asteroidCoords.x < 200 )
			asteroidMovespeed.x = +1;
		asteroidMove.x=asteroidMove.x+asteroidMovespeed.x;
		asteroidMove.y=asteroidMove.y+asteroidMovespeed.y;
	}	
}