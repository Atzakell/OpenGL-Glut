#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>

void init(void);
void reshape(int, int);
void display(void);
void reshape(int, int );
void lineas(int);
void circulos(int);

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
glClearColor(1.0,1.0,1.0,0);
}

void display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glPointSize(10);
    glColor3f(1.0f,0.5f,0.5f);
    lineas(10);
    glColor3f(0.5f,1.0f,0.5f);
    for (int i = 0; i < 10; i++)
    {
        circulos(10);
    }
    
    glPopMatrix();      
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

void lineas(int r){
    GLfloat ang, x,y, radio=r;
    for (ang = 0.0f; ang < 2*M_PI; ang+=2*M_PI/15){
        glBegin(GL_LINES);
        glVertex2f(0,0);
        x=radio*cos(ang);
        y=radio*sin(ang);
        glVertex2f(x,y);
        glEnd();
    }
    
}



void circulos(int r){
    GLfloat ang,x,y,radio=r;
    glBegin(GL_LINE_LOOP);
    for (ang = 0.0f; ang < 2*M_PI; ang+= 2*M_PI/20)
    {
        x=radio*cos(ang);
        y=radio*sin(ang);
        glVertex2f(x,y);
    }
    glEnd();
}

