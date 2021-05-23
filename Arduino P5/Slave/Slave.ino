//CEJA RENTERIA ADRIAN 17420533
//IXTA ZAMUDIO LUIS JOSE 17420533
//MEDIOLA CORREA CESAR PAULINO 17420533

//SLAVE PRACTICA 5
byte M = 0;

void setup() {

  //INICIALIZA SERIAL
  Serial.begin(9600);

  //INICIALIZAMOS LOS COMPONTES
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  
}

void loop() {
digitalWrite(11, HIGH);
  //ACTIVAMOS LO QUE VENGA
  if(Serial.available() > 0){
    
    M = Serial.read();
    
    if (M == 0){
      digitalWrite(11, LOW);
      digitalWrite(12, LOW);
      digitalWrite(13, LOW); 
    }else if (M == 100){
      digitalWrite(11, HIGH);
      digitalWrite(12, LOW);
      digitalWrite(13, LOW); 
    }else if (M == 10){
      digitalWrite(11, LOW);
      digitalWrite(12, HIGH);
      digitalWrite(13, LOW); 
    }else if (M == 1){
      digitalWrite(11, LOW);
      digitalWrite(12, LOW);
      digitalWrite(13, HIGH); 
    }else if (M == 110){
      digitalWrite(11, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(13, LOW); 
    }else if (M == 11){
      digitalWrite(11, LOW);
      digitalWrite(12, HIGH);
      digitalWrite(13, HIGH); 
    }else if (M == 101){
      digitalWrite(11, HIGH);
      digitalWrite(12, LOW);
      digitalWrite(13, HIGH); 
    }else if (M == 111){
      digitalWrite(11, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(13, HIGH); 
    }
    
  }
  
}
