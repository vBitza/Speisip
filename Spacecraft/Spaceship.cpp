#include "Point.h"
#include "Spaceship.h"
#include <iostream>
#include <Gl/glut.h>
#include <gl\gl.h>
#include <gl\glu.h>
using namespace std;
Body::Body()
{
	//Polygon
	coord[0].x=95;
	coord[0].y=137.5;

	coord[1].x=85;
	coord[1].y=75;
	
	coord[2].x=95;
	coord[2].y=60;
	
	coord[3].x=105;
	coord[3].y=60;
	
	coord[4].x=115;
	coord[4].y=75;
	
	coord[5].x=105;
	coord[5].y=137.5;

	//Left quads
	coord[6].x=87.5;
	coord[6].y=90;

	coord[7].x=80;
	coord[7].y=100;

	coord[8].x=75;
	coord[8].y=90;

	coord[9].x=85;
	coord[9].y=75;
	//Right quads

	coord[10].x=110;
	coord[10].y=90;

	coord[11].x=120;
	coord[11].y=100;

	coord[12].x=127.5;
	coord[12].y=90;

	coord[13].x=115;
	coord[13].y=75;
}

Wings::Wings(){
	//Left front Wings
	coord[0].x=80; //-20 20
	coord[0].y=95; //-5

	coord[1].x=60; //-40 40
	coord[1].y=75;
	
	coord[2].x=80;
	coord[2].y=135;

	//Right front wings
	coord[3].x=120;
	coord[3].y=95;
	
	coord[4].x=140;
	coord[4].y=75;

	coord[5].x=120;
	coord[5].y=135;


	//Left back Wings
	coord[6].x=95;
	coord[6].y=60;
	
	coord[7].x=85;
	coord[7].y=75;

	coord[8].x=70;
	coord[8].y=60;

	//Right back wings
	coord[9].x=130;
	coord[9].y=60;
	
	coord[10].x=115;
	coord[10].y=75;

	coord[11].x=105;
	coord[11].y=60;

}

Cockpit::Cockpit(){
	coord[0].x=100;
	coord[0].y=145;
	
	coord[1].x=95;
	coord[1].y=137.5;

	coord[2].x=100;
	coord[2].y=125;

	coord[3].x=105;
	coord[3].y=137.5;
}

MisslesLauncher::MisslesLauncher(){
	coord[0].x=70;
	coord[0].y=105;

	coord[1].x=70;
	coord[1].y=120;

	coord[2].x=72.5;
	coord[2].y=120;

	coord[3].x=72.5;
	coord[3].y=112;
	//-----------------
	coord[4].x=127.5;
	coord[4].y=112;

	coord[5].x=127.5;
	coord[5].y=120;

	coord[6].x=130;
	coord[6].y=120;

	coord[7].x=130;
	coord[7].y=105;
}


Spaceship:: Spaceship(){
	cout<<"Spaceship created";
}
