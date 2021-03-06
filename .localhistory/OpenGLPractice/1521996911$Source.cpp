﻿#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

float angle = 0.0;


void renderScene(void) {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();

	gluLookAt(
		0.0f, 0.0f, 10.0f,
		0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f
	);

	glRotatef(angle, 1, 1, 1);

	glBegin(GL_TRIANGLES);
	glVertex3f(-2.0f, -2.0f, 0.0f);
	glVertex3f(2.0f, 0.0f, 0.0);
	glVertex3f(0.0f, 2.0f, 0.0);
	glEnd();

	angle += 0.05;

	glutSwapBuffers();
}

void onResizeScreen(GLsizei width, GLsizei height)
{
	if (height==0) height = 1;

	double ratio = width * 1.0 / height;

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();
	
	glViewport(0, 0, width, height);
	
	gluPerspective(45, ratio, 1, 1000);

	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv) {

	// init GLUT and create Window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(320, 320);
	glutCreateWindow("Lighthouse3D- GLUT Tutorial");


	glutReshapeFunc(onResizeScreen); // gets called when the window size changes
	glutDisplayFunc(renderScene);  // calls the disnplay renderer func
	glutIdleFunc(renderScene);
	glutMainLoop();

	return 1;

}