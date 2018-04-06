class futaba_ {
private:
  int used_pinNo;
  unsigned char packet[15];
  unsigned char CheckSum = 0;
public:
  futaba_(int);
  void write_packet(unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char,unsigned char, unsigned char, unsigned char, unsigned char);
};

inline void futaba_::futaba_(int used_pinNo){
  this -> used_pinNo = used_pinNo;
  packet[] = {0};
}

inline void futaba_::write_packet(unsigned char Flag, unsigned char Address, unsigned char Length, unsigned char Count, unsigned char dat1, unsigned char dat2, unsigned char dat3, unsigned char dat4, unsigned char dat5, unsigned char dat6, unsigned char dat7, unsigned char dat8, unsigned char dat9){
  packet[0] = 0xFA;
  packet[1] = 0xAF;
  packet[2] = Flag;
  packet[3] = Address;
  packet[4] = Length;
  packet[5] = Count;
  packet[6] = dat1;
  packet[7] = dat2;
  packet[8] = dat3;
  packet[9] = dat4;
  packet[10] = dat5;
  packet[11] = dat6;
  packet[12] = dat7;
  packet[13] = dat8;
  packet[14] = dat9;
}

class futaba_S : futaba_ {
public:
  futaba_S(int output_pinNo, unsigned char ID);
  void write_packet(unsigned char Flag, unsigned char Address, unsigned char Length, unsigned char Count, unsigned char Data);
  void writeFR();
  void restart();
  unsigned char return_packet();
};


class futaba_L{
private:
  int output_pinNo;
  unsigned char packet[];
public:
  futaba_L(int output_pinNo, unsigned char ID);
};

class futaba_R{
private:
  int input_pinNo;
  unsigned char packet[];
public:
  futaba_R(int input_pinNo, unsigned char ID);
};

inline futaba_S::futaba_S(int output_pinNo, unsigned char ID){
    this -> output_pinNo = output_pinNo;
    packet[0] = 0xFA;
    packet[1] = 0xAF;
    packet[3] = ID;
}

inline void futaba_S::write_packet(unsigned char Flag, unsigned char Address, unsigned char Length, unsigned char Count, unsigned int Data){
  packet[4] = Flag;
  packet[5] = Address;
  packet[6] = Length;
  packet[7] = Count;
  packet[8] = Data & 0xF0;
  packet[9] = Data & 0x0F;
  for(int i = 2; i <= 10; i++){
    CheckSum = CheckSum ^ TxData[i];
  }
  packet[10]  = CheckSum;
}

inline void futaba_S::restart(){
  write_packet(0x20, 0xFF, 0x00, 0x00);
}

inline unsigned char futaba_S::return_packet(){
  return packet[0];
}
