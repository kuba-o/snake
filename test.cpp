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
float tempx1, tempx2, tempy1, tempy2;
char previousDirection = 'd';
char direction;
vector<float> wonszx;
vector<float> wonszy;

class SnakeField {
public:
  float x;
  float y;
};

vector<SnakeField> wonsz;

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

void drawSnake(){
  glColor3f(1.0, 1.0, 0.0);
  glPointSize(5.0);
  glBegin(GL_POINTS);
    glVertex2f(wonsz[0].x, wonsz[0].y);
    glColor3f(0.0, 1.0, 0.0);
    for (int i =1; i<wonsz.size(); i++){
      glVertex2f(wonsz[i].x, wonsz[i].y);
    }
  glEnd();
}

void moveSnake(char key){
  if (key == 'w' || key == 'a' || key == 's' || key == 'd'){
    direction = key;
  }

  if (direction == 'w' && previousDirection !='s'){
    wonsz[0].y = fmod(wonsz[0].y+5, 600);
    

  }
  else if (direction == 's' && previousDirection!='w'){

  }
  else if (direction == 'a' && previousDirection!='d'){

  }
  else if (direction == 'd' && previousDirection!='a'){

  }
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
  //turnSnake(dir);
  //getField();
  drawSnake();
  glFlush();
}

void keyboard(unsigned char key, int x, int y){
  //turnSnake(key);
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
  
  SnakeField temp;

  temp.x = 80;
  temp.y = 120;
  wonsz.push_back(temp);
  temp.x = 75;
  temp.y = 120;
  wonsz.push_back(temp);
  temp.x = 70;
  temp.y = 120;
  wonsz.push_back(temp);

  glutInit(&argc, argv);
  glutCreateWindow("leSnake");
  glutInitWindowPosition(50, 50);
  glutReshapeWindow(800, 600);
  initGL();
  getField();
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyboard);
  glutDisplayFunc(showGame);
  Timer(0); 
  glutMainLoop();
  
  return 0;
}

//g++ snake.cpp -lGL -lGLU -lglut