//CEJA RENTERIA ADRIAN 17420533
//IXTA ZAMUDIO LUIS JOSE 17420533
//MEDIOLA CORREA CESAR PAULINO 17420533

//SLAVE PRACTICA 1.2
#include <Wire.h>

byte M = 0;

void setup(){

  //INICIALIZAMOS COMUNICACION
  //Serial.begin(9600);
  //INICIALIZAMOS BUS COMO ESCLAVO
  Wire.begin(0x08); 
  //FUNCION QUE SE ACTIVA CUANDO ALGO SE RECIVE
  Wire.onReceive(solicitud);
  //FUNCION QUE SE ACTIVA CUANDO ALGO SE PIDE
  Wire.onRequest(pedido); 
  //INICIALIZAMOS LOS COMPONTES
  pinMode(13, OUTPUT);
      
}

void loop(){

  luz();
  delay (1000);
  
}

void solicitud() {
  
  //LEE AL MAESTRO
  while(Wire.available()) M = Wire.read();
  //Serial.print("SLAVE RECIBE: ");
  //Serial.println(M);
  
}

void pedido() {
  
  //ENVIA AL MAESTRO
  if (M == 1){
    M = 0;
    Wire.write(M);
  }else if (M == 0) {
    M = 1;
    Wire.write(M);
  }
  //Serial.print("SLAVE ENVIA: ");
  //Serial.println(M);
  
}

void luz(){
  if (M == 1) digitalWrite(13,HIGH);
  else if (M == 0) digitalWrite(13,LOW);
}
