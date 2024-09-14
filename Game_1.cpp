
#include <iostream>
#include <gl/glut.h>

int circle = 0, rectangle = 0, triangle = 0, square = 0;
bool NoSelection = true;

void drawText(double x, double y, std::string text) {
    glColor3f(0.0, 0.0, 0.0);
    glRasterPos2d(x, y);
    for (int i = 0; i < text.size(); i++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
    }
}

void ChangeSize(int w, int h) {

    glutReshapeWindow(600, 600);
}

void Rectangle() {
    glLineWidth(5);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 1.0, 0.0);
    glVertex2d(0.2, -0.35);
    glVertex2d(0.2, -0.65);
    glVertex2d(0.8, -0.65);
    glVertex2d(0.8, -0.35);
    glEnd();
    glFlush();
}

void Circle() {
    double angle;

    glColor3f(1.0, 0.0, 0.0);

    glLineWidth(5);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 360; i++)
    {
        angle = i * 3.142 / 180;
        glVertex2d(0.35 * cos(angle) + 0.5, 0.5 + 0.35 * sin(angle));
    }
    glEnd();
    glFlush();
}

void Square() {

    glLineWidth(5);
    glBegin(GL_LINE_LOOP);
    glColor3f(1.0, 1.0, 0.0);
    glVertex2d(-0.2, -0.2);
    glVertex2d(-0.2, -0.8);
    glVertex2d(-0.8, -0.8);
    glVertex2d(-0.8, -0.2);
    glEnd();
    glFlush();
}

void Triangle() {
    glLineWidth(5);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2d(-0.2, 0.2);
    glVertex2d(-0.5, 0.8);
    glVertex2d(-0.8, 0.2);
    glEnd();
    glFlush();
}

void display()
{
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    if (NoSelection) {
        Triangle();
        drawText(-0.75, 0.1, "push the button T");
        Rectangle();
        drawText(0.24, -0.75, "push the button R");
        Circle();
        drawText(0.25, 0.05, "push the button C");
        drawText(-0.75, -0.9, "push the button S");
        Square();
    }

    else if (rectangle) {
        drawText(0.1, -0.75, "You Choosed Rectangle");
        Rectangle();
    }
    else if (triangle) {
        drawText(-0.87, 0.1, "You Choosed Triangle");
        Triangle();
    }
    else if (circle) {
        drawText(0.17, 0.05, "You Choosed Circle");
        Circle();
    }
    else if (square) {
        drawText(-0.85, -0.9, "You Choosed Square");
        Square();
    }

}

void Keys(unsigned char key, int x, int y) {
    if ((key == 'c' || key == 'C') && NoSelection)
        circle = 1, NoSelection = false;
    else if ((key == 't' || key == 'T') && NoSelection)
        triangle = 1, NoSelection = false;
    else if ((key == 's' || key == 'S') && NoSelection)
        square = 1, NoSelection = false;
    else if ((key == 'r' || key == 'R') && NoSelection)
        rectangle = 1, NoSelection = false;
}

void Display(int value) {
    glutPostRedisplay();
    glutTimerFunc(40, Display, 1);
}


int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(600, 600);
    glutCreateWindow("The Third Game");
    glutReshapeFunc(ChangeSize);
    glutKeyboardFunc(Keys);
    glutDisplayFunc(display);
    glutTimerFunc(40, Display, 1);
    glutMainLoop();
    return 0;
}
