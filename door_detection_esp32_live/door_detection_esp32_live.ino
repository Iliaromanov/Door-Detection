#include <EloquentTinyML.h>
#include "bytearray_full_model.h" // in the same directory as this sketch is the model
#include "arduino.h"

#define NUMBER_OF_INPUTS 90
#define NUMBER_OF_OUTPUTS 1
#define TENSOR_ARENA_SIZE 128*64

#define RX 16
#define TX 17



Eloquent::TinyML::TfLite<NUMBER_OF_INPUTS, NUMBER_OF_OUTPUTS, TENSOR_ARENA_SIZE> ml;

void setup() {
  Serial.begin(9600);
  Serial2.begin(2400, SERIAL_8N1, RX, TX);
}

void loop() {
  while(Serial2.available()){
   // if(Serial2.read() == 0x2E)
    //  Serial.println();
   // else
      char x = Serial2.read();
      Serial.print(x);
      
    
  }
}
