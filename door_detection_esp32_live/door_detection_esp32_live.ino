#include <EloquentTinyML.h>
#include "final_dynamic_quantization.h" // in the same directory as this sketch is the model

#define NUMBER_OF_INPUTS 90
#define NUMBER_OF_OUTPUTS 1
#define TENSOR_ARENA_SIZE 32*1024

#define RX 16
#define TX 17



Eloquent::TinyML::TfLite<NUMBER_OF_INPUTS, NUMBER_OF_OUTPUTS, TENSOR_ARENA_SIZE> ml;
// LED pins green : 13  red : 12
void setup() {
  Serial.begin(9600);
  Serial2.begin(2400, SERIAL_8N1, RX, TX);
}

void loop() {
  byte scan_data[90];
  while(Serial2.available()){
    char x = Serial2.read();
    if(x == '$'){
      unsigned char scan_data[90];
      for(int count = 0; count <90; count ++){
        int temporary = Serial2.read();
        if(temporary>= 255)
          temporary = 0;
          
        scan_data[count] = temporary;
        Serial.print(count);
        Serial.print(" ");
        Serial.println(scan_data[count]);
      } 
      bool door_or_not = ml.predict(scan_data);
      Serial.println(door_or_not);   
    }

  }
}
