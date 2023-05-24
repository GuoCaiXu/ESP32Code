# include <Arduino.h>
# include "../lib/sg90/bsp_sg90.h"

void setup() {
  // put your setup code here, to run once:

  Serial.begin(115200);
  MyPWM_Init();
}

void loop() {
  // put your main code here, to run repeatedly:

  MyPWM_Drive();
}
