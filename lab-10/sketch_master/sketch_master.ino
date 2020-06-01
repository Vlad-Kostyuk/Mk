bool address = false;
byte address_two;
bool algoOne = false;
bool algoTwo = false;
byte Command;
bool comeData = false;
byte address_one = 0x37;
byte address_two = 0x5A;
byte command_one = 0xA1;
byte command_two = 0xB1;
bool commands = false;
byte command;

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


void RS485() {
  byte port = PORTD;
  PORTD |= 1 << PD1;
  delay(1);
}

void loop() {
  if (Serial.available()) {
    int inByte = Serial.read();
    PORTA = inByte;
    if (inByte == 0xC1) {
      algoOne = true;
    } else if (inByte == 0xD1) {
      algoTwo = true;
    }
  }

  if (algoOne) {
    address = true;
    address_two = address_one;
    Command = command_one;
    algoOne = false;
  } else if (algoTwo) {
    address = true;
    address_two = address_two;
    Command = command_two;
    algoTwo = false;
  }

  if (address) {
    RS485();
    UCSR1B |= 1 << TXB81;
    Serial1.write(address_two);
    address = false;
    commands = true;
  } else if (commands) {
    address = false;
    commands = false;
    RS485();
    UCSR1B &= ~(1 << TXB81);
    Serial1.write(Command);
  }


  if (Serial1.available()) {
    byte inByte1 = Serial1.read();
    PORTB = inByte1;
    Serial.write(inByte1);
  }
}

ISR(USART1_TX_vect)
{
  PORTD &= ~(1 << PD1);
}
