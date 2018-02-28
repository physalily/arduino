/***********************
inverted pendulum program
_______________________
Maintain accel at zero.
use arduino, MsTimer2 library.
--config--
slave two motor. use accel sensor.
***********************/
#include <MsTimer2>

//pid parameter
const long Kp = 45;
const long Ki = 30;
const long Kd = 40;
volatile long p_diff = 0;
volatile long i_diff =0;
volatile long d_diff = 0;
volatile long prev_val = 0;
volatile long error = 0;

void update();
void pid_operate(long error);

int main()
{
  //setup
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);

  MsTimer2::set(5, update);
  MsTimer2::start();

  //main loop
  while (TRUE) {
    if (power > 0) {
      analogWrite(6, power);
      digitalWrite(4,HIGH);
      digitalWrite(5,LOW);
      analogWrite(9, power);
      digitalWrite(7,HIGH);
      digitalWrite(8,LOW);
    }else{
      analogWrite(6, -power);
      digitalWrite(4,HIGH);
      digitalWrite(5,LOW);
      analogWrite(9, -power);
      digitalWrite(7,HIGH);
      digitalWrite(8,LOW);
    }
  }
}

void update()
{
  //limit power 255 ~ -255
  power = max(min(pid_operate(0 - analogRead(A5)),255),-255)
}

void pid_operate(long error)
{
  p_diff = error;
  i_diff += error;
  d_diff = error - prev_val;
  prev_val = error;
  return (Kp * p_diff) + (Ki * i_diff) + (Kd * d_diff);
}
