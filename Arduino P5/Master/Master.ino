//CEJA RENTERIA ADRIAN 17420533
//IXTA ZAMUDIO LUIS JOSE 17420533
//MEDIOLA CORREA CESAR PAULINO 17420533

//MASTER PRACTICA 5
byte M;

void setup() {
  
  //INICIALIZAMOS LOS COMPONTES
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  
  //INICIALIZA SERIAL
  Serial.begin(9600);
  
}

void loop() {

  M = 0;
  
  //LECTURA DE LOS TRES INPUTS Y ENVIO
  if(digitalRead(3) == HIGH) M += 1;
  if(digitalRead(4) == HIGH) M += 10; 
  if(digitalRead(5) == HIGH) M += 100;

  Serial.write(M);
  delay(20);
  
}
