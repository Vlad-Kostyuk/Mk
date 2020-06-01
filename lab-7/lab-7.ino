/*
    A
   ---
F |   | B
  | G |
   ---
E |   | C
  |   |
   ---
    D
*/


int pinA = 30;
int pinB = 31;
int pinC = 32;
int pinD = 33;
int pinE = 34;
int pinF = 35;
int pinG = 36;
int pinDP = 37;
int D1 = 21;
int D2 = 20;
int D3 = 19;
int D4 = 18;
int D5 = 17;
int D6 = 16;

volatile unsigned long int mile;

int seconds = 0;//xx:xx:00
int minute = 0;//xx:00:xx
int hour = 0;//00:xx:xx
int secondsTwo = 0;//xx:xx:10
int minuteTwo = 0;//xx:10:xx
int hourTwo = 0;//10:xx:xx

int historySeconds = 0;//xx:xx:00
int historyMinute = 0;//xx:00:xx
int historyHour = 0;//00:xx:xx
int historySecondsTwo = 0;//xx:xx:10
int historyMinuteTwo = 0;//xx:10:xx
int historyHourTwo = 0;//10:xx:xx

unsigned long int tmpTime;

int timer[10][7] =
{
  //A   B    C    D     E    F    G
  {LOW, LOW, LOW, LOW, LOW, LOW, HIGH},//0
  {HIGH, LOW, LOW, HIGH, HIGH, HIGH, HIGH},//1
  {LOW, LOW, HIGH, LOW, LOW, HIGH, LOW},//2
  {LOW, LOW, LOW, LOW, HIGH, HIGH, LOW},//3
  {HIGH, LOW, LOW, HIGH, HIGH, LOW, LOW},//4
  {LOW, HIGH, LOW, LOW, HIGH, LOW, LOW},//5
  {LOW, HIGH, LOW, LOW, LOW, LOW, LOW},//6
  {LOW, LOW, LOW, HIGH, HIGH, HIGH, HIGH},//7
  {LOW, LOW, LOW, LOW, LOW, LOW, LOW},//8
  {LOW, LOW, LOW, LOW, HIGH, LOW, LOW},//9
};

int timer2[4][7] =
{
  //A   B    C    D     E    F    G
  {HIGH, LOW, LOW, HIGH, LOW, LOW, LOW},//H
  {LOW, LOW, HIGH, LOW, LOW, LOW, LOW},//E
  {HIGH, LOW, HIGH, LOW, LOW, LOW, HIGH},//L
  {HIGH, HIGH, HIGH, LOW, HIGH, HIGH, HIGH},//_
};



int pins[8] = {30, 31, 32, 33, 34, 35, 36, 37};
int pinsTimer[6] = {21, 20, 19, 18, 17, 16};
int number = 0;


int checkTimer = 0;
int c = 0;
int timeArray[10][6];
int a = 0;
int checkButton = false;
int checkHistory = 0;



void setup() {
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT);
  pinMode(pinE, OUTPUT);
  pinMode(pinF, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);

  pinMode(38, OUTPUT);

  pinMode(50, INPUT_PULLUP);
  pinMode(51, INPUT_PULLUP);
  pinMode(52, INPUT_PULLUP);
  pinMode(53, INPUT_PULLUP);


  Serial.begin(9600);
  cli(); //
  TCCR0A = 0;
  TCCR0B = 0;
  TCNT0  = 0;
  OCR0A = 170;
  TCCR0B |= (1 << WGM01);
  TCCR0B |= (0 << CS02) | (1 << CS01) | (1 << CS00);
  TIMSK0 |= (1 << OCIE0A);
  sei();
}



