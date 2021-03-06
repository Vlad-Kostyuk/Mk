#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 13

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

byte address = 0x37;
bool command = false;
bool addressOne = true;


void setup() {
  delay(100);

  DDRD = 0b00000111;
  PORTD = 0b11111000;
  DDRC = 0xFF;

  Serial.begin(9600, SERIAL_8N1);
  UCSR0B |= (1 << UCSZ02) | (1 << TXCIE0);
  UCSR0A |= (1 << MPCM0);
  sensors.begin();

  delay(1);
}

byte crc(byte b, unsigned char poly, unsigned char crcStart,
                  unsigned char finalXOR) {
  unsigned char crc = crcStart;
  unsigned char i;

  b = reflect8(b);
  crc ^= b;

  for (i = 0; i < 8; i ++) {
    crc = crc & 0x80 ? (crc << 1) ^ poly : crc << 1;
  }

  crc = reflect8(crc);
  crc ^= finalXOR;
  return crc;
}

unsigned char reflect8(unsigned char x) {
  x = (x & 0x55) << 1 | (x & 0xAA) >> 1;
  x = (x & 0x33) << 2 | (x & 0xCC) >> 2;
  x = (x & 0x0F) << 4 | (x & 0xF0) >> 4;
  return x;
}


void loop() {
  if (Serial.available()) {
    int inByte = Serial.read();
    if (addressOne) {
      if (address == inByte) {
        addressOne = false;
        command = true;
        UCSR0A &= ~(1 << MPCM0);
      }
    } else if (command) {
      if (inByte == 0xA1) {
        UCSR0A |= (1 << MPCM0);
        sensors.requestTemperatures();
        data(sensors.getTempCByIndex(0));
      }
    }
  }
}

void data(byte value) {
  RS485();
  Serial.write(value);
  RS485();
  Serial.write(crc(value, 0x1D, 0xFF, 0x00));
  RS485();
  Serial.write(0b10100101);
  addressOne = true;
  command = false;
}

void RS485() {
  PORTD |= 1 << PD2;
  delay(1);
}


ISR(USART_TX_vect)
{
  PORTB = 0xF0;
  PORTD &= ~(1 << PD2);
}
