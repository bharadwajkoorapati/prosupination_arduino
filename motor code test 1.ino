#include <Servo.h> // include servo library to use its related functions
#define Servo_PWM1 6 // A descriptive name for D6 pin of Arduino to provide PWM signal
Servo MG995_Servo1;  // Define an instance of of Servo with the name of "MG995_Servo1"

#define Servo_PWM2 7 // A descriptive name for Dr7 pin of Arduino to provide PWM signal
Servo MG995_Servo2;  // Define an instance of of Servo with the name of "MG995_Servo2"  

String command;
void setup() {
  Serial.begin(9600); // Initialize UART with 9600 Baud rate
  MG995_Servo1.attach(Servo_PWM1);  // Connect D6 of Arduino with PWM signal pin of servo motor
  MG995_Servo2.attach(Servo_PWM2);
}

void loop() {

if(Serial.available()){
command = Serial.readStringUntil('\n');
String value = command;
if(value == "d"){
  Serial.println("right");// You can display on the serial the signal value
  MG995_Servo1.write(0); //Turn clockwise at high speed
  MG995_Servo1.attach(Servo_PWM1);
  delay(4500);
  MG995_Servo1.detach();  
}
else if(value == "a"){
Serial.println("left");//Turn left high speed
  MG995_Servo1.write(180);
  MG995_Servo1.attach(Servo_PWM1);
  delay(4500);
  MG995_Servo1.detach();
   }
else if(value == "w"){
Serial.println("up");//Turn left high speed
  MG995_Servo2.write(180);
  MG995_Servo2.attach(Servo_PWM2);
  delay(3000);
  MG995_Servo2.detach();

}
else if(value == "s"){
Serial.println("down");//Turn left high speed
  MG995_Servo2.write(0);
  MG995_Servo2.attach(Servo_PWM2);
  delay(1500);
  MG995_Servo2.detach();

}

}
}

      

