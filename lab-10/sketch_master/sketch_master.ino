bool isAddress = false;
bool isCommand = false;
byte command;
byte Address_A = 0x37;
byte Address_B = 0x5A;
byte Command_A = 0xA1;
byte Command_B = 0xB1;
bool isData1Come = false;
byte Address;
bool startAlgo1 = false;
bool startAlgo2 = false;
byte Command;


void setWriteModeRS485() {
  byte port = PORTD;
  PORTD |= 1 << PD1;
  delay(1);
}

ISR(USART1_TX_vect)
{
  PORTD &= ~(1 << PD1);
}

void setup() {
  delay(100);
  DDRB = 0xFF;
  DDRA = 0xFF;
  DDRD |= 1 << PD1;
  PORTA = 0x00;
  PORTB = 0x00;
  PORTD &= ~(1 << PD1);

  Serial.begin(9600);
  Serial1.begin(9600, SERIAL_8N1);
  UCSR1B |= (1 << UCSZ12) | (1 << TXCIE1);
}

void loop() {

  if (Serial.available()) {
    int inByte = Serial.read();
    PORTA = inByte;
    if (inByte == 0xC1) {
      startAlgo1 = true;
    } else if (inByte == 0xD1) {
      startAlgo2 = true;
    }
  }

  if (startAlgo1) {
    isAddress = true;
    Address = Address_A;
    Command = Command_A;
    startAlgo1 = false;
  } else if (startAlgo2) {
    isAddress = true;
    Address = Address_B;
    Command = Command_B;
    startAlgo2 = false;
  }

  if (isAddress) {
    setWriteModeRS485();
    UCSR1B |= 1 << TXB81;
    Serial1.write(Address);
    isAddress = false;
    isCommand = true;
  } else if (isCommand) {
    isAddress = false;
    isCommand = false;
    setWriteModeRS485();
    UCSR1B &= ~(1 << TXB81);
    Serial1.write(Command);
  }


  if (Serial1.available()) {
    byte inByte1 = Serial1.read();
    PORTB = inByte1;
    Serial.write(inByte1);
  }
}
