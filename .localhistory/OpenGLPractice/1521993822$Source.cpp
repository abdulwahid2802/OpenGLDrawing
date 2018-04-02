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

void MyDisplay() {                      //디스플레이 콜백함수
	glClear(GL_COLOR_BUFFER_BIT);       //GL 상태변수 설정
	glViewport(0, 0, 300, 300);
	glBegin(GL_TRIANGLES);                //입력 기본요소 정의

	glColor3f(0, 1.0, 0);
	glVertex3f(-0.5, -0.5, 0.0);
	glColor3f(1.0, 0, 0);
	glVertex3f(0.5, -0.5, 0.0);
	glColor3f(0, 0, 1.0);
	glVertex3f(0.5, 0.5, 0.0);

	glEnd();
	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);               //GLUT 윈도우 함수
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(1080, 300);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OpenGL Sample Drawing");
	glutFullScreen();
	glClearColor(0.0, 0.0, 0.0, 0.1);   //GL 상태변수 설정
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

	glutDisplayFunc(MyDisplay);         //GLUT 콜백함수 등록
	glutMainLoop();                     //이벤트 루프 진입
	return 0;
}
