// NOUMAN AHMAD

//final semester project





//============================================================================
// Name        : .cpp
// Author      : FAST CS Department
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Rush Hour...
//============================================================================

#ifndef RushHour_CPP_
#define RushHour_CPP_
#include "util.h"
#include <iostream>
#include <ctime>	//for randomizer
#include<string>	//for char 
#include<cmath> // for basic math functions such as cos, sin, sqrt
#include<fstream>

using namespace std;

// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
 
//---------------------------------------------------------------------------------------------------------------
void SetCanvasSize(int width, int height) 
{
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}


//===============================================================================================================
// VARIABLE DECLARATION

int xI = 0, yI = 0;
int aI =200, bI = 200;
int xIII=300, yIII=700;
int xIIII=630, yIIII=130;
int s=2;
int d;
int e;
int l1,l2,l3,l4,p,c;
int h1,h2,h3,h4;
int key;
int seconds=0;

int arr[16]={-1,-2,-3,-4,-5,-6,-7,-8,-9,-10,-11,-12,-13,-14,-15,-16};
int pers_arr[16]={-1,-2,-3,-4,-5,-6,-7,-8,-9,-10,-11,-12,-13,-14,-15,-16};

//===============================================================================================================
// FUNCTION DECLARATION
void walls(int key);
void coll_sion(int key);
void check_place(int d,int e);
void random_pers(int p, int c);
int name;

void result();
//===============================================================================================================

void drawCar() {
	
	DrawSquare(xI, yI, 20, colors[YELLOW]);
	
	glutPostRedisplay();
}
//2ND CAR
void drawCar2() {
	
	
	DrawCircle(aI,bI-4,5,colors[BLACK]);
	DrawCircle(aI+18,bI-4,5,colors[BLACK]);
	DrawSquare(aI,bI,20,colors[RED]);
	glutPostRedisplay();
}

void drawCar3() {
	
	
	DrawCircle(xIII,yIII-4,5,colors[BLACK]);
	DrawCircle(xIII+18,yIII-4,5,colors[BLACK]);
	DrawSquare(xIII,yIII,20,colors[RED]);
	glutPostRedisplay();
}

void drawCar4() {
	
	
	DrawCircle(xIIII,yIIII-4,5,colors[BLACK]);
	DrawCircle(xIIII+18,yIIII-4,5,colors[BLACK]);
	DrawSquare(xIIII,yIIII,20,colors[RED]);
	glutPostRedisplay();
}

//---
void drawCar5() {
	
	DrawSquare(xI, yI, 20, colors[INDIGO]);
	
	glutPostRedisplay();
}
//--------------------------------------------------------------------------------------------------------------
bool flag = true;
void moveCar() {
	
	if (xI > 10 && flag) {
		xI -= 10;
		cout << "going left";
		if(xI < 100)
			
			flag = false;

	}
	else if (xI < 1010 && !flag) {
		cout << "go right";
		xI += 10;
		if (xI > 900)
			flag = true;
	}
}
//2ND CAR
bool flag_2 = true;
void moveCar2() {
	
	if (aI > 10 && flag_2) 
	{
		bI -= 10;
		cout << "going left";
		if(bI < 100)
			
			flag_2 = false;

	}
	else if (bI < 1010 && !flag_2) 
	{
		cout << "go right";
		bI += 10;
		if (bI > 400)
			flag_2 = true;
	}
}

bool flag_3 = true;
void moveCar3() {
	
	if (xIII > 1 && flag_3) 
	{
		xIII -= 10;
		cout << "going left";
		if(xIII < 90)
			
			flag_3 = false;

	}
	else if (xIII < 1010 && !flag_3) {
		cout << "go right";
		xIII += 10;
		if (xIII > 200)
			flag_3 = true;
	}
}

bool flag_4 = true;
void moveCar4() 
{
	
	if (yIIII > 0 && flag_4) {
		yIIII -= 12;
		cout << "going DOWN";
		if(yIIII < 200)
			
			flag_4 = false;

	}
	else if (yIIII < 1010 && !flag_4) {
		cout << "go UP";
		yIIII += 12;
		if (yIIII > 500)
			flag_4 = true;
	}
}
//----