void loop() {
int count = 0;
  if (true) {
    for (; count <= 6; count++) {
      if (count == 1) {
        digitalWrite(D6, LOW);
        digitalWrite(D1, HIGH);
        number = hourTwo;
        int tmp = 0;
        for (int b = 0; b <= 8; b++) {
          if ( tmp <= 7) {
            digitalWrite(pins[b], timer[number][tmp]);
            tmp++;
          }
        }
        delay(1);
      }

      if (count == 2) {
        digitalWrite(D1, LOW);
        digitalWrite(D2, HIGH);
        number = hour;
        int tmp = 0;
        for (int b = 0; b <= 8; b++) {
          if ( tmp <= 7) {
            digitalWrite(pins[b], timer[number][tmp]);
            tmp++;
          }
        }
        delay(1);
      }

      if (count == 3) {
        digitalWrite(D2, LOW);
        digitalWrite(D3, HIGH);
        number = minuteTwo;
        int tmp = 0;
        for (int b = 0; b <= 8; b++) {
          if ( tmp <= 7) {
            digitalWrite(pins[b], timer[number][tmp]);
            tmp++;
          }
        }
        delay(1);
      }

      if (count == 4) {
        digitalWrite(D3, LOW);
        digitalWrite(D4, HIGH);
        number = minute;
        int tmp = 0;
        for (int b = 0; b <= 8; b++) {
          if ( tmp <= 7) {
            digitalWrite(pins[b], timer[number][tmp]);
            tmp++;
          }
        }
        delay(1);
      }

      if (count == 5) {
        digitalWrite(D4, LOW);
        digitalWrite(D5, HIGH);
        number = secondsTwo;
        int tmp = 0;
        for (int b = 0; b <= 8; b++) {
          if ( tmp <= 7) {
            digitalWrite(pins[b], timer[number][tmp]);
            tmp++;
          }
        }
        delay(1);
      }

      if (count == 6) {
        digitalWrite(D5, LOW);
        digitalWrite(D6, HIGH);
        number = seconds;
        int tmp = 0;
        for (int b = 0; b <= 8; b++) {
          if ( tmp <= 7) {
            digitalWrite(pins[b], timer[number][tmp]);
            tmp++;
          }
        }
        delay(1);
      }
    }
  }
  //--------------------- start/stop
  if (!digitalRead(50) == HIGH) {
    digitalWrite(38, HIGH);
    delay(10);
    digitalWrite(38, LOW);

    if (checkButton == true && checkHistory != 1) {
      seconds = 0;
      minute = 0;
      hour = 0;
      secondsTwo = 0;
      minuteTwo = 0;
      hourTwo = 0;
      checkButton = false;
    }

    if (!checkButton) {
      if (checkTimer == 0) {
        checkTimer = 1;
      } else {
        checkTimer = 0;
        checkButton = true;
      }
    }

    if (checkHistory == 1) {
      seconds = historySeconds;
      minute = historyMinute;
      hour = historyHour;
      secondsTwo = historySecondsTwo;
      minuteTwo = historyMinuteTwo;
      hourTwo = historyHourTwo;

      historySeconds = 0;
      historyMinute = 0;
      historyHour = 0;
      historySecondsTwo = 0;
      historyMinuteTwo = 0;
      historyHourTwo = 0;

      checkHistory = 0;
      a = 0;
    }

    delay(200);
  }
  //---------------------- add
  if (!digitalRead(51) == HIGH && checkHistory != 1) {
    digitalWrite(38, HIGH);
    delay(10);
    digitalWrite(38, LOW);
    if (c <= 10) {
      for (int tmp = 0; tmp <= 6; tmp++) {

        if (tmp == 1) {
          timeArray[c][tmp] = seconds;
        }
        if (tmp == 2) {
          timeArray[c][tmp] = secondsTwo;
        }

        if (tmp == 3) {
          timeArray[c][tmp] = minute;
        }

        if (tmp == 4) {
          timeArray[c][tmp] = minuteTwo;
        }
        if (tmp == 5) {
          timeArray[c][tmp] = hour;
        }

        if (tmp == 6) {
          timeArray[c][tmp] = hourTwo;
        }

          timeArray[0][1] = {1};
          timeArray[0][2] = {2};
          timeArray[0][3] = {3};
          timeArray[0][4] = {4};
          timeArray[0][5] = {5};
          timeArray[0][6] = {6};

          timeArray[1][1] = {0};
          timeArray[1][2] = {0};
          timeArray[1][3] = {1};
          timeArray[1][4] = {1};
          timeArray[1][5] = {0};
          timeArray[1][6] = {0};

                 timeArray[2][1] = {0};
          timeArray[2][2] = {1};
          timeArray[2][3] = {1};
          timeArray[2][4] = {1};
          timeArray[2][5] = {0};
          timeArray[2][6] = {1};

                         timeArray[3][1] = {1};
          timeArray[3][2] = {1};
          timeArray[3][3] = {1};
          timeArray[3][4] = {1};
          timeArray[3][5] = {1};
          timeArray[3][6] = {1};
        
      }
      c++;
    } else {
      digitalWrite(38, HIGH);
      delay(1000);
      digitalWrite(38, LOW);
    }
    delay(200);
  }
  //----------------------  clear
  if (!digitalRead(52) == HIGH && checkHistory != 1) {
    digitalWrite(38, HIGH);
    delay(1000);
    digitalWrite(38, LOW);
    c = 0;
    for (; c <= 10; c++) {
      for (int tmp = 0; tmp <= 6; tmp++) {
        timeArray[c][tmp] = 0;
      }
    }
    delay(200);
    c = 0;
    a = 0;
  }
  //---------------------- show
  if (!digitalRead(53) == HIGH) {

    if (checkHistory == 0) {
      checkHistory = 1;

      historySeconds = seconds;
      historyMinute = minute;
      historyHour = hour;
      historySecondsTwo = secondsTwo;
      historyMinuteTwo = minuteTwo;
      historyHourTwo = hourTwo;
    }

    digitalWrite(38, HIGH);
    delay(10);
    digitalWrite(38, LOW);
    if (a <= 10) {
      for (int tmp = 0; tmp <= 6; tmp++) {

        if (tmp == 1) {
          seconds = timeArray[a][tmp];
        }
        if (tmp == 2) {
          secondsTwo = timeArray[a][tmp];
        }

        if (tmp == 3) {
          minute =  timeArray[a][tmp];
        }

        if (tmp == 4) {
          minuteTwo = timeArray[a][tmp];
        }
        if (tmp == 5) {
          hour = timeArray[a][tmp];
        }

        if (tmp == 6) {
          hourTwo = timeArray[a][tmp];
        }

      }
      a++;
    } else {
      digitalWrite(38, HIGH);
      delay(1000);
      digitalWrite(38, LOW);
      a = 0;
    }
    delay(200);
  }
  //----------------------
  */
}
}




ISR(TIMER0_COMPA_vect)
{
  if (checkTimer == 1)
  {
    mile++;
    if (mile - tmpTime >= 1000)
    {
      cli();
      tmpTime = mile;
      sei();
      seconds++;
      if (seconds > 9) {
        secondsTwo++;
        seconds = 0;
      }
      if (secondsTwo == 6 && seconds == 0)
      {
        secondsTwo = 0;
        seconds = 0;
        minute++;
        digitalWrite(38, HIGH);
        delay(100);
        digitalWrite(38, LOW);
        if (minute > 9) {
          minuteTwo++;
          minute = 0;
        }
        if (minuteTwo == 6 && minute == 0)
        {
          minute = 0;
          minuteTwo = 0;
          hour++;
          if (hour > 9) {
            hourTwo++;
            hour = 0;
          }
          if (hourTwo == 2 && hour == 4)
          {
            hour = 0;
            hourTwo = 0;
          }
        }
      }
    }
  }
}
