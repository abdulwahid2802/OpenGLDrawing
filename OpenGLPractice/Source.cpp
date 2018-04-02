#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include<iostream>

float angle = 0.0;

GLfloat light_diffuse[] = { .5, .5, 0.5, 1.0 };  /* Red diffuse light. */
GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };  /* Infinite light location. */
GLfloat n[6][3] = {  /* Normals for the 6 faces of a cube. */
	{ -1.0, 0.0, 0.0 },{ 0.0, 1.0, 0.0 },{ 1.0, 0.0, 0.0 },
{ 0.0, -1.0, 0.0 },{ 0.0, 0.0, 1.0 },{ 0.0, 0.0, -1.0 } };
GLint faces[6][4] = {  /* Vertex indices for the 6 faces of a cube. */
	{ 0, 1, 2, 3 },{ 3, 2, 6, 7 },{ 7, 6, 5, 4 },
{ 4, 5, 1, 0 },{ 5, 6, 2, 1 },{ 7, 4, 0, 3 } };
GLfloat v[8][3];  /* Will be filled in with X,Y,Z vertexes. */


void drawBox(void)
{
	//glRotatef(angle, 0, 1.0, 0.0);
	//glRotatef(angle, 0.0, 0.0, 1.0);
	int i;
	for (i = 0; i < 6; i++) {
		glBegin(GL_QUADS);
		glNormal3fv(&n[i][0]);
		glVertex3fv(&v[ faces[i][0] ][0]);
		glVertex3fv(&v[ faces[i][1] ][0]);
		glVertex3fv(&v[ faces[i][2] ][0]);
		glVertex3fv(&v[ faces[i][3] ][0]);
		glEnd();
	}

	angle += .1;
}

void drawCircle()
{
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i <= 300; i++) {
		double angle = 2 * 3.14 * i / 300;
		double x = cos(angle);
		double y = sin(angle);
		glVertex2d(x-2, y-2);
	}
	glEnd();
}

void drawTRI()
{
	gluLookAt(
		0.0f, .0f, 8.0f,
		0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f
	);

	glRotatef(angle, 0, 1, 0);

	glBegin(GL_TRIANGLES);
	glColor3f(0.1, 0, 0);
	glVertex3d(-4.0f, 3.0f, 0.0f);
	glColor3f(0, 1, 0);
	glVertex3f(-2.0f, 3.0f, 0.0);
	glColor3f(0, 0, 1);
	glVertex3f(-3.0f, 1.0f, 0.0);


	glEnd();
}

void initBox(void)
{
	/* Setup cube vertex data. */
	v[0][0] = v[1][0] = v[2][0] = v[3][0] = -1;
	v[4][0] = v[5][0] = v[6][0] = v[7][0] = 1;
	v[0][1] = v[1][1] = v[4][1] = v[5][1] = -1;
	v[2][1] = v[3][1] = v[6][1] = v[7][1] = 1;
	v[0][2] = v[3][2] = v[4][2] = v[7][2] = 1;
	v[1][2] = v[2][2] = v[5][2] = v[6][2] = -1;

	/* Enable a single OpenGL light. */
	//glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);

	/* Use depth buffering for hidden surface elimination. */
	//glEnable(GL_DEPTH_TEST);

	/* Setup the view of the cube. */
	glMatrixMode(GL_PROJECTION);
	gluPerspective( /* field of view in degree */ 45.0,
		/* aspect ratio */ 1.0,
		/* Z near */ 1.0, /* Z far */ 1000.0);
	glMatrixMode(GL_MODELVIEW);
	//gluLookAt(0.0, 0.0, 5.0,  /* eye is at (0,0,5) */
	//	0.0, 0.0, 0.0,      /* center is at (0,0,0) */
	//	0.0, 1.0, 0.);      /* up is in positive Y direction */

							/* Adjust cube position to be asthetic angle. */
	glTranslatef(0.0, 0.0, 0.0);
	glRotatef(60, 1.0, 0.0, 0.0);
	glRotatef(-20, 0.0, 0.0, 1.0);
}

void renderScene(void) {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();	

	
	drawTRI();
	drawBox();
	drawCircle();
	glutSwapBuffers();
}

void onResizeScreen(GLsizei width, GLsizei height)
{
	if (height==0) height = 1;

	double ratio = width * 1.0 / height;

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();
	
	glViewport(0, 0, width, height);
	
	std::cout << width << std::endl << height;

	gluPerspective(45, ratio, 1, 1000);

	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv) {

	// init GLUT and create Window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);  // starting postion of the window
	glutInitWindowSize(640, 480);
	glutCreateWindow("Wahid Coding School");


	glutReshapeFunc(onResizeScreen); // gets called when the window size changes
	glutDisplayFunc(renderScene);  // calls the disnplay renderer func
	glutIdleFunc(renderScene);
	initBox();
	glutMainLoop();

	return 1;

}