bool flag_5 = true;
void moveCar5() {
	
	if (xI > 10 && flag_5) {
		xI -= 10;
		cout << "going left";
		if(xI < 100)
			
			flag_5 = false;

	}
	else if (xI < 1010 && !flag_5) {
		cout << "go right";
		xI += 10;
		if (xI > 900)
			flag_5 = true;
	}
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/*
 * Main Canvas drawing function.
 * */

void GameDisplay()/**/{
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	glClearColor(1/*Red Component*/, 1,	//148.0/255/*Green Component*/,
			1.0/*Blue Component*/, 1 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
	
	//Green Square
	DrawSquare( 250 , 250 ,20,colors[GREEN]); 
	//INSTRUCTION
	DrawString( 100, 980, "DESTINATION", colors[BLACK]);
	DrawSquare( 280 , 980 ,20,colors[BROWN]);
	
	DrawString( 320, 980, "PEOPLE", colors[BLACK]);
	DrawCircle(440,990,10,colors[RED]);
	
	DrawString( 460, 980, " TAXI", colors[BLACK]);
	DrawSquare( 530 , 980 ,20,colors[YELLOW]);
	
	DrawString( 560, 980, " PRESS ESC TO EXIT", colors[BLACK]);
	//Display Score
	DrawString( 50, 900, "Score="+to_string(s), colors[BLACK]);
	DrawString( 700, 900, "time="+to_string(seconds), colors[BLACK]);
	DrawString( 500, 900,"X "+to_string(xI)+" Y "+to_string(yI) , colors[BLACK]);
	
	
	// Trianlge Vertices v1(300,50) , v2(500,50) , v3(400,250)
	DrawTriangle( 300, 450 , 340, 450 , 320 , 490, colors[MISTY_ROSE] ); 
	


	//DrawLine(int x1, int y1, int x2, int y2, int lwidth, float *color)
//	DrawLine( 210 , 230 ,  210 , 480 , 30 , colors[BLACK] );	
	//       (LOWER.X-Y   UPPER.X-Y   WIDTH  COLOR)
	
	DrawLine( 70 , 45 ,  70 , 45 , 30 , colors[BLACK] );	
	DrawLine( 60 , 48 , 40 , 48 , 30 , colors[BLACK] );
	//--SCALE
	DrawLine( 70 , 0 , 70 , 880 , 1 , colors[BLACK] );
	DrawLine( 140 , 0 , 140 , 880 , 1 , colors[BLACK] );
	DrawLine( 210 , 0 , 210 , 880 , 1 , colors[BLACK] );
	DrawLine( 280 , 0 , 280 , 880 , 1 , colors[BLACK] );
	DrawLine( 350 , 0 , 350 , 880 , 1 , colors[BLACK] );
	DrawLine( 420 , 0 , 420 , 880 , 1 , colors[BLACK] );
	DrawLine( 490 , 0 , 490 , 880 , 1 , colors[BLACK] );
	DrawLine( 560 , 0 , 560 , 880 , 1 , colors[BLACK] );
	DrawLine( 630 , 0 , 630 , 880 , 1 , colors[BLACK] );
	DrawLine( 700 , 0 , 700 , 880 , 1 , colors[BLACK] );
	DrawLine( 770 , 0 , 770 , 880 , 1 , colors[BLACK] );
	DrawLine( 840 , 0 , 840 , 880 , 1 , colors[BLACK] );
	DrawLine( 910 , 0 , 910 , 880 , 1 , colors[BLACK] );
	DrawLine( 980 , 0 , 980 , 880 , 1 , colors[BLACK] );
	DrawLine( 1050 , 0 , 1050 , 880 , 1 , colors[BLACK] );
	
	DrawLine( 0 , 880 , 1100 , 880 , 10 , colors[BLACK] );
	
//	DrawCircle(50,770,10,colors[RED]);
//	DrawCircle(70,770,10,colors[RED]);
//	DrawCircle(90,770,10,colors[RED]);


//OBSTACLES
	DrawSquare(arr[0], arr[1], 30, colors[BLACK]);
	DrawSquare(arr[2],arr[3],30,colors[BLACK]);
	DrawSquare(arr[4],arr[5],30,colors[BLACK]);
	
	
	//person-0
	DrawCircle(pers_arr[0],pers_arr[1],10,colors[RED]);
	if(pers_arr[0]==1500 and pers_arr[1]==1500)
	{
		DrawSquare(l1,h1,30,colors[BROWN]);
	}
	
	DrawCircle(pers_arr[2],pers_arr[3],10,colors[RED]);
	if(pers_arr[2]==1500 and pers_arr[3]==1500)
	{
		DrawSquare(l2,h2,30,colors[BROWN]);
	}
	DrawCircle(pers_arr[4],pers_arr[5],10,colors[RED]);
	if(pers_arr[4]==1500 and pers_arr[5]==1500)
	{
		DrawSquare(l3,h3,30,colors[BROWN]);
	}

	
	//--BLOCK
	DrawSquare(140,420,50,colors[BLUE]);
	DrawSquare(70,420,50,colors[BLUE]);
	DrawSquare(118,420,50,colors[BLUE]);
	//--TREE
	DrawLine( 110 , 468 , 110 , 508 , 2 , colors[BROWN] );
	DrawCircle(110,515,20,colors[GREEN]);
	
	//--BLOCK
	DrawSquare(350,350,50,colors[BLUE]);
	DrawSquare(390,350,50,colors[BLUE]);
	DrawSquare(430,350,50,colors[BLUE]);
	DrawSquare(470,350,50,colors[BLUE]);
	DrawSquare(470,390,50,colors[BLUE]);
	//--TREE
	DrawLine( 440 , 397 , 440 , 427 , 2 , colors[BROWN] );
	DrawCircle(440,447,20,colors[GREEN]);
	
	//--BLOCK
	DrawSquare(800,700,50,colors[BLUE]);
	DrawSquare(840,700,50,colors[BLUE]);
	DrawSquare(840,660,50,colors[BLUE]);
	
	//--BLOCK
	DrawSquare(800,60,50,colors[BLUE]);
	DrawSquare(840,60,50,colors[BLUE]);
	DrawSquare(840,100,50,colors[BLUE]);
	
	//--BLOCK
	DrawSquare(390,700,50,colors[BLUE]);
	DrawSquare(330,700,50,colors[BLUE]);
	DrawSquare(370,700,50,colors[BLUE]);
	DrawSquare(410,700,50,colors[BLUE]);
	DrawSquare(440,700,50,colors[BLUE]);
	DrawSquare(480,700,50,colors[BLUE]);
	DrawSquare(520,700,50,colors[BLUE]);
	
	//--BLOCK
	DrawSquare(840,350,50,colors[BLUE]);
	
	//--BLOCK
	DrawSquare(500,20,50,colors[BLUE]);
	DrawSquare(540,20,50,colors[BLUE]);
	DrawSquare(580,20,50,colors[BLUE]);
	
//	DrawRoundRect(500,200,50,100,colors[DARK_SEA_GREEN],70);
//	DrawRoundRect(100,200,100,50,colors[DARK_OLIVE_GREEN],20);	
//	DrawRoundRect(100,100,50,100,colors[DARK_OLIVE_GREEN],30);
//	DrawRoundRect(200,100,100,50,colors[LIME_GREEN],40);
//	DrawRoundRect(350,100,100,50,colors[LIME_GREEN],20);
	
	drawCar();
	//2ND CAR
	drawCar2();
	drawCar3();
	drawCar4();
	
	glutSwapBuffers(); // do not modify this line..

}





void GameDisplay_2()/**/{
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	glClearColor(1/*Red Component*/, 1,	//148.0/255/*Green Component*/,
			1.0/*Blue Component*/, 1 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors

	//Green Square
	DrawSquare( 250 , 250 ,20,colors[GREEN]); 
	
	//Display Score
	DrawString( 50, 900, "Score="+to_string(s), colors[BLACK]);
	DrawString( 700, 900, "time="+to_string(seconds), colors[BLACK]);
	DrawString( 500, 900,"X "+to_string(xI)+" Y "+to_string(yI) , colors[BLACK]);
	
	
	// Trianlge Vertices v1(300,50) , v2(500,50) , v3(400,250)
	DrawTriangle( 300, 450 , 340, 450 , 320 , 490, colors[MISTY_ROSE] ); 
	


	//DrawLine(int x1, int y1, int x2, int y2, int lwidth, float *color)
//	DrawLine( 210 , 230 ,  210 , 480 , 30 , colors[BLACK] );	
	//       (LOWER.X-Y   UPPER.X-Y   WIDTH  COLOR)
	
	DrawLine( 70 , 45 ,  70 , 45 , 30 , colors[BLACK] );	
	DrawLine( 60 , 48 , 40 , 48 , 30 , colors[BLACK] );
	//--SCALE
	DrawLine( 70 , 0 , 70 , 880 , 1 , colors[BLACK] );
	DrawLine( 140 , 0 , 140 , 880 , 1 , colors[BLACK] );
	DrawLine( 210 , 0 , 210 , 880 , 1 , colors[BLACK] );
	DrawLine( 280 , 0 , 280 , 880 , 1 , colors[BLACK] );
	DrawLine( 350 , 0 , 350 , 880 , 1 , colors[BLACK] );
	DrawLine( 420 , 0 , 420 , 880 , 1 , colors[BLACK] );
	DrawLine( 490 , 0 , 490 , 880 , 1 , colors[BLACK] );
	DrawLine( 560 , 0 , 560 , 880 , 1 , colors[BLACK] );
	DrawLine( 630 , 0 , 630 , 880 , 1 , colors[BLACK] );
	DrawLine( 700 , 0 , 700 , 880 , 1 , colors[BLACK] );
	DrawLine( 770 , 0 , 770 , 880 , 1 , colors[BLACK] );
	DrawLine( 840 , 0 , 840 , 880 , 1 , colors[BLACK] );
	DrawLine( 910 , 0 , 910 , 880 , 1 , colors[BLACK] );
	DrawLine( 980 , 0 , 980 , 880 , 1 , colors[BLACK] );
	DrawLine( 1050 , 0 , 1050 , 880 , 1 , colors[BLACK] );
	
	DrawLine( 0 , 880 , 1100 , 880 , 10 , colors[BLACK] );
	
//	DrawCircle(50,770,10,colors[RED]);
//	DrawCircle(70,770,10,colors[RED]);
//	DrawCircle(90,770,10,colors[RED]);



// OBSTACLES
	DrawSquare( 250 , 250 ,20,colors[GREEN]); 
	//INSTRUCTION
	DrawString( 100, 980, "DESTINATION", colors[BLACK]);
	DrawSquare( 280 , 980 ,20,colors[BROWN]);
	
	DrawString( 320, 980, "PEOPLE", colors[BLACK]);
	DrawCircle(440,990,10,colors[RED]);
	
	DrawString( 460, 980, " TAXI", colors[BLACK]);
	DrawSquare( 530 , 980 ,20,colors[YELLOW]);
	
	DrawString( 560, 980, " PRESS ESC TO EXIT", colors[BLACK]);
	//Display Score
	DrawString( 50, 900, "Score="+to_string(s), colors[BLACK]);
	DrawString( 700, 900, "time="+to_string(seconds), colors[BLACK]);
	DrawString( 500, 900,"X "+to_string(xI)+" Y "+to_string(yI) , colors[BLACK]);


//OBSTACLES
	DrawSquare(arr[0], arr[1], 30, colors[BLACK]);
	DrawSquare(arr[2],arr[3],30,colors[BLACK]);
	DrawSquare(arr[4],arr[5],30,colors[BLACK]);

	
	//person-0
	DrawCircle(pers_arr[0],pers_arr[1],10,colors[RED]);
	if(pers_arr[0]==1500 and pers_arr[1]==1500)
	{
		DrawSquare(l1,h1,30,colors[BROWN]);
	}
	
	DrawCircle(pers_arr[2],pers_arr[3],10,colors[RED]);
	if(pers_arr[2]==1500 and pers_arr[3]==1500)
	{
		DrawSquare(l2,h2,30,colors[BROWN]);
	}
	DrawCircle(pers_arr[4],pers_arr[5],10,colors[RED]);
	if(pers_arr[4]==1500 and pers_arr[5]==1500)
	{
		DrawSquare(l3,h3,30,colors[BROWN]);
	}
	//--BLOCK
	DrawSquare(140,420,50,colors[BLUE]);
	DrawSquare(70,420,50,colors[BLUE]);
	DrawSquare(118,420,50,colors[BLUE]);
	//--TREE
	DrawLine( 110 , 468 , 110 , 508 , 2 , colors[BROWN] );
	DrawCircle(110,515,20,colors[GREEN]);
	
	//--BLOCK
	DrawSquare(350,350,50,colors[BLUE]);
	DrawSquare(390,350,50,colors[BLUE]);
	DrawSquare(430,350,50,colors[BLUE]);
	DrawSquare(470,350,50,colors[BLUE]);
	DrawSquare(470,390,50,colors[BLUE]);
	//--TREE
	DrawLine( 440 , 397 , 440 , 427 , 2 , colors[BROWN] );
	DrawCircle(440,447,20,colors[GREEN]);
	
	//--BLOCK
	DrawSquare(800,700,50,colors[BLUE]);
	DrawSquare(840,700,50,colors[BLUE]);
	DrawSquare(840,660,50,colors[BLUE]);
	
	//--BLOCK
	DrawSquare(800,60,50,colors[BLUE]);
	DrawSquare(840,60,50,colors[BLUE]);
	DrawSquare(840,100,50,colors[BLUE]);
	
	//--BLOCK
	DrawSquare(390,700,50,colors[BLUE]);
	DrawSquare(330,700,50,colors[BLUE]);
	DrawSquare(370,700,50,colors[BLUE]);
	DrawSquare(410,700,50,colors[BLUE]);
	DrawSquare(440,700,50,colors[BLUE]);
	DrawSquare(480,700,50,colors[BLUE]);
	DrawSquare(520,700,50,colors[BLUE]);
	
	//--BLOCK
	DrawSquare(840,350,50,colors[BLUE]);
	
	//--BLOCK
	DrawSquare(500,20,50,colors[BLUE]);
	DrawSquare(540,20,50,colors[BLUE]);
	DrawSquare(580,20,50,colors[BLUE]);
	
//	DrawRoundRect(500,200,50,100,colors[DARK_SEA_GREEN],70);
//	DrawRoundRect(100,200,100,50,colors[DARK_OLIVE_GREEN],20);	
//	DrawRoundRect(100,100,50,100,colors[DARK_OLIVE_GREEN],30);
//	DrawRoundRect(200,100,100,50,colors[LIME_GREEN],40);
//	DrawRoundRect(350,100,100,50,colors[LIME_GREEN],20);
	
	drawCar5();
	//2ND CAR
	drawCar2();
	drawCar3();
	drawCar4();
	
	glutSwapBuffers(); // do not modify this line..

}










/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int x, int y) 
{
	if (key
			== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		// what to do when left key is pressed...
		xI -= 10;

	} else if (key
			== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {
		xI += 10;
	} else if (key
			== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {
		yI += 10;
	}

	else if (key
			== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {
		yI -= 10;
	}
	//--FOR BOUNDARIES--------------------------------------------------------------------------------------
	if(xI<=2 and key == GLUT_KEY_LEFT)
	{
		xI+=10;
		
	}
	else if(xI>= 1020 and key == GLUT_KEY_RIGHT)
	{
		xI-=10;
		
	}
	else if(yI>=860 and key == GLUT_KEY_UP)
	{
		yI-=10;
		
	}
	else if(yI<=7 and key == GLUT_KEY_DOWN)
	{
		yI+=10;
		
	}
	
	
	walls(key);
	coll_sion(key);
	//------------------------------------------------------------------------------------------------------
	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();

}




void walls(int key)
{
	//--FOR COLLISSION---------------------------------
	//--MIDDLE BLOCK TO RIGHT
	if((xI>=830 && xI<=880 ) && (yI>=340  && yI<=390 ))//=====done
	{
		if(key == GLUT_KEY_LEFT)
		{
			xI+=10;
		}
		else if(key == GLUT_KEY_RIGHT)
		{
			xI-=10;
		}
		else if(key == GLUT_KEY_DOWN)
		{
			yI+=10;
		}
		else if(key == GLUT_KEY_UP)
		{
			yI-=10;
		}
		
		
	}
	
	//--MIDDLE ONE WITH THE TREE
	if((xI>=340 && xI<=510 ) && (yI>=335  && yI<=390 ))//===========done
	{
		if(key == GLUT_KEY_LEFT)
		{
			xI+=10;
		}
		else if(key == GLUT_KEY_RIGHT)
		{
			xI-=10;
		}
		else if(key == GLUT_KEY_DOWN)
		{
			yI+=10;
		}
		else if(key == GLUT_KEY_UP)
		{
			yI-=10;
		}
		
		
	}
	
	
	if((xI>=460 && xI<=510 ) && (yI>=390  && yI<=430 ))//==============done
	{
		if(key == GLUT_KEY_LEFT)
		{
			xI+=10;
		}
		else if(key == GLUT_KEY_RIGHT)
		{
			xI-=10;
		}
		else if(key == GLUT_KEY_DOWN)
		{
			yI+=10;
		}
		else if(key == GLUT_KEY_UP)
		{
			yI-=10;
		}
		
		
	}
	
	if((xI>=315 && xI<=565 ) && (yI>=690  && yI<=740 ))//====done
	{
		if(key == GLUT_KEY_LEFT)
		{
			xI+=10;
		}
		else if(key == GLUT_KEY_RIGHT)
		{
			xI-=10;
		}
		else if(key == GLUT_KEY_DOWN)
		{
			yI+=10;
		}
		else if(key == GLUT_KEY_UP)
		{
			yI-=10;
		}
		
		
	}
	
	
	if((xI>=60 && xI<=180 ) && (yI>=410  && yI<=460 ))//=====done 
	{
		if(key == GLUT_KEY_LEFT)
		{
			xI+=10;
		}
		else if(key == GLUT_KEY_RIGHT)
		{
			xI-=10;
		}
		else if(key == GLUT_KEY_DOWN)
		{
			yI+=10;
		}
		else if(key == GLUT_KEY_UP)
		{
			yI-=10;
		}
		
		
	}
	
	if((xI>=490 && xI<=620 ) && (yI>=10  && yI<=60 ))//===done lower one
	{
		if(key == GLUT_KEY_LEFT)
		{
			xI+=10;
		}
		else if(key == GLUT_KEY_RIGHT)
		{
			xI-=10;
		}
		else if(key == GLUT_KEY_DOWN)
		{
			yI+=10;
		}
		else if(key == GLUT_KEY_UP)
		{
			yI-=10;
		}
		
		
	}
	
	
	
	if((xI>=785 && xI<=880 ) && (yI>=690  && yI<=740 ))//===done
	{
		if(key == GLUT_KEY_LEFT)
		{
			xI+=10;
		}
		else if(key == GLUT_KEY_RIGHT)
		{
			xI-=10;
		}
		else if(key == GLUT_KEY_DOWN)
		{
			yI+=10;
		}
		else if(key == GLUT_KEY_UP)
		{
			yI-=10;
		}
		
		
	}
	
	
	if((xI>=830 && xI<=880 ) && (yI>=650  && yI<=690 ))//====done
	{
		if(key == GLUT_KEY_LEFT)
		{
			xI+=10;
		}
		else if(key == GLUT_KEY_RIGHT)
		{
			xI-=10;
		}
		else if(key == GLUT_KEY_DOWN)
		{
			yI+=10;
		}
		else if(key == GLUT_KEY_UP)
		{
			yI-=10;
		}
		
		
	}
	
	
	if((xI>=830 && xI<=880 ) && (yI<=140  && yI>=90 ))//====done
	{
		if(key == GLUT_KEY_LEFT)
		{
			xI+=10;
		}
		else if(key == GLUT_KEY_RIGHT)
		{
			xI-=10;
		}
		else if(key == GLUT_KEY_DOWN)
		{
			yI+=10;
		}
		else if(key == GLUT_KEY_UP)
		{
			yI-=10;
		}
		
		
	}
	
	
	
	if((xI>=785 && xI<=880 ) && (yI>=50  && yI<=100 ))
	{
		if(key == GLUT_KEY_LEFT)
		{
			xI+=10;
		}
		else if(key == GLUT_KEY_RIGHT)
		{
			xI-=10;
		}
		else if(key == GLUT_KEY_DOWN)
		{
			yI+=10;
		}
		else if(key == GLUT_KEY_UP)
		{
			yI-=10;
		}
		
		
	}
}	


//void NonPrintableKeys2(int key, int x, int y) {
//	if (key
//			== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
//		// what to do when left key is pressed...
//		aI -= 10;
//
//	} else if (key
//			== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {
//		aI += 10;
//	} else if (key
//			== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {
//		bI += 10;
//	}
//
//	else if (key
//			== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {
//		bI -= 10;
//	}
//
//	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
//	 * this function*/

//	glutPostRedisplay();

//}



/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) 
{
	if (key == 27/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}

	if (key == 'b' || key == 'B') //Key for placing the bomb
			{
		//do something if b is pressed
		cout << "b pressed" << endl;

	}
	
	if (key == 75/* Escape key ASCII*/) {
		glutDisplayFunc(GameDisplay); // exit the program when escape key is pressed.
	}
	
	if (key == 76/* Escape key ASCII*/) {
		glutDisplayFunc(GameDisplay_2); // exit the program when escape key is pressed.
	}
	
	
	if((xI>=pers_arr[0]-5) and (xI<=pers_arr[1]+8) and (yI>=pers_arr[1]-4) and (yI<=pers_arr[1]+8))
	{
		if(key==32)
		{
			pers_arr[0]=1500;
			pers_arr[1]=1500;
			l1=(rand() % 1000)+10;
			h1=(rand() % 820)+10;
			check_place(l1,h1);
		}
	}
	
	if((xI>=l1-8) and (xI<=l1+10) and (yI>=h1-10) and (yI>=h1+10))
	{	
		if(key==32){
		s+=10;
		l1=1500;
		h1=1500;
		}
		if(pers_arr[0]==1500 and pers_arr[1]==1500)
		{
			pers_arr[0]=(rand() % 1000)+10;
			pers_arr[1]=(rand() % 820)+10;
			
			check_place(pers_arr[0],pers_arr[1]);
		
		}
	
	}
	
	if((xI>=pers_arr[2]-5) and (xI<=pers_arr[2]+8) and (yI>=pers_arr[3]-4) and (yI<=pers_arr[3]+8))
	{
		if(key==32)
		{
			pers_arr[2]=1500;
			pers_arr[3]=1500;
			l2=(rand() % 1000)+10;
			h2=(rand() % 820)+10;
			check_place(l2,h2);
		}
	}
	
	if((xI>=l2-5) and (xI<=l2+10) and (yI>=h2-5) and (yI>=h2+10))
	{	
		if(key==32){
		s+=10;
		l2=1500;
		h2=1500;
		}
		if(pers_arr[2]==1500 and pers_arr[3]==1500)
		{
			pers_arr[2]=(rand() % 1000)+10;
			pers_arr[3]=(rand() % 820)+10;
			
			check_place(pers_arr[2],pers_arr[3]);
		
		}
	
	}
	
	if((xI>=pers_arr[4]-5) and (xI<=pers_arr[4]+8) and (yI>=pers_arr[5]-4) and (yI<=pers_arr[5]+8))
	{
		if(key==32)
		{
			pers_arr[4]=1500;
			pers_arr[5]=1500;
			l3=(rand() % 1000)+10;
			h3=(rand() % 820)+10;
			check_place(l3,h3);
		}
	}
	
	if((xI>=l3-8) and (xI<=l3+10) and (yI>=h3-8) and (yI>=h3+10))
	{	
		if(key==32){
		s+=10;
		l3=1500;
		h3=1500;
		}
		if(pers_arr[4]==1500 and pers_arr[5]==1500)
		{
			pers_arr[4]=(rand() % 1000)+10;
			pers_arr[5]=(rand() % 820)+10;
			
			check_place(pers_arr[4],pers_arr[5]);
		
		}
	
	
		
		
	
	}
	


	//if (key== 'm' || key=='M')
	//{
		//glutDisplayFunc(MenuDisplay);
//	}
//	if (key == 'f' || key == 'F')
//	{
//		glutDisplayFunc(GameDisplay);
//	}
	glutPostRedisplay();
}



	
	
void MenuDisplay()
{	
		glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
			unsigned char key;
	glClear (GL_COLOR_BUFFER_BIT);
	
	DrawString( 500, 900, "RUSH HOUR", colors[BLUE]);
	DrawString( 300, 700, "ENTER 'K' TO GET GREEN CAB", colors[BLUE]);
	DrawString( 300, 600, "ENTER L TO GET PURPLE CAB", colors[BLUE]);
	DrawSquare(700, 700, 20, colors[GREEN]);
	DrawSquare(700, 600, 20, colors[PURPLE]);
	DrawString( 300, 300, "enjoy", colors[BLUE]);
	glutSwapBuffers();
	
	glutPostRedisplay();

}

/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
 

void Timer(int m){

	// implement your functionality here
	//moveCar();
	//moveCar5();
	moveCar2();
	moveCar3();
	moveCar4();

	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(100, Timer, 0);
}


void Timmy(int n){

	seconds++;
	if (seconds >= 180){
		glutDisplayFunc(result);
	}


	if (s>=100){
		exit(1);

	}

	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(1000, Timmy, 0);
}





/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y)
{
	cout << x << " " << y << endl;
	glutPostRedisplay();
}
void MouseMoved(int x, int y) 
{
	cout << x << " " << y << endl;
	glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
void MouseClicked(int button, int state, int x, int y)
{

	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
			{
		cout << GLUT_DOWN << " " << GLUT_UP << endl;

	} else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
			{
			cout<<"Right Button Pressed"<<endl;

	}
	glutPostRedisplay();
}



//===================================================
void rando_place()
{
	arr[0]=(rand()%1020)+10;
	arr[1]=(rand()%820)+10;
	check_place(arr[0],arr[1]);
	
	arr[2]=(rand()%1020)+10;
	arr[3]=(rand()%820)+10;
	check_place(arr[2],arr[3]);
	
	arr[4]=(rand()%1020)+10;
	arr[5]=(rand()%820)+10;
	check_place(arr[4],arr[5]);
	
	
}


void check_place(int d, int e)
{
	if((xI>=800 && xI<=860 ) && (yI>=300  && yI<=370 ))	//20 - 30 - 30 - 30
	{
		d=(rand()%1000) + 10;
		e=(rand()%820) + 10;
		check_place(d,e);
	}
	if((xI>=330 && xI<=530 ) && (yI>=315  && yI<=410 ))   //10 - 20 - 20 - 20
	{
		d=(rand()%1000) + 10;
		e=(rand()%820) + 10;
		check_place(d,e);
	}
	if((xI>=430 && xI<=490 ) && (yI>=360  && yI<=450 ))	//30 - 20 - 30 - 20
	{
		d=(rand()%1000) + 10;
		e=(rand()%820) + 10;
		check_place(d,e);
	}
	if((xI>=300 && xI<=585 ) && (yI>=670  && yI<=760 ))	//15 - 20 - 20 - 20
	{
		d=(rand()%1000) + 10;
		e=(rand()%820) + 10;
		check_place(d,e);
	}
	if((xI>=40 && xI<=200 ) && (yI>=390  && yI<=480 ))	//20 - 20 - 20 - 20
	{
		d=(rand()%1000) + 10;
		e=(rand()%820) + 10;
		check_place(d,e);
	}
	if((xI>=470 && xI<=640 ) && (yI>=5  && yI<=80 ))	//20 - 20 - 5 - 20
	{
		d=(rand()%1000) + 10;
		e=(rand()%820) + 10;
		check_place(d,e);
	}
	if((xI>=765 && xI<=900 ) && (yI>=670  && yI<=760 ))	//20 - 20 - 20 - 20
	{
		d=(rand()%1000) + 10;
		e=(rand()%820) + 10;
		check_place(d,e);
	}
	if((xI>=810 && xI<=900 ) && (yI>=630  && yI<=710 ))	//20 - 20 - 20 - 20
	{
		d=(rand()%1000) + 10;
		e=(rand()%820) + 10;
		check_place(d,e);
	}
	if((xI>=810 && xI<=900 ) && (yI<=130  && yI>=120 ))	//20 - 20 - 10 - 30
	{
		d=(rand()%1000) + 10;
		e=(rand()%820) + 10;
		check_place(d,e);
	}
	if((xI>=765 && xI<=900 ) && (yI>=30  && yI<=120 ))	//20 - 20 - 20 - 20
	{
		d=(rand()%1000) + 10;
		e=(rand()%820) + 10;
		check_place(d,e);
	}
}

void coll_sion(int key)
	{
		if(((xI>=arr[0]-15) and xI<=(arr[0]+32)) and ((yI>=arr[1]-15) and yI<=(arr[1]+34)))
		{
			if(key==GLUT_KEY_RIGHT)
			{
				xI-=10;
			}
			else if(key==GLUT_KEY_LEFT)
			{
				xI+=10;
			}
			else if(key==GLUT_KEY_UP)
			{
				yI-=10;
			}
			else if(key==GLUT_KEY_DOWN)
			{
				yI+=10;
			}
			s-=2;
		}
		
		if(((xI>=arr[2]-15) and xI<=(arr[2]+32)) and ((yI>=arr[3]-15) and yI<=(arr[3]+34)))
		{
			if(key==GLUT_KEY_RIGHT)
			{
				xI-=10;
			}
			else if(key==GLUT_KEY_LEFT)
			{
				xI+=10;
			}
			else if(key==GLUT_KEY_UP)
			{
				yI-=10;
			}
			else if(key==GLUT_KEY_DOWN)
			{
				yI+=10;
			}
			s-=2;
		}
		
		if(((xI>=arr[4]-15) and xI<=(arr[4]+32)) and ((yI>=arr[5]-15) and yI<=(arr[5]+34)))
		{
			if(key==GLUT_KEY_RIGHT)
			{
				xI-=10;
			}
			else if(key==GLUT_KEY_LEFT)
			{
				xI+=10;
			}
			else if(key==GLUT_KEY_UP)
			{
				yI-=10;
			}
			else if(key==GLUT_KEY_DOWN)
			{
				yI+=10;
			}
			s-=2;
		}
	}

void random_pers()
{
	pers_arr[0]=(rand()%1000)+10;
	pers_arr[1]=(rand()%820)+10;
	check_place(pers_arr[0],pers_arr[1]);
	
	pers_arr[2]=(rand()%1000)+10;
	pers_arr[3]=(rand()%820)+10;
	check_place(pers_arr[2],pers_arr[3]);
	
	pers_arr[4]=(rand()%1000)+10;
	pers_arr[5]=(rand()%820)+10;
	check_place(pers_arr[4],pers_arr[5]);

}


/*
	1=if((xI>=830 && xI<=880 ) && (yI>=340  && yI<=390 ))
	2=if((xI>=340 && xI<=510 ) && (yI>=335  && yI<=390 ))
	3=if((xI>=460 && xI<=510 ) && (yI>=390  && yI<=430 ))
	4=if((xI>=315 && xI<=565 ) && (yI>=690  && yI<=740 ))
	5=if((xI>=60 && xI<=180 ) && (yI>=410  && yI<=460 ))
	6=if((xI>=490 && xI<=620 ) && (yI>=10  && yI<=60 )
	7=if((xI>=785 && xI<=880 ) && (yI>=690  && yI<=740 ))
	8=if((xI>=830 && xI<=880 ) && (yI>=650  && yI<=690 ))
	9=if((xI>=830 && xI<=880 ) && (yI<=140  && yI>=90 ))
	10=if((xI>=785 && xI<=880 ) && (yI>=50  && yI<=100 ))
*/

void result()
{	
		glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
			unsigned char key;
	glClear (GL_COLOR_BUFFER_BIT);
	
//	DrawString( 500, 500,"NAME=", n,a,m,e , colors[BLUE]);
	DrawString( 300, 400,"SCORE="+to_string(s) , colors[BLUE]);
	DrawString( 300, 600,"PRESS ESC TO EXIT" , colors[BLUE]);
	glutSwapBuffers();
	
	glutPostRedisplay();

}






//===================================================
/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {

	int width = 1100, height = 1020; // i have set my window size to be 800 x 600

 	srand((unsigned int)time(0));
	rando_place();
	random_pers();
	
	char n,a,m,e;
	
	cout<<"enter name first"<<endl;
	cin>>n>>a>>m>>e;
	
	string file_name = "NAME.1";
	ofstream data_out;
	data_out.open(file_name);
    
	if(data_out)
	{
        data_out<<n<<a<<m<<e<<"  ";
        data_out<<s<<endl;
    }
    
    
    
	//InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("Rush Hour by Nouman Ahmad"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

//	glutDisplayFunc(MenuDisplay); // tell library which function to call for drawing Canvas.
	MenuDisplay();
	//glutDisplayFunc(GameDisplay);
//	}
//	NonPrintableKeys();
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);
	glutTimerFunc(1000.0, Timmy, 0);
	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}


#endif /* RushHour_CPP_ */






