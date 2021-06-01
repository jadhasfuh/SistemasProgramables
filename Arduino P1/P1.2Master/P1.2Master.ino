char msj = 'I';
char msj2;

void setup() {
  Serial.begin(9600);
  pinMode(13,OUTPUT);
}

void loop() {
  if(Serial.available() > 0) {
    msj = Serial.read();
    enviarMessage(msj);
    //delay(1000);
    msj2 = Serial.read();
    leerMensaje(msj);
    /*if(msj == 'O')
      msj = 'I';
    else
      if(msj == 'I')
        msj = 'O';*/

    /*msj = Serial.read();
    on_off_LED(msj);*/
  }
}

void enviarMessage(char msj) {
  if(msj == 'I')
      msj = 'I';
    else
      if(msj == 'O')
        msj = 'O';
  Serial.write(msj);
}

void leerMensaje(char msj2) {
  if(msj2 == 'I')
    digitalWrite(13,HIGH);
  else
    if(msj2 == 'O')
      digitalWrite(13,LOW);
}

/*void on_off_LED(char msj) {
  if(msj == 'I' || msj == 'i') {
    Serial.print("ON_");
  }else
    if(msj == 'O' || msj == 'o') {
      Serial.print("OFF_");
  }
}*/
