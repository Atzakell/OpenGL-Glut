#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>

void ejes2D(void);
void bordecirculo(int,int,int);
void circulo(int,int,int);
void caracol(void);
void init(void);
void display(void);
void reshape(int,int);

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(1000,800);
    glutInitWindowPosition(100,100);
    glutCreateWindow(argv[0]);
    init();
    char p;
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}

void init(void)
{
glClearColor(1.0,1,1,0);
}

void display(void)
{

    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glPointSize(2);
    glColor3f(0,0,1);
    ejes2D();
    glColor3f(1,0,0);
    caracol();
    glColor3f(1,0,0);
    bordecirculo(0,5,4);

    glLineWidth(5);
    glColor3f(0,0,1);
    glLineStipple(2,0xAAAA);
    glEnable(GL_LINE_STIPPLE);
    bordecirculo(5,-5,5);
    glDisable(GL_LINE_STIPPLE);

    glColor3f(0,1,0);
    circulo(-5,-5,5);
    glPopMatrix();      // reecupera el estado del matriz
    glFlush();
}
void reshape(int w, int h)
{
    glViewport(0,0,(GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-10.0,10.0,-10.0,10,-10.0,10.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
void bordecirculo(int h,int k,int radio)
{
GLfloat ang, x, y;
    glBegin(GL_LINE_LOOP);
        for (ang = 0.0f; ang < 2 * M_PI; ang += 2*M_PI/100)
            {
            x = h+radio * cos(ang);
            y = k+radio * sin(ang);
            glVertex2f(x,y);
            }
    glEnd();
}

void circulo(int h,int k,int radio)
{
GLfloat ang, x, y;
    glBegin(GL_POLYGON);
        for (ang = 0.0f; ang < 2 * M_PI; ang += 2*M_PI/10)
            {
            x = h+radio * cos(ang);
            y = k+radio * sin(ang);
            glVertex2f(x,y);
            }
    glEnd();
}

void ejes2D(void)
{
    glBegin(GL_LINES);
        glVertex2f(-50,0);
        glVertex2f(50,0);
        glVertex2f(0,50);
        glVertex2f(0,-50);
    glEnd();
}

void caracol(void)
{
GLfloat ang,radio, x, y;
    glBegin(GL_LINE_LOOP);
        for (ang = 0.0f; ang < 2 * M_PI; ang += 2*M_PI/100)
            {
            radio=2+4*sin(ang);
            x = radio * cos(ang);
            y = radio * sin(ang);
            glVertex2f(x,y);
            }
    glEnd();
}