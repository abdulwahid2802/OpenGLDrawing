#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

bool keys[256];						// active keys we are going to use
bool active = true;					// tells if the window has been minimized or not
bool fullScreen = true;				// tell if the screen is full screen


GLvoid ReSizeGLScene(GLsizei width, GLsizei height)             // Resize And Initialize The GL Window
{
	if (height == 0)                              // Prevent A Divide By Zero By
	{
		height = 1;                           // Making Height Equal One
	}

	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);                        // Select The Projection Matrix
	glLoadIdentity();                           // Reset The Projection Matrix
												// Calculate The Aspect Ratio Of The Window
	gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 100.0f);

	glMatrixMode(GL_MODELVIEW);                     // Select The Modelview Matrix
	glLoadIdentity();                           // Reset The Modelview Matrix
}
