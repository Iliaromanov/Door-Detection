#include <SPI.h>
#include <SD.h>
#include <Ultrasonic.h>
#include <Servo.h>

Servo scan_servo;
Ultrasonic dist(6, 7); //ultrasonic sensor on pins 6 and 7
int start_of_range = 120;


void setup() {
  scan_servo.attach(5); // servo on pin 5
 // SD.begin(10); // sd card on pin 10, plus the spi port
  scan_servo.write(start_of_range);
  Serial.begin(9600);
  
}


// to do: file making (, file writing, ultrasonic scanning (done)
void loop() {
  String scan = "0,";
  for(int angle = start_of_range; angle > start_of_range - 90; angle--){
    scan_servo.write(angle);
    //delay(30);
    int distance = dist.read();
    String distance_string = String(distance) + ",";
    scan += distance_string;
    delay(100);
  }
  Serial.println(scan);
  delay(500);

  
}
