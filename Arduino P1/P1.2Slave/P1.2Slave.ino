/*String inputString = "";
boolean stringComplete = false;*/
char msj;
char msj2;

void setup() {
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  //inputString.reserve(200);
}

void loop() {
  msj = Serial.read();
  Serial.println(msj);
  leerMensaje();
  /*if(stringComplete) {
    Serial.print(inputString);
    if(inputString == "ON_"){
      digitalWrite(13,HIGH);
    }else 
      if(inputString == "OFF_"){
      digitalWrite(13,LOW);
    }
    inputString = "";
    stringComplete = false;
  }*/
}

void leerMensaje() {
  if(msj == 'I') {
    digitalWrite(13,HIGH);
    msj2 = 'I';
  } 
  else
    if(msj == 'O') {
      digitalWrite(13,LOW);
      msj2 = 'O';
    }
  Serial.write(msj2);
}

/*void serialEvent() {
  while(Serial.available()) {
    char inChar = (char)Serial.read();
    inputString += inChar;
    if(inChar == '_') {
      stringComplete = true;
    }
  }
}*/
