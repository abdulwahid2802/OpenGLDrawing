#include <GL/glut.h>
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

	glRotatef(-90, 0.0, 0.1, 0.0);
	glRotatef(-20, 0.0, .0, 0.1);


	glBegin(GL_QUADS);
	// front
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.8f, 0.0f, 0.0f);
	glVertex3f(0.8f, 0.8f, 0.0f);
	glVertex3f(0.0f, 0.8f, 0.0f);
	// back
	glVertex3f(0.0f, 0.0f, -0.8f);
	glVertex3f(0.8f, 0.0f, -0.8f);
	glVertex3f(0.8f, 0.8f, -0.8f);
	glVertex3f(0.0f, 0.8f, -0.8f);
	// right
	glVertex3f(0.8f, 0.0f, 0.0f);
	glVertex3f(0.8f, 0.0f, -0.8f);
	glVertex3f(0.8f, 0.8f, -0.8f);
	glVertex3f(0.8f, 0.8f, 0.0f);
	// left
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, -0.8f);
	glVertex3f(0.0f, 0.8f, -0.8f);
	glVertex3f(0.0f, 0.8f, 0.0f);
	// top
	glVertex3f(0.0f, 0.8f, 0.0f);
	glVertex3f(0.8f, 0.8f, 0.0f);
	glVertex3f(0.8f, 0.8f, -0.8f);
	glVertex3f(0.0f, 0.8f, -0.8f);
	// bottom
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.8f, 0.0f, 0.0f);
	glVertex3f(0.8f, 0.0f, -0.8f);
	glVertex3f(0.0f, 0.0f, -0.8f);
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