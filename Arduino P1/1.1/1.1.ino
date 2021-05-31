//CEJA RENTERIA ADRIAN 17420533
//IXTA ZAMUDIO LUIS JOSE 17420533
//MEDIOLA CORREA CESAR PAULINO 17420533

// PRACTICA 1

char readChar; 

void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT); //  LED ROJO
  pinMode(3, OUTPUT); //  LED VERDE
  pinMode(4, OUTPUT); //  LED AZUL
  pinMode(5, OUTPUT); //  BUZZER
}

void loop() {
  if (Serial.available() > 0) {
    readChar = Serial.read();
    action(readChar);
  }
}

void action(char readChar){
   if (readChar == 'r') {
      digitalWrite(5, HIGH);
      delay(200);
      digitalWrite(5, LOW);
   }
   if (readChar == 'g') {
      digitalWrite(4, HIGH);
      delay(200);
      digitalWrite(4, LOW);
   }  
   if (readChar == 'b') {
      digitalWrite(3, HIGH);
      delay(200);
      digitalWrite(3, LOW);
   }  
   if (readChar == 's') {

      // MODIFICACION DEL AUDIO
      tone(2, 440);
      delay(300);
      noTone(2);
      tone(2, 740);
      delay(100);
      noTone(2);
   
      digitalWrite(2, LOW);
   }
}


    
