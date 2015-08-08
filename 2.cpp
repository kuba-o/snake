#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void initGL() {
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void display(void)
{
  glClear (GL_COLOR_BUFFER_BIT);

  glColor3f (1.0, 1.0, 1.0);

  glBegin(GL_POLYGON);
    glVertex2f(80.0, 120.0);
    glVertex2f(50.0, 30.0);
    glVertex2f(40.0, 100.0);
    glVertex2f(150.0, 190.0);
  glEnd();

  float c= rand()%800;
  float d = rand()%600;
  float a = 300.0;
  float b = 400.0;
  glPointSize(10);
  glBegin(GL_POINTS);
   glVertex2f(300.0, 300.0);
   glVertex2f(a, b);
   glVertex2f(c, d);
  glEnd();

  glFlush ();
}

void test2(){
    //glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (0.0, 1.0, 0.0);
    glPointSize(10);
  glBegin(GL_POINTS);
   glVertex2f(200.0, 200.0);
  glEnd();

  glFlush ();
}

void callfunc(){
    display();
    test2();
}

void reshape (int w, int h)
{
  glViewport (0, 0, (GLsizei) w, (GLsizei) h);
  glMatrixMode (GL_PROJECTION);
  glLoadIdentity ();
  gluOrtho2D (0.0, (GLdouble) w, 0.0, (GLdouble) h);
}

int main(int argc, char** argv) {
  srand( time( NULL ) );
  glutInit(&argc, argv);
  glutCreateWindow("leSnake");
  glutInitWindowPosition(50, 50);
  glutReshapeWindow(800, 600);
  initGL();
  glutDisplayFunc(callfunc);
  //glutDisplayFunc(display);
  //glutDisplayFunc(test2); 
  glutReshapeFunc(reshape);
  glutMainLoop();
  
  cout<<"END"<<endl;
  return 0;
}