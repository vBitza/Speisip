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
#include "Keyboard.h"

using namespace std;

void display(void);
void reshape(int, int);
void init(void);

int main (int argc,char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1000, 800);
	glutInitWindowPosition(200, 0);
	glutCreateWindow("Spaceship");
	init();
	glutDisplayFunc(display);
	glutIdleFunc(updateObjects); 
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyPress);
	glutKeyboardUpFunc(keyUp);
	glutMainLoop();
	return 0;
}

void init(void)
{
	glClearColor(0.1, 0.5, 0.1, 0.0);
	glShadeModel(GL_SMOOTH);
}

void display(void) {
	keyOperations(); 
	if(gameState == true )
	{
		glFlush();
		checkConditions();
		glClear(GL_COLOR_BUFFER_BIT);
		overlay();
		glPushMatrix();
		glScalef(glutGet(GLUT_SCREEN_WIDTH) / 1000.0,glutGet(GLUT_SCREEN_HEIGHT) / 1000.0 , 1);
		drawShip(spaceship);
		spawnAsteroid();
		if(laser == true)
			drawProjectile(spaceship, projectilePosition, projectileMove);
		glPopMatrix();
		glutSwapBuffers();	
	}
	else 
		overlay();
	glTimer();

}

void reshape (int w, int h)
{
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, glutGet(GLUT_SCREEN_WIDTH), 0, glutGet(GLUT_SCREEN_HEIGHT), -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity(); 
}
