#include <Wire.h>

#define I2C_ADDRESS 1    //i2c Slave Address

void setup() {
  
  for(int i=2; i<10; i++){
    pinMode(i, OUTPUT);
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
  
  analogWrite(pin, (val==1)? HIGH:LOW);
  Serial.print("Pin=");
  Serial.print(pin);
  Serial.print("\tVal=");
  Serial.println(val);
}
