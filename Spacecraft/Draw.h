#ifndef DRAW_H
#define DRAW_H
#include "Point.h"
#include "Spaceship.h"
#include <iostream>
#include <Gl/glut.h>
#include <gl\gl.h>
#include <gl\glu.h>

void drawShip(Spaceship spaceship);
void drawProjectile(Spaceship spaceship, Point projectilePosition, Point projectileMove);
void renderBitmap(float x, float y, void *font, char *string);
void overlay();
#endif//DRAW_H