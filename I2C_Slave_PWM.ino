#include <Wire.h>

#define I2C_ADDRESS 5    //i2c Slave Address

const int lowestPin = 2;
const int highestPin = 13;

void setup() {
  
  for(int i=lowestPin; i<=highestPin ; i++){
    pinMode(i, OUTPUT); //set pin sebagai output
  }
  
  Serial.begin(9600);
  Wire.begin(I2C_ADDRESS);
  Wire.onReceive(receiveEvent);
  
}

void loop() {
  //delay(1);
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany) {
  int pin = Wire.read();
  int val = Wire.read();    // receive byte as an integer
  analogWrite(pin, val);
}
