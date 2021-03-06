﻿#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>
#include<iostream>

#define PI 3.1415926535897932384626433832795

GLfloat n[6][3] = {  /* Normals for the 6 faces of a cube. */
	{ -1.0, 0.0, 0.0 },{ 0.0, 1.0, 0.0 },{ 1.0, 0.0, 0.0 },
{ 0.0, -1.0, 0.0 },{ 0.0, 0.0, 1.0 },{ 0.0, 0.0, -1.0 } };
GLint faces[6][4] = {  /* Vertex indices for the 6 faces of a cube. */
	{ 0, 1, 2, 3 },{ 3, 2, 6, 7 },{ 7, 6, 5, 4 },
{ 4, 5, 1, 0 },{ 5, 6, 2, 1 },{ 7, 4, 0, 3 } };
GLfloat v[8][3];  /* Will be filled in with X,Y,Z vertexes. */


void drawSquare()
{
	glViewport(0, 0, 500, 500);
	glColor3f(.5, .5, .5);

	glBegin(GL_POLYGON);                //입력 기본요소 정의
	glVertex3f(-1, -1, 0.0);
	glVertex3f(1, -1, 0.0);
	glVertex3f(1, 1, 0.0);
	glVertex3f(-1, 1, 0.0);
	glEnd();
	
}

void drawTriangle()
{
	glViewport(0, 250, 250, 250);
	glColor3f(1.0, 1.0, 1.0);

	glBegin(GL_TRIANGLES);                //입력 기본요소 정의
	glVertex3f(-0.9, -0.9, 0.0);
	glVertex3f(0.9, -0.9, 0.0);
	glVertex3f(0.0, 0.9, 0.0);
	glEnd();
}

void drawCircle1()
{
	glViewport(250, 250, 250, 250);
	glColor3f(1.0, 1.0, 1.0);

	glBegin(GL_LINE_LOOP);
	//glBegin(GL_POLYGON);    // this is for solid circle which is filled inside

	for (int i = 0; i <= 300; i++) {
		double angle = 2 * PI * i / 300;
		double x = cos(angle);
		double y = sin(angle);
		glVertex2d(x / 1.1 , y / 1.1);
	}
	glEnd();
}

void drawHexa()
{
	glViewport(0, 0, 250, 250);
	glColor3f(1.0, 1.0, 1.0);

	glBegin(GL_POLYGON);
	for (int i = 0; i < 6; ++i) {
		glVertex2f(sin(i / 6.0 * 2 * PI) / 1.1,
			cos(i / 6.0 * 2 * PI) / 1.1);
	}
	glEnd();

}


void drawCube()
{
	glViewport(250, 0, 250, 250);
	glColor3f(1.0, 1.0, 1.0);


	/* Setup cube vertex data. */
	v[0][0] = v[1][0] = v[2][0] = v[3][0] = -0.8;
	v[4][0] = v[5][0] = v[6][0] = v[7][0] = 0.8;
	v[0][1] = v[1][1] = v[4][1] = v[5][1] = -0.8;
	v[2][1] = v[3][1] = v[6][1] = v[7][1] = 0.8;
	v[0][2] = v[3][2] = v[4][2] = v[7][2] = 0.8;
	v[1][2] = v[2][2] = v[5][2] = v[6][2] = -0.8;


	int i;
		glBegin(GL_QUADS);
	for (i = 0; i < 6; i++) {
		glNormal3fv(&n[i][0]);
		glVertex3fv(&v[faces[i][0]][0]);
		glColor3f(.3, .3, .3);
		glVertex3fv(&v[faces[i][1]][0]);
		glColor3f(.5, .5, .5);
		glVertex3fv(&v[faces[i][2]][0]);
		glColor3f(.8, .8, .8);
		glVertex3fv(&v[faces[i][3]][0]);
	}
	glRotatef(60, 1.0, 0.0, 0.0);
	glRotatef(-20, 0.0, 0.0, 1.0);
		glEnd();
}

void MyDisplay() {                      //디스플레이 콜백함수
	glClear(GL_COLOR_BUFFER_BIT);       //GL 상태변수 설정
	
	drawSquare();

	/* Define Viewport, Color and Vertex for TRIANGLES*/
	drawTriangle();

	/* Define Viewport, Color and Vertex for CIRCLE*/
	drawCircle1();

	/* Define Viewport, Color and Vertex for hexagon*/
	drawHexa();


	/* Define Viewport, Color and Vertex for cube*/

	drawCube();

	glFlush();
}


int main(int argc, char** argv) {
	glutInit(&argc, argv);               //GLUT 윈도우 함수
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OpenGL Sample Drawing");

	glClearColor(0.0, 0.0, 0.0, 1.0);   //GL 상태변수 설정
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

	glutDisplayFunc(MyDisplay);         //GLUT 콜백함수 등록
	glutMainLoop();                     //이벤트 루프 진입
	return 0;
}