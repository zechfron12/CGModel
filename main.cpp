#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "GL/glut.h"

unsigned char prevKey;


void Init(void) {
    glClearColor(1.0, 1.0, 1.0, 1.0);

    glLineWidth(3);

    glPointSize(4);

    glPolygonMode(GL_FRONT, GL_LINE);
}

void Display1() {
    glColor3f(0.2, 0.15, 0.88);
    glBegin(GL_LINES); // line drawing
    glVertex2i(1, 1); // vertice coordinates
    glVertex2i(-1, -1);
    glEnd();

    glColor3f(1, 0.1, 0.1);
    unsigned char prevKey;
    glBegin(GL_LINES);
    glVertex2i(-1, 1);
    glVertex2i(1, -1);
    glEnd();
 
    glBegin(GL_LINES);
    glVertex2d(-0.5, 0);
    glVertex2d(0.5, 0);
    glEnd();
}

void Display2() {
    glColor3f(1, 0.1, 0.1); 

    glBegin(GL_LINES);
    glVertex2f(1.0, 1.0);
    glVertex2f(0.9, 0.9);
    glVertex2f(0.8, 0.8);
    glVertex2f(0.7, 0.7);
    glVertex2f(0.6, 0.6);
    glVertex2f(0.5, 0.5);
    glVertex2f(-0.5, -0.5);
    glVertex2f(-1.0, -1.0);
    glEnd();
}

void Display(void) {
    printf("Call Display\n");

    glClear(GL_COLOR_BUFFER_BIT);

    switch (prevKey) {
    case '1':
        Display1();
        break;
    case '2':
        Display2();
        break;
    default:
        break;
    }
    glFlush();
}


void Reshape(int w, int h) {
    printf("Call Reshape : width = %d, height = %d\n", w, h);
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
}

void KeyboardFunc(unsigned char key, int x, int y) {
	printf("You have pressed <%c>. The mouse has the position %d, %d.\n",
		key, x, y);

	prevKey = key;
	if (key == 27) // escape
		exit(0);
	glutPostRedisplay();
}

void MouseFunc(int button, int state, int x, int y) {
	printf("Call MouseFunc : you have %s the %s button in the position %d %d\n",
		(state == GLUT_DOWN) ? "pressed" : "released",
		(button == GLUT_LEFT_BUTTON) ?
		"left" :
		((button == GLUT_RIGHT_BUTTON) ? "right" : "middle"),
		x, y);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(100, 100);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow(argv[0]);

	Init();


	glutReshapeFunc(Reshape);

	glutKeyboardFunc(KeyboardFunc);
	glutMouseFunc(MouseFunc);
	glutDisplayFunc(Display);



	glutMainLoop();
	return 0;
}