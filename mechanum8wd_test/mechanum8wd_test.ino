/************************
8wd mechanum test program
________________________
*************************/
#include "mechanum.h"
mechanum wheel_in(600,450,30);
mechanum wheel_out(300,450,30);
mechanum SINGLE(750,750,100);
void drive();

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

  while (1) {
    X = 50;
    Y = 0;
    A = 0;
    wheel_in.update(X, Y, A);
    whee_out.update(X, Y, A);
    drive();
    delay(3000);

    X = 0;
    Y = 0;
    A = 3.1415;
    wheel_in.update(X, Y, A);
    whee_out.update(X, Y, A);
    drive();
    delay(3000);

    X = 0;
    Y = 50;
    A = 0;
    whee_in.update(X, Y, A);
    whee_out.update(X, Y, A);
    drive();
    delay(3000);

    X = -50;
    Y = -50;
    A = 0;
    wheel_in.update(X, Y, A);
    wheel_out.update(X, Y, A);
    dirve();
    delay(3000);
  }
}

void drive()
{

}

void MD(double pinA, double pinD, double POWER)
{

}
