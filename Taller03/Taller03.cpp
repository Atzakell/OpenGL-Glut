#include <math.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

void recta_punto_medio(int,int,int,int);
void inicio(void);
void display(void);
void myreshape(int, int);
void abasico(int, int, int, int);
void dda(int, int, int, int);
void dibujarpunto(int,int);
void circunferencia_parametrica(int );
void circunferencia_punto_medio(int, int, int);

float delta;
int px0=-40;
int py0=-40;
int px1=40;
int py1=30;
int main(int argc, char** argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Algoritmos de primitivas graficas");
    inicio();
    glutDisplayFunc(display);
    glutReshapeFunc(myreshape);
    glutMainLoop();
    return 0;
}
void inicio(void)
{
    glClearColor(1.0,1.0,1.0,0.0); //parametros: rojo, amarillo y azul, el cuarto es el parametro

    glShadeModel(GL_FLAT);
}
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix(); // salva el estado actual de la matriz
    glColor3f(0,0,1); // Azul
    glPointSize(5); // Fije el grosor de pixel = 2

    abasico(px0, py0, px1, py1);
    glColor3f(1,0,0);
    dda(px0, py0+5, px1, py1+5);
    glColor3f(0,1,0);
    recta_punto_medio(px0, py0+10, px1, py1+10);
    glColor3f(0.1f, 0.0f, 0.0f);
    circunferencia_punto_medio(0, 0, 40);

    glPopMatrix(); // recupera el estado del matriz
    glFlush();
}
void myreshape(int w, int h)
{
    glViewport(0,0,(GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-50.0, 50.0, -50.0, 50, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
void abasico(int x0,int y0,int x1,int y1)
{
    int x;
    float dx, dy, m, b, y;
    dx = x1 - x0;
    dy = y1 - y0;
    m = dy/dx;
    b = y0 - m*x0;
    y = y0;
    for(x=x0; x<=x1; x++)
    {
        y = m*x + b;
        dibujarpunto(x,(int)ceil(y-0.5));
    }
}
// opcional

void dda(int x0,int y0,int x1,int y1)
{
    int x;
    float dx, dy, m,y;
    dx = x1-x0;
    dy = y1-y0;
    m = dy/dx;
    y = (float)y0;
    for(x=x0; x<=x1; x++)
        {
            dibujarpunto(x,(int)ceil(y-0.5));
            y += m;
        }
}

void dibujarpunto(int x0,int y0)
{
    glBegin(GL_POINTS);
        glVertex2f(x0,y0);
    glEnd();
}

void recta_punto_medio(int x0, int y0, int x1, int y1)
{
    int dx, dy, dE, dNE, d, x, y;
    dx = x1 - x0;
    dy = y1- y0;
    d = 2*dy - dx;
    dE = 2*dy;
    dNE = 2*(dy - dx);
    x = x0;
    y = y0;
    dibujarpunto(x,(int)ceil(y-0.5));
    while (x<x1)
        {
        if(d<=0){
            d += dE;
            x++;
            }
        else{
            d += dNE;
            x++;
            y++;
            }
        dibujarpunto(x,(int)ceil(y-0.5));
        }
}

void circunferencia_punto_medio(int h, int k, int R)
{
// discretizacion valida en el II octante
int x=0;
int y=R,d=1-R;
dibujarpunto(x+h,y+k);
while (x<y){
    if (d<0)
        d+=2*x+3;
    else{
        d+=2*(x-y)+5;
        y--;
    }
    x++;
    dibujarpunto(x+h,y+k);
    dibujarpunto(-x+h,y+k);
    dibujarpunto(-y+h,x+k);
    dibujarpunto(-y+h,-x+k);
    dibujarpunto(-x+h,-y+k);
    dibujarpunto(x+h,-y+k);
    dibujarpunto(y+h,-x+k);
    dibujarpunto(y+h,x+k);
}
}