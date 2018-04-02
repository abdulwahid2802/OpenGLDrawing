#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>
#include<iostream>

#define PI 3.1415926535897932384626433832795

void MyDisplay() {                      //디스플레이 콜백함수
	glClear(GL_COLOR_BUFFER_BIT);       //GL 상태변수 설정
	glViewport(0, 0, 500, 500);
	glColor3f(1.0, 1.0, 1.0);

	glBegin(GL_POLYGON);                //입력 기본요소 정의
	glVertex3f(-0.5, -0.5, 0.0);
	glVertex3f(0.5, -0.5, 0.0);
	glVertex3f(0.5, 0.5, 0.0);
	glVertex3f(-0.5, 0.5, 0.0);
	glEnd();

	/* Define Viewport, Color and Vertex for TRIANGLES*/

	/* Define Viewport, Color and Vertex for CIRCLE*/

	/* Define Viewport, Color and Vertex for hexagon*/

	/* Define Viewport, Color and Vertex for hexagon*/


	glFlush();
}

void onResizeScreen(GLsizei width, GLsizei height)
{
	if (height == 0) height = 1;

	double ratio = width * 1.0 / height;

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	glViewport(0, 0, width, height);

	std::cout << width << std::endl << height;

	gluPerspective(45, ratio, 1, 1000);

	glMatrixMode(GL_MODELVIEW);
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
	//glutReshapeFunc(onResizeScreen);
	glutMainLoop();                     //이벤트 루프 진입
	return 0;
}