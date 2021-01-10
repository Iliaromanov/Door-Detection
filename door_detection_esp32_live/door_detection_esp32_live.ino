#include <EloquentTinyML.h>
#include "bytearray_full_model.h" // in the same directory as this sketch is the model

#define NUMBER_OF_INPUTS 90
#define NUMBER_OF_OUTPUTS 1
#define TENSOR_ARENA_SIZE 128*64

Eloquent::TinyML::TfLite<NUMBER_OF_INPUTS, NUMBER_OF_OUTPUTS, TENSOR_ARENA_SIZE> ml(bytearray_full_model);

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
