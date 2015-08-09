#include <GL/glut.h> 
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>

using namespace std;

char dir = 'd';
float a, b;
float c = 0.0;
float d = 0.0;
char actual;
vector<float> wonszx;
vector<float> wonszy;

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

void lel(char asd){
  dir = asd;
    if (dir == 'w')
      wonszy[0] = abs(fmod(wonszy[0]+5, 600));
    else if (dir == 's'){
      if (wonszy[0]<0)
        wonszy[0] = 600;
      wonszy[0] = fmod(wonszy[0]-5, 600);
    }
    else if (dir == 'a'){
      if (wonszx[0] < 0)
        wonszx[0] = 800;
      wonszx[0] = fmod(wonszx[0]-5, 800);
    }
    else if (dir == 'd')
      wonszx[0] =abs(fmod(wonszx[0]+5, 800));
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

  glPointSize(5.0);
  glBegin(GL_POINTS);
    glVertex2f(a, b);
  glEnd();
}

void showGame(){
  displayBoard();
  //getField();
  lel(dir);
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
    lel(key);
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
  /*
  wonszx.push_back(60);
  wonszx.push_back(55);
  wonszx.push_back(50);
  */
  wonszy.push_back(10);
  /*
  wonszy.push_back(10);
  wonszy.push_back(10);
  wonszy.push_back(10);
  */
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