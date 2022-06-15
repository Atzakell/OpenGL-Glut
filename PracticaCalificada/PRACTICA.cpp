#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

GLdouble angulo = 0;
GLint modelo = 0;
void menu_principal(int);
void Circunferencia(void);
void Caracol(void);
void Rosal(void);
void bordecirculo(int , int , int);
void iniciar(void);
void display(void);
void myReshape(int , int);
void salir(void);
void menu_patron(int);
void menu_grosor(int);
void menu_polares(int);
void menu_color(int);
void menu_principal(int);
void ejes2D(void);


int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Modelos b usando menus jerarquicos con Glut ");

    //int submenu_salir=glutCreateMenu(salir);
    //glutAddMenuEntry("Salir", 1);

    int submenu_patron=glutCreateMenu(menu_patron);
    glutAddMenuEntry("Opcion 1", 1);
    glutAddMenuEntry("Opcion 2", 2);

    int submenu_Grosor=glutCreateMenu(menu_grosor);
    glutAddMenuEntry("3", 1);
    glutAddMenuEntry("5", 2);
    glutAddMenuEntry("7", 3);
    glutAddSubMenu("Grosor",submenu_Grosor);

    int submenu_polares=glutCreateMenu(menu_polares);
    glutAddMenuEntry("Mariposa", 1);
    glutAddMenuEntry("Corazon", 2);
    glutAddMenuEntry("Rosa Polar", 3);
    glutAddSubMenu("Curvas Polares",submenu_polares);
    

    int submenu_color = glutCreateMenu(menu_color);
    glutAddMenuEntry("Rojo", 1);
    glutAddMenuEntry("Verde", 2);
    glutAddMenuEntry("Azul", 3);
    glutAddSubMenu("Color",submenu_color);

    
    int menu = glutCreateMenu(menu_principal);
    glutAddMenuEntry("Cartesianas", 1);
    glutAddMenuEntry("Polares", 2);
    glutAddMenuEntry("Ninguna", 3);
    
    glutCreateMenu(menu_principal);
    glutAddSubMenu("Sistema Referencial", menu);
    
    glutAddMenuEntry("Esc", 5);


    glutAttachMenu(GLUT_RIGHT_BUTTON);

    iniciar();
    glutReshapeFunc(myReshape);
    glutDisplayFunc(display);
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
    return 0;
}

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
void bordecirculo(int h, int k, int radio)
{
    GLfloat ang, x, y;
    glBegin(GL_LINE_LOOP);
    for (ang = 0.0f; ang < 2 * M_PI; ang += 2 * M_PI / 10)
    {
        x = h + radio * cos(ang);
        y = k + radio * sin(ang);
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
    glPopMatrix();
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

void menu_patron(int opcion){
    switch (opcion)
    {
    case 1:
        
        break;
    case 2:
        
        break;
}

void menu_grosor(int opcion){
    switch (opcion)
    {
    case 1:
        glPointSize(3.0);
        break;
    case 2:
        glPointSize(5.0);
        break;
    case 3:
        glPointSize(7.0);
        break;
    }
}

void menu_polares(int opcion)
{
    switch (opcion)
    {
    case 1:
        
        break;
    case 2:
        
        break;
    case 3:
        
        break;
    }
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
        ejes2D();
        break;
    case 2:
        modelo = 2;
        Caracol();
        break;
    case 3:
        modelo = 3;
        iniciar();
        break;
    case 5:
        exit(-1);
    }
    glutPostRedisplay();
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

void salir(){
    return ;
}