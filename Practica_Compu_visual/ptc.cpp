#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

void menu_principal(int);
void menu_figuras(int);
void menu_color(int);
GLdouble angulo=0;
GLint modelo=0;
GLint model=0;
GLint color=0;
void iniciar()
{
    glClearColor (1, 1, 1, 0.0);
    glColor3f (1.0, 0.0, 0.0);
    glLineWidth(2.0);
    glShadeModel(GL_FLAT);
}
//Declaramos la funcion de dibujar
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glColor3f(0.1f, 0.0f, 0.0f);
    menu_principal(modelo);
    menu_color(color);
    menu_figuras(model);
    glFlush();
    glutSwapBuffers();
}
//FUncion de redibujado
void myReshape(int w, int h)
{
    glViewport(0,0,(GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-20.0,20.0,-20.0,20,-20.0,20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
//---------------------------------------------------------
//Declaramos el grafico de la Rosa Polar
void RosaPolar(void)
{
    float ang, radio , x, y;
    glBegin(GL_LINE_LOOP);
    for (ang = 0.0; ang < 2 * M_PI; ang += 2*M_PI/50)
    {
    radio= 4*cos((3*ang)/5); //Ingresamos la formula de la Rosa polar.
    x = radio * cos(ang);
    y = radio * sin(ang);
    glVertex2f(x,y);
    }
    glEnd();
}
//---------------------------------------------------------
//Declaramos el grafico de la Mariposa
void Mariposa(void)
{
    float ang, radio , x, y;
    glBegin(GL_LINE_LOOP);
    for (ang = 0.0; ang < 2 * M_PI; ang += 2*M_PI/50)
    {
    radio = (pow(2.71828,cos(ang)))-(2*cos(4*ang))+(pow(sin((2*ang-M_PI)/24), 2)); //Ingresamos la formula "Mariposa"
    x = radio * cos(ang);
    y = radio * sin(ang);
    glVertex2f(x,y);
    }
    glEnd();
}
//---------------------------------------------------------
//Declaramos el grafico del Corazon
void Corazon(void)
{
    float ang, radio , x, y;
    glBegin(GL_LINE_LOOP);
    for (ang = 0.0; ang < 2 * M_PI; ang += 2*M_PI/50)
    {
    radio = sin(ang)*(sqrt(abs(cos(ang)))/(sin(ang) + 1.4)) - 2*sin(ang) + 2; //Ingresamos la formula "Corazon"
    x = radio * cos(ang);
    y = radio * sin(ang);
    glVertex2f(x,y);
    }
    glEnd();
}
//Sistema Cartesiano
void cartesiano(){
    glBegin(GL_LINES);
        glVertex2f(-50,0);
        glVertex2f(50,0);
        glVertex2f(0,50);
        glVertex2f(0,-50);
    glEnd();
}
//SIstema de coordenadas polares
void rayos(void){
    GLfloat ang, x, y;
    glBegin(GL_LINES);
        for (ang = 0.0f; ang < 2 * M_PI; ang += 2*M_PI/20)
            {
            x = 9 * cos(ang);
            y = 9 * sin(ang);
            glVertex2f(0,0);
            glVertex2f(x,y);
            }
    glEnd();
}

void circunferencia(int h,int k,int radio){
    GLfloat ang, x, y;
    glBegin(GL_LINE_LOOP);
        for (ang = 0.0f; ang < 2 * M_PI; ang += 2*M_PI/20)
            {
            x = h+radio * cos(ang);
            y = k+radio * sin(ang);
            glVertex2f(x,y);
            }
    glEnd();
}
void polar(){
    rayos();
    for(int radio=1;radio <10;radio+=1)
    {
        circunferencia(0,0,radio);
    }
}
//Menu principal
void menu_principal(int opcion)
{
switch(opcion){
    case 1: modelo=1; cartesiano();break;
    case 2: modelo=2; polar();break;
    case 3: modelo=3; display();break;
    case 4: exit(-1);
}
glutPostRedisplay();
}


void menu_figuras(int opcion){
    switch(opcion){
    case 1: model=1;RosaPolar(); break;
    case 2: model=2;Mariposa(); break;
    case 3: model=3;Corazon(); break;
}
}

//Menu de los colores
void menu_color(int opcion)
{
switch(opcion){
    case 1: color=1;glColor3f (1.0, 0.0, 0.0); break;
    case 2: color=2;glColor3f (0.0, 1.0, 0.0); break;
    case 3: color=3;glColor3f (0.0, 0.0, 1.0); break;
}
}

//Menu de los grosores.
void menu_grosor(int opcion){
switch(opcion){
    case 1: glLineWidth(1);break;
    case 2: glLineWidth(3);break;
    case 3: glLineWidth(5);break;
    case 4: glLineWidth(7);break;
}
}

//Declaramos los patrones
void Patron1(void)
{
    glLineStipple(2,0xAAAA);
    glEnable(GL_LINE_STIPPLE);
    }

void Patron2(void)
{
    glLineStipple(2,0x0C0F);
    glEnable(GL_LINE_STIPPLE);
    }

void menu_Patrones(int opcion)
{
switch(opcion){
    case 1: Patron1(); break;
    case 2: Patron2(); break;
}
}
//---------------------------------------------------------
int main(int argc, char **argv)
{
    //Procedimientos iniciales de todo proyecto con GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500,500);
    glutCreateWindow("Modelos de curvas polares");
    //Menu de coordenadas
    int submenu_figuras=glutCreateMenu(menu_figuras);
    glutAddMenuEntry("Rosa Polar",1);
    glutAddMenuEntry("Mariposa",2);
    glutAddMenuEntry("Corazon",3);

    //Menu de colores
    int submenu_color=glutCreateMenu(menu_color);
    glutAddMenuEntry("Rojo",1);
    glutAddMenuEntry("Verde",2);
    glutAddMenuEntry("Azul",3);
    
    //Menu de grosores.
    int submenu_grosor=glutCreateMenu(menu_grosor);
    glutAddMenuEntry("Delgado",1);
    glutAddMenuEntry("Normal",2);
    glutAddMenuEntry("Grueso",3);
    
    //Menu de patrones.
    int submenu_Patron=glutCreateMenu(menu_Patrones);
    glutAddMenuEntry("patron1",1);
    glutAddMenuEntry("patron2",2);

    //LLamamos al procedimiento del menu principal del programa.
    int menu=glutCreateMenu(menu_principal);
    glutAddSubMenu("Figuras", submenu_figuras);
    glutAddSubMenu("Colores",submenu_color);
    glutAddSubMenu("Grosor de lineas",submenu_grosor);
    glutAddSubMenu("Patrones ", submenu_Patron);
    glutAddMenuEntry("Cartesianas",1);
    glutAddMenuEntry("Polares",2);

    glutAddMenuEntry("Esc",4);

    glutAttachMenu(GLUT_RIGHT_BUTTON);

    iniciar();
    glutReshapeFunc(myReshape);
    glutDisplayFunc(display);
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
    return 0;
    }