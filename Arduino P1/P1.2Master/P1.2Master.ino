//CEJA RENTERIA ADRIAN 17420533
//IXTA ZAMUDIO LUIS JOSE 17420533
//MEDIOLA CORREA CESAR PAULINO 17420533

//MASTER PRACTICA 1.2
#include <Wire.h>

byte M = 0;

void setup(){

  //INICIALIZAMOS COMUNICACION
  Serial.begin(9600);
  //INICIALIZAMOS BUS COMO MASTER SIN DIRECCION
  Wire.begin();   
  //INICIALIZAMOS LOS COMPONTES
  pinMode(13, OUTPUT);
           
}

void loop(){

  //INICIAMOS TRANMISION 
  Wire.beginTransmission(0x08);
  
  //ENVIA AL ESCLAVO
  if (M == 1){
    M = 0;
    Wire.write(M);
  }else if (M == 0) {
    M = 1;
    Wire.write(M);
  }
  Serial.print("MASTER ENVIA: ");
  Serial.println(M);
  
  delay(100);
  
  //TERMINAMOS TRANMISION 
  Wire.endTransmission(); 

  //PEDIMOS INFO
  Wire.requestFrom(0x08, 1);

  //LEE AL ESCLAVO
  while(Wire.available()) M = Wire.read();
   
  Serial.print("MASTER RECIVE: ");
  Serial.println(M);
  
  if (M == 1) digitalWrite(13,HIGH);
  else if (M == 0) digitalWrite(13,LOW);

  delay(1000);
  
}
