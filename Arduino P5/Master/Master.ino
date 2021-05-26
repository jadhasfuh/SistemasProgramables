//CEJA RENTERIA ADRIAN 17420533
//IXTA ZAMUDIO LUIS JOSE 17420533
//MEDIOLA CORREA CESAR PAULINO 17420533

//MASTER PRACTICA 5
//#include <SoftwareSerial.h>

//SoftwareSerial S(2,3);// RX,TX
char M;

void setup() {
  
  //INICIALIZAMOS LOS COMPONTES
  pinMode(11, INPUT);
  pinMode(12, INPUT);
  pinMode(13, INPUT);
  
  //INICIALIZA SERIAL
  Serial.begin(9600);
  //S.begin(9600);
  
}

void loop() {

  M = 'A';
  
  //LECTURA DE LOS TRES INPUTS Y ENVIO
  if (
      digitalRead(11) == HIGH  &&
      digitalRead(12) == HIGH  &&
      digitalRead(13) == LOW   ) M = 'D';
  else if (
      digitalRead(11) == LOW   &&
      digitalRead(12) == HIGH  &&
      digitalRead(13) == HIGH  ) M = 'B';
  else if (
      digitalRead(11) == HIGH  &&
      digitalRead(12) == LOW   &&
      digitalRead(13) == HIGH  ) M = 'C';
  else if (
      digitalRead(11) == HIGH  &&
      digitalRead(12) == HIGH  &&
      digitalRead(13) == HIGH  ) M = 'A';

  Serial.write(M);
  delay(50);
  
}
