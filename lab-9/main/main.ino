byte command;
bool commandOne = false;
bool address = true;


void setup() {
  delay(1000);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
  DDRD |= 1 << PD1;
  PORTD &= ~(1 << PD1);
  Serial.begin(9600);
  Serial.begin(9600, SERIAL_8N1);
  UCSR1B |= (1 << UCSZ12) | (1 << TXCIE1);
}

void loop() {
  if (Serial.available()) {
    byte inByte = Serial.read();
    if (address) {
      RS485();
      UCSR1B |= 1 << TXB81;
      Serial.write(inByte);
      address = false;
      commandOne = true;
    } else if (commandOne) {
      command = inByte;
      commandOne = false;
      RS485();
      UCSR1B &= ~(1 << TXB81);
      Serial1.write(inByte);
      if (command == 0xB1) address = true;
    } else {
      address = true;
      RS485();
      UCSR1B &= ~(1 << TXB81);
      Serial.write(inByte);
    }
  }

  if (Serial.available()) {
    String inString = Serial.readString();
    Serial.print(inString);
  }
}

void RS485() {
  byte port = PORTD;
  PORTD |= 1 << PD1;
  delay(1);
}

uint8_t crc16(uint8_t const *data, size_t size) {
  uint8_t crc = 0xFF;
  while (size--) {
    crc ^= (*data++) << 8;
    for (unsigned k = 0; k < 8; k++) {
      crc = crc & 1 ? (crc << 1) ^ 0x7 : crc << 1;
    }
  } return crc;
}

ISR(USART1_TX_vect)
{
  PORTD &= ~(1 << PD1);
}
