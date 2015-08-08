#include <GL/glut.h> 
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

float a, b;
float c = 0.0;
float d = 0.0;

void Timer(int iUnused)
{
    glutPostRedisplay();
    glutTimerFunc(30, Timer, 0);
}

void initGL() {
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void displayBoard(){
  glClear (GL_COLOR_BUFFER_BIT);
}

void lel(){
	glColor3f (1.0, 1.0, 0.0);
	glPointSize(5.0);
  	glBegin(GL_POINTS);
    	glVertex2f(c, d);
  	glEnd();
  	c = fmod((c+5), 800);
  	d = fmod((d+5), 600);
}

void getField(){
  glColor3f (1.0, 0.0, 0.0);
  //float a = rand()%800;
  //float b = rand()%600;

  glPointSize(5.0);
  glBegin(GL_POINTS);
    glVertex2f(a, b);
  glEnd();
}

void showGame(){
  displayBoard();
  getField();
  lel();
  glFlush();
}

void keyboard(unsigned char key, int x, int y){
    switch (key){
    case 'd':
      a+=10;
      break;
 
    case 'a':
      a -= 10.0;
    break;

    case 'w':
      b += 10;
    break;

    case 's':
      b -= 10;
 
    default:
         break;
  }
   //glutPostRedisplay(); //request display() call ASAP
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

  a = rand()%800;
  b = rand()%600;

  glutInit(&argc, argv);
  glutCreateWindow("leSnake");
  glutInitWindowPosition(50, 50);
  glutReshapeWindow(800, 600);
  initGL();
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyboard);
  glutDisplayFunc(showGame);
  Timer(0); 
  glutMainLoop();
  
  return 0;
}

//g++ snake.cpp -lGL -lGLU -lglut