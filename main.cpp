//#include <iostream>
#import <OpenGL/OpenGL.h>
#import <GLUT/GLUT.h>
#import "Planet.h"

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <stdlib.h>

using std::string;
using std::ifstream;
using std::istringstream;
using std::vector;

vector<Planet *> solarSystem;
float xRot = 50.0f;
float timeInc = 10.0f;
double timeValue = 0.0;
float zPos = -2000.0f;

void setupScene(void) {
    // for reading in CSV from file
	ifstream inFile ("/Users/mikelrob/Documents/Xcode/Solar/PlanetInfo.dat", ifstream::in);
    string line;
    int linenum = 0;
    while (inFile.good())
    {
        getline(inFile, line);
		Planet *newPlanet = new Planet();
		solarSystem.push_back(newPlanet);
        //cout << "\nLine #" << linenum << ":" << endl;
        istringstream linestream(line);
        string item;
		int itemnum = 0;
        while (getline(linestream, item, ','))
        {
            //cout << "Item #" << itemnum << ": " << item << endl;
			switch (itemnum) {
				case 0:
					solarSystem[linenum]->setName(item);
					break;
				case 1:
				{
					double temp = 0.0;
					sscanf(item.c_str(), "%lf", &temp);
					solarSystem[linenum]->getOrbit()->setAphelion(temp);
				}
					break;
				case 2:
				{
					double temp = 0.0;
					sscanf(item.c_str(), "%lf", &temp);
					solarSystem[linenum]->getOrbit()->setPerihelion(temp);
				}
					break;
				case 3:
				{
					float temp = 0.0;
					sscanf(item.c_str(), "%f", &temp);
					solarSystem[linenum]->getOrbit()->setPeriod(temp);
				}
					break;
				case 4:
				{
					float temp = 0.0;
					sscanf(item.c_str(), "%f", &temp);
					solarSystem[linenum]->getOrbit()->setInclination(temp);
				}
					break;
				case 5:
				{
					float temp = 0.0;
					sscanf(item.c_str(), "%f", &temp);
					solarSystem[linenum]->setRadius(temp);
				}
					break;
				case 6:
				{
					float temp = 0.0;
					sscanf(item.c_str(), "%f", &temp);
					solarSystem[linenum]->setPeriod(temp);
				}
					break;
				case 7:
					solarSystem[linenum]->getColour()->setRedComponent((unsigned short)atoi(item.c_str()));
					break;
				case 8:
					solarSystem[linenum]->getColour()->setGreenComponent((unsigned short)atoi(item.c_str()));
					break;
				case 9:
					solarSystem[linenum]->getColour()->setBlueComponent((unsigned short)atoi(item.c_str()));
					break;
				case 10:
				{
					float temp = 0.0;
					sscanf(item.c_str(), "%f", &temp);
					solarSystem[linenum]->setAxialTilt(temp);
				}
					break;
				case 11:
					solarSystem[linenum]->setNumSatellites(atoi(item.c_str()));
					break;

				default:
					//too many line params so do nothing
					break;
			}
			itemnum++;
        }
		linenum++;
    }
	return;
}

