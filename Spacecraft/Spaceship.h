#include "Point.h"
#ifndef SPACESHIP_H
#define SPACESHIP_H

static class Body {
public: Point coord[14];
		Body ();
};

static class Wings {
public:Point coord[12];
	   Wings();
};

static class Cockpit {
public:Point coord[4];
		Cockpit();
};

static class MisslesLauncher {
public:Point coord[8];
	   MisslesLauncher();
};

static class Spaceship: public Body, Wings, Cockpit, MisslesLauncher {
public: 
	Body body;
	Wings wings;
	Cockpit cockpit;
	MisslesLauncher misslesLauncher;
	Point position;
	Spaceship();
	
};
#endif//SPACESHIP_H