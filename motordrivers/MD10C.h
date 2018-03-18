/************************
DIR   PWM   outA  outB
  *       0        0       0
  0      ~1       1       0
  1      ~1       0       1
  this driver cannot stop.
  pwm = 0 is brake.
************************/
class MD10Cdr{
private:
  int dirPin;
  int pwmPin;
public:
  MD10Cdr(int dirPin, int pwmPin){
    this -> dirPin = dirPin;
    this -> pwmPin = pwmPin;
    pinMode(dirPin,OUTPUT);
    pinMode(pwmPin,OUTPUT);
  }
  void drive(int dir, double power){
    digitalWrite(dirPin, dir);
    analogWrite(pwmPin,power);
  }
};
