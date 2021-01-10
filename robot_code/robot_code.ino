#include <SPI.h>
#include <SD.h>
#include <Ultrasonic.h>
#include <Servo.h>

Servo scan_servo;
Ultrasonic dist(6, 7); //ultrasonic sensor on pins 6 and 7

void setup() {
  scan_servo.attach(5); // servo on pin 5
  SD.begin(10); // sd card on pin 10, plus the spi port
}

void loop() {
  // put your main code here, to run repeatedly:

}
