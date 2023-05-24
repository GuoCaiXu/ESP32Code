#include <Arduino.h>
# include <HardwareSerial.h>

void read_usart(void);

void setup() {
  // put your setup code here, to run once:

  Serial.begin(115200);

  Serial.onReceive(read_usart, true);
}

void loop() {
  // put your main code here, to run repeatedly:

  //read_usart();
}

void read_usart(void){

  int i = Serial.available();

  if (i != 0){

    while(i --){

      char temp = Serial.read();
      Serial.printf("%c", temp);
    }
  }
}
