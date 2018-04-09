#include "Draw.h"
#include "Source.h"
#include "Point.h"
#include "Spaceship.h"
#include "Global.h"
#include <iostream>
#include <Gl/glut.h>
#include <gl\gl.h>
#include <gl\glu.h>
#include "Source.h"
using namespace std;
void drawShip(Spaceship spaceship)
{
	glColor3f(0.1,0,0.2);



	//Spaceship - body polygon
	glBegin(GL_POLYGON);
	for(int i=0;i<=5;i++)
		glVertex2f(spaceship.body.coord[i].x + spaceship.position.x,spaceship.body.coord[i].y + spaceship.position.y);
	glEnd();


	//Spaceship - body quads
	glBegin(GL_QUADS);
	for(int i=6;i<10;i++)
		glVertex2f(spaceship.body.coord[i].x + spaceship.position.x,spaceship.body.coord[i].y + spaceship.position.y);
	glEnd();

	glBegin(GL_QUADS);
	for(int i=10;i<=13;i++)
		glVertex2f(spaceship.body.coord[i].x + spaceship.position.x,spaceship.body.coord[i].y +spaceship.position.y);
	glEnd();


	//Space ship - front wings
	glColor3f(0.2,0.2,0.2);
	glBegin(GL_TRIANGLES);
	glColor3f(0.2,0.2,0.2);
	for(int i=0;i<=2;i++)
		glVertex2f(spaceship.wings.coord[i].x+spaceship.position.x,spaceship.wings.coord[i].y+spaceship.position.y);
	glEnd();

	glBegin(GL_TRIANGLES);
	for(int i=3;i<=5;i++)
		glVertex2f(spaceship.wings.coord[i].x+spaceship.position.x,spaceship.wings.coord[i].y+spaceship.position.y);
	glEnd(); 

	//Space ship - (back wings)
	glBegin(GL_TRIANGLES);
	for(int i=6;i<=8;i++)
		glVertex2f(spaceship.wings.coord[i].x+spaceship.position.x,spaceship.wings.coord[i].y+spaceship.position.y);
	glEnd();

	glBegin(GL_TRIANGLES);
	for(int i=9;i<=11;i++)
		glVertex2f(spaceship.wings.coord[i].x+spaceship.position.x,spaceship.wings.coord[i].y+spaceship.position.y);
	glEnd();

	//Space ship - (cockpit)
	glBegin(GL_QUADS);
	for(int i=0;i<4;i++)
		glVertex2f(spaceship.cockpit.coord[i].x+spaceship.position.x,spaceship.cockpit.coord[i].y+spaceship.position.y);
	glEnd();


	//Missles Launchers
	glColor3f(0.5,0.5,0.5);
	glBegin(GL_QUADS);
	for(int i=0;i<=3;i++)
		glVertex2f(spaceship.misslesLauncher.coord[i].x+spaceship.position.x,spaceship.misslesLauncher.coord[i].y+spaceship.position.y);
	glEnd();

	glBegin(GL_QUADS);
	for(int i=4;i<=7;i++)
		glVertex2f(spaceship.misslesLauncher.coord[i].x+spaceship.position.x,spaceship.misslesLauncher.coord[i].y+spaceship.position.y);
	glEnd();

}

void drawProjectile(Spaceship spaceship, Point projectilePosition, Point projectileMove){
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 0.0);
	for(int i=0;i<4;i++)
		glVertex2f(spaceship.cockpit.coord[i].x+projectilePosition.x, spaceship.cockpit.coord[i].y+projectilePosition.y+projectileMove.y);
	glEnd();
	//glutPostRedisplay();
}

void renderBitmap(float x, float y, void *font, char *string)
{
	char *c;
	glRasterPos2f(x,y);
	for(c=string;*c!='\n';c++)
	{
		glutBitmapCharacter(font, *c);
	}
}

void overlay() 
{
	char buf[100]={0};
	if(gameState==true){
		glPushMatrix();
		glScalef(glutGet(GLUT_SCREEN_WIDTH) / 1000.0,glutGet(GLUT_SCREEN_HEIGHT) / 1000.0 , 1);
		glColor3f(0,0,0);
		sprintf_s(buf,"Score:\n");
		glColor3f(0,0,0);
		renderBitmap(20,900,GLUT_BITMAP_HELVETICA_18,buf);
		glRasterPos2f(100,900);
		for(int j=0;j<2;j++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,chars[score][j]);
		sprintf_s(buf,"Lifes:\n");
		renderBitmap(20,880,GLUT_BITMAP_HELVETICA_18,buf);
		glRasterPos2i(100,880);
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,lifes[lifesCount]);
		glPopMatrix();
	} else 
	{
		//keyOperations(); 
		glClear(GL_COLOR_BUFFER_BIT);
		glPushMatrix();
		glColor3f(0,0,0);
		glBegin(GL_POLYGON);
		glVertex2f(0,0);
		glVertex2f(0,glutGet(GLUT_SCREEN_HEIGHT));
		glVertex2f(glutGet(GLUT_SCREEN_WIDTH), glutGet(GLUT_SCREEN_HEIGHT));
		glVertex2f(glutGet(GLUT_SCREEN_WIDTH), 0);
		glEnd();
		sprintf_s(buf,"GAME OVER\n");
		glColor3f(1,1,1);
		renderBitmap(500,500,GLUT_BITMAP_HELVETICA_18,buf);
		sprintf_s(buf,"Score:\n");
		renderBitmap(500,480,GLUT_BITMAP_HELVETICA_18,buf);
		glRasterPos2i(600,480);
		for(int j=0;j<2;j++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,chars[score][j]);
		sprintf_s(buf,"Press R if you want to restart the game\n");
		renderBitmap(500,460,GLUT_BITMAP_HELVETICA_18,buf);
		glPopMatrix();
		glutSwapBuffers();
		//glTimer();

	}
}