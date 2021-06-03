#include <Wire.h>

//CEJA RENTERIA ADRIAN 17420533
//IXTA ZAMUDIO LUIS JOSE 17420533
//MEDIOLA CORREA CESAR PAULINO 17420533

//SLAVE PRACTICA 1.2

char m;

void setup() {
  pinMode (13, OUTPUT);
  Wire.begin(9); 
  Wire.onReceive(receiveEvent);
  Wire.onRequest(requestEvent);
}

void receiveEvent(int bytes) {
  m = Wire.read();  
}

void requestEvent(){
  if (m == 'E') m = 'A';
  else m == 'E';
  Wire.write(m);
}

void loop() {
  if (m == 'E') digitalWrite(13, HIGH);
  else digitalWrite(13, LOW);
  delay(100);
}
