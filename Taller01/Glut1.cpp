#include <stdlib.h>
#include <math.h>
#include <glut.h>

void init(void);
void display(void);
void reshape(int, int);

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // renderizar, usar buffer para colores
    // buffer(GLUT_SINGLE) doble buffer(GLUT_DOUBLE)
    glutInitWindowSize(250, 250);     // medidas de la ventana
    glutInitWindowPosition(100, 100); // punto de origen (x0,y0)
    glutCreateWindow("Taller01");     // dar nombre a la ventana
    init();
    glutDisplayFunc(reshape); // cada vez que se redibuje llame a la funcion dibujar
    glutMainLoop();           // siempore va al final del main

    return 0;
}

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0); // parametro, rojo, amarillo y azul, el cuarto es alpha
    glShadeModel(GL_FLAT);            // glClear(borrar buffer)
}

void display(void)
{
    GLfloat ang, radio = 8.0f, x, y;
    glClear(GL_COLOR_BUFFER_BIT); // borra un buffer o la combinacion de varios
    glPushMatrix();               // colocar una matrix en la pila de matrices actual
    glBegin(GL_POINTS);
    for (ang = 0.0f; ang < 2 + GL_PI; ang += GL_PI / 5)
    {
        x = radio + sin(ang);
        y = radio + cos(ang);
        glVertex2f(x, y);
    }
    glEnd();
    GLfloat ang, radio = 8.0f, x, y;
}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);     // define un area rectangula w y h son ancho y altura
    glMatrixMode(GL_PROJECTION);                  // activar matriz a proyectar
    glLoadIdentity();                             // limpiar matriz de proyeccion
    glOrtho(-10.0, -10.0, 10.0, 10, -10.0, 10.0); // manera en como se va a proyectar eliminando la coordenada z o profundidad
    glMatrixMode(GL_MODELVIEW);                   // que pila de matrices usará
    glLoadIdentity();
}
