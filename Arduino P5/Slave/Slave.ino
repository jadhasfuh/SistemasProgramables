//CEJA RENTERIA ADRIAN 17420533
//IXTA ZAMUDIO LUIS JOSE 17420533
//MEDIOLA CORREA CESAR PAULINO 17420533

//SLAVE PRACTICA 5
//#include <SoftwareSerial.h>
char M;
//SoftwareSerial S(2,3);

void setup() {

  //INICIALIZA SERIAL
  Serial.begin(9600);

  //INICIALIZAMOS LOS COMPONTES
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);

  //ESTADO INICIAL
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
  
}

void loop() {

  //ACTIVAMOS LO QUE VENGA
    M = Serial.read();
    Serial.println(M);
    if (M == 'A'){
      digitalWrite(11, LOW);
      digitalWrite(12, LOW);
      digitalWrite(13, LOW); 
    }else if (M == 'B'){
      digitalWrite(11, HIGH);
      digitalWrite(12, LOW);
      digitalWrite(13, LOW); 
    }else if (M == 'C'){
      digitalWrite(11, LOW);
      digitalWrite(12, HIGH);
      digitalWrite(13, LOW); 
    }else if (M == 'D'){
      digitalWrite(11, LOW);
      digitalWrite(12, LOW);
      digitalWrite(13, HIGH); 
    }else if (M == 'E'){
      digitalWrite(11, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(13, LOW); 
    }else if (M == 'F'){
      digitalWrite(11, LOW);
      digitalWrite(12, HIGH);
      digitalWrite(13, HIGH); 
    }else if (M == 'G'){
      digitalWrite(11, HIGH);
      digitalWrite(12, LOW);
      digitalWrite(13, HIGH); 
    }else if (M == 'H'){
      digitalWrite(11, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(13, HIGH); 
    }

}
