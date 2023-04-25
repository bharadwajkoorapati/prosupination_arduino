#include <Servo.h> // include servo library to use its related functions
#define Servo_PWM 6 // A descriptive name for D6 pin of Arduino to provide PWM signal
Servo MG995_Servo;  // Define an instance of of Servo with the name of "MG995_Servo"
  
String command;
void setup() {
  Serial.begin(9600); // Initialize UART with 9600 Baud rate
  MG995_Servo.attach(Servo_PWM);  // Connect D6 of Arduino with PWM signal pin of servo motor

}

void loop() {

if(Serial.available()){
command = Serial.readStringUntil('\n');
String value = command;
if(value == "r"){
  Serial.println("right");// You can display on the serial the signal value
  MG995_Servo.write(0); //Turn clockwise at high speed
  MG995_Servo.attach(Servo_PWM);
  delay(3000);
  MG995_Servo.detach();  
}
else if(value == "l"){
Serial.println("left");//Turn left high speed
  MG995_Servo.write(180);
  MG995_Servo.attach(Servo_PWM);
  delay(3000);
  MG995_Servo.detach();
   }
else if(value == "s"){
  MG995_Servo.detach();
  Serial.println("stop");
}

}
}

      
