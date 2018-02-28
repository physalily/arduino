int i;
int dats[3][16] = {
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
}

int main()
{
  pinMode(4,OUTPUT);//SIN_1 common
  pinMode(5,OUTPUT);//SIN_2 columnA
  pinMode(6,OUTPUT);//SIN_3 columnB

  pinMode(7,OUTPUT);//LATCH
  pinMode(8,OUTPUT);//ENABLE
  pinMode(9,OUTPUT);//CLOCK

  while(TRUE)
  {
    for ( i = 0; i < 16; i++) {
      //data set
      digitalWrite(4,dats[0][i]);       //common
      digitalWrite(5,dats[1][i]);       //columnA
      digitalWrite(6,dats[2][i]);       //columnB
      digitalWrite(9,HIGH);//clock up
      digitalWrite(9,LOW);
    }
    digitalWrite(7,HIGH);//latch
    digitalWrite(7,LOW);
    delay(1000);
  }
}
