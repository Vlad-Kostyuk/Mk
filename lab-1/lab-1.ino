boolean statusButton;
boolean butt;
int leftLED = 37;
int rigthLED = 30;
void setup() {
 pinMode(28, INPUT_PULLUP);
 
 pinMode(37, OUTPUT);
 pinMode(36, OUTPUT);
 pinMode(35, OUTPUT);
 pinMode(34, OUTPUT);
 pinMode(33, OUTPUT);
 pinMode(32, OUTPUT);
 pinMode(31, OUTPUT);
 pinMode(30, OUTPUT);
 
 digitalWrite(37, 0);
 digitalWrite(36, 0);
 digitalWrite(35, 0);
 digitalWrite(34, 0);
 digitalWrite(33, 0);
 digitalWrite(32, 0);
 digitalWrite(31, 0);
 digitalWrite(30, 0);
 
}

void loop() {
      butt = !digitalRead(28);
      statusButton = butt;
      if( statusButton == 1 && rigthLED != 32) {
        // -------
       digitalWrite(37, 1);
       delay(1000);
       digitalWrite(37, 0);
       // -------
       digitalWrite(30, 1);
       delay(1000);
       digitalWrite(30, 0);
        // -------
       digitalWrite(36, 1);
       delay(1000);
       digitalWrite(36, 0);
         // -------
       digitalWrite(31, 1);
       delay(1000);
       digitalWrite(31, 0);
          // -------
       digitalWrite(35, 1);
       delay(1000);
       digitalWrite(35, 0);
        // -------
       digitalWrite(32, 1);
       delay(1000);
       digitalWrite(32, 0);
          // -------
       digitalWrite(34, 1);
       delay(1000);
       digitalWrite(34, 0);
         // -------
       digitalWrite(33, 1);
       delay(1000);
       digitalWrite(33, 0);
      }
}