void RenderScene(void) {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	
	//translate the whole scene out into view
	glTranslatef(0.0f, 0.0f, zPos);
	glRotatef(xRot, 1.0f, 0.0f, 0.0f);
	
	//set material colour to yellow (sun)
	glColor3ub(255, 255, 0);
	
	glDisable(GL_LIGHTING);
	glutSolidSphere(15.0f, 15, 15);
	glEnable(GL_LIGHTING);
	
	//position the light after we draw the sun!
	GLfloat lightPos[] = {0.0f, 0.0f, 0.0f, 1.0f};
	GLfloat amb_dif[] = {1.0f, 1.0f, 1.0, 1.0f};
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
	glLightfv(GL_LIGHT0, GL_AMBIENT_AND_DIFFUSE, amb_dif);
	glEnable(GL_LIGHT0);
	
    //start drawing
    
	//std::clog << solarSystem.size();
	for (int i = 0 ; i < solarSystem.size() ; i++) {
		//save sun position
		glPushMatrix();
		
		//rotate the coord system
		glRotatef(1.0 / solarSystem[i]->getOrbit()->getPeriod() * timeValue, 0.0f, 1.0f, 0.0f);
		
		//translate distance to planet
		glTranslatef(solarSystem[i]->getOrbit()->getAverageDistance() * 50, 0.0f, 0.0f);

		//draw planet
		glColor3f(solarSystem[i]->getColour()->getRedComponent(),
				  solarSystem[i]->getColour()->getGreenComponent(),
				  solarSystem[i]->getColour()->getBlueComponent());
		glutSolidSphere(solarSystem[i]->getRadius()/1000, 15, 15);
		//if moon
		//save planet position
		//rotate to moon angle
		//translate moon distance
		//draw moon
		//go back to planet position
		
		//go back to sun position
		glPopMatrix();
		
	}
	/*
	//rotate coord system
	glRotatef(timeValue / 12.0, 0.0f, 1.0f, 0.0f);
	
	//draw the earth (blue)
	glColor3ub(0, 0, 255);
	glTranslatef(105.0f, 0.0f, 0.0f);
	glutSolidSphere(15.0f, 15, 15);
	
	//rotate earth-based coords and draw moon (grey)
	glColor3ub(200, 200, 200);
	glRotatef(timeValue, 0.0f, 1.0f, 0.0f);
	glTranslatef(30.0f, 0.0f, 0.0f);
	//fMoonRot += 15.0f;
	//if (fMoonRot > 360.0f) {
	//	fMoonRot = 0.0f;
	//}
	glutSolidSphere(6.0f, 15, 15);
	*/
    
    //stop drawing
     
	//restore the matrix state
	glPopMatrix();
	
	//step the time variable
	timeValue += timeInc;
	if (timeValue > 360000000.0) {
		timeValue = 0.0f;
	}
	
	//flush and swap
	glutSwapBuffers();
}


void SetupRC(void) {
	//setup up a clear window colour of opaque black
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	
}

void ChangeSize(GLsizei w, GLsizei h) {
	
	GLfloat aspectRatio = (GLfloat)w / (GLfloat)h;
	
	//prevent a div by 0
	if (h == 0) {
		h = 1;
	}
	
	//set the viewport
	glViewport(0, 0, w, h);
	
	//reset the coord system
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	//produce a perspective projection - FOV 45 deg, near 1 and far 425
	gluPerspective(45.0f, aspectRatio, 1.0, 10000.0);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
}

void InputKeys(unsigned char key, int mouseX, int mouseY){
    
    std::cerr << zPos;
    switch (key) {
        case '=':
            zPos += 100.0f;
            zPos > -500.0f ? zPos = -500.0 : zPos;
            break;
        case '-':
            zPos -= 100.0f;
            zPos < -2000.0f ? zPos = -2000.0 : zPos;
            ;
            break;
            
        default:
            break;
    }
    std::cerr << "\nInputKeys\n";
    
}

void SpecialKeys(int key, int mouseX, int mouseY) {
    
    switch (key) {
        case GLUT_KEY_UP:
            xRot += 10.0f;
            xRot > 90.0 ? xRot = 90.0f : 0;
            break;
        case GLUT_KEY_DOWN:
            xRot -= 10.0f;
            xRot < 0.0f ? xRot = 0.0f : 0;
            break;
        case GLUT_KEY_LEFT:
            timeInc -= 10.0f;
            timeInc < 10.0f ? timeInc = 10.0f : 0;
            break;
        case GLUT_KEY_RIGHT:
            timeInc += 10.0f;
            break;
        default:
            break;
    }
    std::cerr << "\nSpecialKeys: " << key << "\n";

}


void TimerFunc(int value) {
	glutPostRedisplay();
	glutTimerFunc(100, TimerFunc, value);
}

int main (int argc, char * argv[]) {
    
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Solar");
	glutReshapeFunc(ChangeSize);
	glutDisplayFunc(RenderScene);
    glutKeyboardFunc(InputKeys);
	glutSpecialFunc(SpecialKeys);
	glutTimerFunc(300, TimerFunc, 1);
	
	setupScene();
	SetupRC();
	
	glutMainLoop();
	
    return 0;
}
