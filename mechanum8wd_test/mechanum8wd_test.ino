/************************
8wd mechanum test program
________________________
*************************/
#include "mechanum.h"
mechanum wheel_in(600,450,30);
mechanum wheel_out(300,450,30);

int main()
{
  double X, Y, A;
  //pwm
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(6,OUTPUT);
  //direction
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(7,OUTPUT);

  X = 50;
  Y = 0;
  A = 0;
  wheel_in.update(X, Y, A);
  whee_out.update(X, Y, A);
  while (1) {
    
  }
}
