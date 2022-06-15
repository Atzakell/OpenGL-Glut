#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

void menu_principal(int);
GLdouble angulo = 0;
GLint modelo = 0;
void Circunferencia(void)
{
    float ang, radio = 8.0f, x, y;
    glBegin(GL_LINE_LOOP);
    for (ang = 0.0; ang < 2 * M_PI; ang += 2 * M_PI / 50)
    {
        x = radio * cos(ang);
        y = radio * sin(ang);
        glVertex2f(x, y);
    }
    glEnd();
}
void Caracol(void)
{
    float ang, radio, x, y;
    glBegin(GL_LINE_LOOP);
    for (ang = 0.0; ang < 2 * M_PI; ang += 2 * M_PI / 50)
    {
        radio = 4 + 4 * sin(ang);
        x = radio * cos(ang);
        y = radio * sin(ang);
        glVertex2f(x, y);
    }
    glEnd();
}
void Rosal(void)
{
    float ang, radio, x, y;
    glBegin(GL_LINE_LOOP);
    for (ang = 0.0; ang < 2 * M_PI; ang += 2 * M_PI / 50)
    {
        radio = 6 * cos(2 * ang);
        x = radio * cos(ang);
        y = radio * sin(ang);
        glVertex2f(x, y);
    }
    glEnd();
}
void iniciar(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(1.0, 0.0, 0.0);
    glLineWidth(2.0);
    glShadeModel(GL_FLAT);
}
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    menu_principal(modelo);
    glFlush();
    glutSwapBuffers();
}
void myReshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-10.0, 10.0, -10.0, 10, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
void menu_color(int opcion)
{
    switch (opcion)
    {
    case 1:
        glColor3f(1.0, 0.0, 0.0);
        break;
    case 2:
        glColor3f(0.0, 1.0, 0.0);
        break;
    case 3:
        glColor3f(0.0, 0.0, 1.0);
        break;
    }
}
void menu_principal(int opcion)
{
    switch (opcion)
    {
    case 1:
        modelo = 1;
        Circunferencia();
        break;
    case 2:
        modelo = 2;
        Caracol();
        break;
    case 3:
        modelo = 3;
        Rosal();
        break;
    case 5:
        exit(-1);
    }
    glutPostRedisplay();
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Modelos b usando menus jerarquicos con Glut ");
    int submenu_color = glutCreateMenu(menu_color);
    glutAddMenuEntry("Rojo", 1);
    glutAddMenuEntry("Verde", 2);
    glutAddMenuEntry("Azul", 3);
    int menu = glutCreateMenu(menu_principal);
    glutAddMenuEntry("Circunferencia", 1);
    glutAddMenuEntry("Caracol", 2);
    glutAddMenuEntry("Rosal", 3);
    glutAddMenuEntry("Esc", 5);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    iniciar();
    glutReshapeFunc(myReshape);
    glutDisplayFunc(display);
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
    return 0;
}