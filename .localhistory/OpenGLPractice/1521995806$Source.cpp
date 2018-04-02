#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

void renderScene(void) {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glBegin(GL_TRIANGLES);
	glVertex3f(-0.5, -0.5, 0.0);
	glVertex3f(0.5, 0.0, 0.0);
	glVertex3f(0.0, 0.5, 0.0);
	glEnd();

	glutSwapBuffers();
}

void onResizeScreen(GLsizei width, GLsizei height)
{
	if (!height) height = 1;

	GLfloat ratio = 1.0 * width / height;

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


	glutDisplayFunc(renderScene);  // calls the disnplay renderer func
	glutReshapeFunc(onResizeScreen); // gets called when the window size changes
	glutMainLoop();

	return 1;

}