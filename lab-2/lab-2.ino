boolean statusButton;
boolean buttOne;
boolean buttTwo;

void setup() {
 Serial.begin(9600);
 pinMode(28, INPUT_PULLUP);
 pinMode(26, INPUT_PULLUP);
  
 pinMode(37, OUTPUT);
 pinMode(36, OUTPUT);
 pinMode(35, OUTPUT);
 pinMode(34, OUTPUT);
 pinMode(33, OUTPUT);
 pinMode(32, OUTPUT);
 pinMode(31, OUTPUT);
 pinMode(30, OUTPUT);

}

void loop() {
  if (Serial.available() > 0) {
    char inByte = Serial.read();
      if(inByte == 1) {
       int leftLED = 37;
       int rigthLED = 30;
        while(rigthLED != 34) {
         digitalWrite(leftLED, 1);
         delay(700);
         digitalWrite(leftLED, 0);
         leftLED = leftLED - 1;
         // -------
         digitalWrite(rigthLED, 1);
         delay(700);
         digitalWrite(rigthLED, 0);
         rigthLED = rigthLED + 1;
        }
      }
 
      if(inByte == 2) {
       int led = 37;
        while(led != 29) {
          digitalWrite(led, 1);
          delay(700);
          digitalWrite(led, 0);
          led = led - 1;
        }
      } 
}

  
  if(!digitalRead(26)==1){
    Serial.write(1);
    delay(200);
  }

  if(!digitalRead(28)==1){
    Serial.write(2);
    delay(200);
  }
}
