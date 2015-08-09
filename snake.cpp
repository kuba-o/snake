#include <GL/glut.h> 
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>

using namespace std;

class snakeField{

  float x;
  float y;
};

float a, b;
float c = 0.0;
float d = 0.0;
char actual;
vector<float> wonszx;
vector<float> wonszy;
vector<snakeField> wonsz;

void Timer(int iUnused)
{
    glutPostRedisplay();
    glutTimerFunc(30, Timer, 0);
    for (int i =0; i<wonszx.size(); i++){
      wonszx[i] = wonszx[i] + 5;
    }
}

void initGL() {
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void displayBoard(){
  glClear (GL_COLOR_BUFFER_BIT);
}

/*
void sortSnake(char direction){
  if (direction == 'w' && actual != 's')
    wonszy[0] += 5;
  else if (direction == 's' && actual != 'w')
    wonszy[0] -= 5;
  else if (direction == 'a' && actual != 'd')
    wonszx[0]
}*/

void countSnake(){

}
void lel(){
  glColor3f (1.0, 1.0, 0.0);
  glPointSize(10.0);
    glBegin(GL_POINTS);
      glVertex2f(c, d);
      glVertex2f(120, 20);
      glVertex2f(120, 9);
    glEnd();
    c = fmod((c+5), 800);
    d = fmod((d+5), 600);
}

void drawSnake(){
  glColor3f(1.0, 1.0, 0.0);
  glPointSize(5.0);
  glBegin(GL_POINTS);
    glVertex2f(wonszx[0], wonszy[0]);
    glColor3f(0.0, 1.0, 0.0);
    for (int i =1; i<wonszx.size(); i++){
      glVertex2f(wonszx[i], wonszy[i]);
    }
  glEnd();
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
  //lel();
  drawSnake();
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

  
  wonszx.push_back(65);
  wonszx.push_back(60);
  wonszx.push_back(55);
  wonszx.push_back(50);
  wonszy.push_back(10);
  wonszy.push_back(10);
  wonszy.push_back(10);
  wonszy.push_back(10);

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