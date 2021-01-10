#include <Ultrasonic.h>
#include <Servo.h>

Servo scan_servo;
Ultrasonic dist(6, 7); //ultrasonic sensor on pins 6 and 7
int start_of_range = 120;

void setup() {
  scan_servo.attach(5); // servo on pin 5
  scan_servo.write(start_of_range);
  Serial.begin(2400);
  pinMode (4, INPUT_PULLUP);
}


// to do: file making, file writing, ultrasonic scanning (done)
void loop() {
  if(digitalRead(4) == 0){
    scan_servo.write(start_of_range);
    delay(500);
    
    Serial.println("$");// shows the start of a row, begin reading data for neural net
    for(int angle = start_of_range; angle > start_of_range - 90; angle--){
      scan_servo.write(angle);
      int distance = dist.read();
      Serial.println(distance);
      delay(25);
    }


  }
}
