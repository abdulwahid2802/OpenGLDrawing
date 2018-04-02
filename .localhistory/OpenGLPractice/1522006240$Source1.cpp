#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>
#include<iostream>

#define PI 3.1415926535897932384626433832795

void drawSquare()
{
	glViewport(0, 0, 500, 500);
	glColor3f(.0, 1.0, .0);

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
	glVertex3f(-0.5, -0.5, 0.0);
	glVertex3f(0.5, -0.5, 0.0);
	glVertex3f(0.0, 0.5, 0.0);
	glEnd();
}

void drawCircle1()
{
	glViewport(250, 250, 250, 250);
	glColor3f(1.0, 1.0, 1.0);

	glBegin(GL_LINE_LOOP);
	for (int i = 0; i <= 300; i++) {
		double angle = 2 * PI * i / 300;
		double x = cos(angle);
		double y = sin(angle);
		glVertex2d(x / 2, y / 2);
	}
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


	/* Define Viewport, Color and Vertex for hexagon*/


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