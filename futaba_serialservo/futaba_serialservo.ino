int REDE = 2;

void torque(unsigned char ID, unsigned char data){
  unsigned char TxData[9];
  unsigned char CheckSum = 0;
  TxData[0] = 0xFA;
  TxData[1] = 0xAF;
  TxData[2] = ID;
  TxData[3] = 0x00;
  TxData[4] = 0x24;
  TxData[5] = 0x01;
  TxData[6] = 0x01;
  TxData[7] = data;

  for(int i = 2; i <= 7; i++){
    CheckSum = CheckSum ^ TxData[i];
  }
  TxData[8] = CheckSum;

  digitalWrite(REDE, HIGH);
  for(int i = 0; i <= 8; i++){
    Serial.write(TxData[i]);
  }
  delayMicroseconds(250);
  digitalWrite(REDE, LOW);
}

void Move_SV(unsigned char ID, int Angle, int Speed){
  unsigned char TxData[12];
  unsigned char CheckSum = 0;
  TxData[0] = 0xFA;
  TxData[1] = 0xAF;
  TxData[2] = ID;
  TxData[3] = 0x00;
  TxData[4] = 0x24;
  TxData[5] = 0x01;
  TxData[6] = 0x01;

  TxData[7] = (unsigned char)0x00FF & Angle;
  TxData[8] = (unsigned char)0x00FF & (Angle >> 8);

  TxData[9] = (unsigned char)0x00FF & Speed;
  TxData[10] = (unsigned char)0x00FF & (Speed >> 8);

  for(int i = 2; i <= 10; i++){
    CheckSum = CheckSum ^ TxData[i];
  }
  TxData[11]  = CheckSum;

  digitalWrite(REDE, HIGH);
  for(int i = 0; i <= 11; i++){
    Serial.write(TxData[i]);
  }
  delayMicroseconds(250);
  digitalWrite(REDE, LOW);
}

void setup(){
  pinMode(REDE, OUTPUT);
  Serial.begin(115200);
  delay(500);
}

void loop(){
  unsigned char i = 0;
  setup();
  torque(0xFF, 0x01);
  delay(1000);

  while (1) {
    for( i = 0; i <= 20; i++){
      Move_SV(i, 300, 100);
      delay(500);
    }
    delay(500);
    Move_SV(0xFF, -300, 100);
    delay(2000);
  }
}
