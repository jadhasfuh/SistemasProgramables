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

  M = 'A';
  
  //LECTURA DE LOS TRES INPUTS Y ENVIO
  if (digitalRead(3) == LOW   &&
      digitalRead(4) == LOW   &&
      digitalRead(5) == LOW   ) M = 'A';
  else if (
      digitalRead(3) == HIGH  &&
      digitalRead(4) == LOW   &&
      digitalRead(5) == LOW   ) M = 'B';
  else if (
      digitalRead(3) == LOW   &&
      digitalRead(4) == HIGH  &&
      digitalRead(5) == LOW   ) M = 'C';
  else if (
      digitalRead(3) == LOW   &&
      digitalRead(4) == LOW   &&
      digitalRead(5) == HIGH  ) M = 'D';
  else if (
      digitalRead(3) == HIGH  &&
      digitalRead(4) == HIGH  &&
      digitalRead(5) == LOW   ) M = 'E';
  else if (
      digitalRead(3) == LOW   &&
      digitalRead(4) == HIGH  &&
      digitalRead(5) == HIGH  ) M = 'F';
  else if (
      digitalRead(3) == HIGH  &&
      digitalRead(4) == LOW   &&
      digitalRead(5) == HIGH  ) M = 'G';
  else if (
      digitalRead(3) == HIGH  &&
      digitalRead(4) == HIGH  &&
      digitalRead(5) == HIGH  ) M = 'H';

  Serial.write(M);
  delay(10);
  
}
