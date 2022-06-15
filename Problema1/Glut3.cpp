#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

void init(void);
void gluDisk(GLUquadricObj *pt, GLdouble rinterior, GLdouble rexterior, GLint nlados, GLint nvueltas);

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB); 
    glutInitWindowSize(800, 800);     
    glutInitWindowPosition(100, 100); 
    glutCreateWindow("Disco");     
    init();

    glutMainLoop();          
    return 0;
}


void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0); // parametro, rojo, amarillo y azul, el cuarto es alpha
    glShadeModel(GL_FLAT);            // glClear(borrar buffer)
}

void gluDisk(GLUquadricObj *pt, GLdouble rinterior, GLdouble rexterior, GLint nlados, GLint nvueltas){
    GLUquadricObj *pt;
    pt=gluNewQuadric();
    // esta orden especifica como va a ser renderizado:
    gluQuadricDrawStyle(pt,GLU_LINE);
    glColor3f (1.0, 0.0, 0.0);
    // Dibuja Discos
    gluDisk(pt, 4, 9, 15, 6);
}