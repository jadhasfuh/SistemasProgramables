//CEJA RENTERIA ADRIAN 17420533
//IXTA ZAMUDIO LUIS JOSE 17420533
//MEDIOLA CORREA CESAR PAULINO 17420533

//MASTER B PRACTICA 5

void setup() {
  
  //INICIALIZA SERIAL
  Serial.begin(9600);
  
}

void loop() {

  for(int i = 0; i < 7; i++) {
    Serial.write(65+i);
    delay(100);  
  }
  
}
