#include <MSTimer2>

double i;
double signal_s;

int main()
{
  pinMode(13,OUTPUT);
  while(1)
  {
    for ( i = 0; i < 3.14159; i += 0.001) {
      if (1 > signal_s) {
        signal_s += 0.01;
      }else{
        signal_s -= 0.01;
      }
      if (sin(i) >= signal_s) {
        digitalWrite(13,HIGH);
      }else{
        digitalWrite(13,LOW);
      }
      delay(1);
    }
  }
}
