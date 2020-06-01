#include <Keypad.h>
#include <LiquidCrystal.h>


volatile unsigned long int mile;
unsigned long int tmpTime;
int tmpHour;
int tmpMinute;
int tmpSeconds;
int checkTimer = 0;
int checkButtonA = 0;
int checkButtonB = 1;
int seconds = 0;
int minute;
int hour;
int checkArray = 0;
int timeArray[60][3];
int sizeArray = 0;
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1','2','3','A'}, 
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {A4, A5, A6, A7}; 
byte colPins[COLS] = {A3, A2, A1, A0};
Keypad customKeypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
LiquidCrystal lcd(46, 6, 45, 30, 31, 32, 33, 34, 35, 36, 37);


void setup() {
  lcd.begin(16, 2); 
  Serial.begin(9600);
  pinMode(53, OUTPUT);
  digitalWrite(53, 0);
  TCCR0A = 0; 
  TCCR0B = 0; 
  TCNT0  = 0; 
  OCR0A = 171;
  TCCR0B |= (1 << WGM01);
  TCCR0B |= (0 << CS02) | (1 << CS01) | (1 << CS00);
  TIMSK0 |= (1 << OCIE0A);
  sei(); 
}

void loop() {    
  lcd.setCursor(5, 0);              
  lcd.print(hour);
  lcd.print(":");
  lcd.print(minute);
  lcd.print(":");
  lcd.print(seconds);
  lcd.setCursor(1, 1);    
  lcd.print("M");  
  lcd.print(sizeArray);    
  char customKey = customKeypad.getKey();

  //----------------------------
  if (customKey == 'D'){
       if(checkTimer == 1) {
         checkTimer = 0;
       } else {
         checkTimer = 1;
       }
  } 
 //-----------------
 if (customKey == 'C'){
    checkTimer = 0;
    customKey = 0;
    seconds = 0;
    minute = 0;
    hour = 0;
    mile = 0;
    lcd.clear();
  }
  //-------------
  if (customKey == '#' && checkButtonA == 0){
    if (sizeArray < 60)  {
       timeArray[sizeArray ][0] = hour;
       timeArray[sizeArray ][1] = minute;
       timeArray[sizeArray ][2] = seconds; 
       sizeArray++;
   }
  }
 //--------------
 if (customKey == '*'){
  for(int i = 0; i  <= 60; i++) {
    for(int c = 0; c < 3; c++) {
      timeArray[i][c] = 0;
    }
  }
   sizeArray = 0;
 }
 //--------------------
 if(customKey == 'A'){
  if(checkButtonA == 0) {
    tmpHour = hour;
    tmpMinute = minute;
    tmpSeconds = seconds;
    checkButtonA = 1;
    lcd.clear();
    int i = 0;
    hour = timeArray[i][0];
    minute = timeArray[i][1];
    seconds = timeArray[i][2];
    lcd.setCursor(3, 0);              
    lcd.print("0)" + hour);
    lcd.print(":");
    lcd.print(minute);
    lcd.print(":");
    lcd.print(seconds);
    } else  {
       lcd.clear();
       hour = tmpHour;
       minute = tmpMinute;
       seconds = tmpSeconds;
       checkButtonA = 0;
       checkButtonB = 0;
    }
 }
 //--------------------
  if (customKey == 'B' && checkButtonA == 1) {
    if (checkButtonB < sizeArray)  {
      hour = timeArray[checkButtonB][0];
      minute = timeArray[checkButtonB][1];
      seconds = timeArray[checkButtonB][2];
      lcd.clear();
      lcd.setCursor(2, 0);             
      lcd.print(String(checkButtonB) + ") " + String(hour));
      lcd.print(":");
      lcd.print(minute);
      lcd.print(":");
      lcd.print(seconds);
      checkButtonB++;
   }
  }
 //--------------------  
  if(seconds == 3) {
     digitalWrite(53, 0);
     delay(200);
        digitalWrite(53, 1);
        delay(200);
        digitalWrite(53, 0);
  }
  
}

 //-------------------------------------------------
  ISR(TIMER0_COMPA_vect)
  {
  if(checkTimer == 1) 
  {
   mile++;
    if(mile - tmpTime >= 1000) 
    {
     cli();
     tmpTime = mile;
     sei();
     seconds++;
      if(seconds == 60)
      {
        lcd.clear();
        seconds = 0;
        minute++;
         if(minute > 59) 
         {
           minute = 0;
           hour++;
            if(hour > 24) 
            {
               hour = 0;
            }
         }
       }
     }
   }
  }
