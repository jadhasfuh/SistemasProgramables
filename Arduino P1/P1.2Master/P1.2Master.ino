#include <Wire.h>

//CEJA RENTERIA ADRIAN 17420533
//IXTA ZAMUDIO LUIS JOSE 17420533
//MEDIOLA CORREA CESAR PAULINO 17420533

//MASTER PRACTICA 1.2

char m = 'E';

void setup() {
  Wire.begin(); 
  pinMode(13,OUTPUT);
}

void loop() { 

  if (m == 'E'){
    digitalWrite(13, HIGH);
    m = 'A';
  } else {
    digitalWrite(13, LOW);
    m = 'E';
  }

  Wire.beginTransmission(9); 
  Wire.write(m);              
  Wire.endTransmission();  
  
  delay(1000);
  
}
