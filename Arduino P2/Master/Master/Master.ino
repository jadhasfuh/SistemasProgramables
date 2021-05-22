//CEJA RENTERIA ADRIAN 17420533
//IXTA ZAMUDIO LUIS JOSE 17420533
//MEDIOLA CORREA CESAR PAULINO 17420533

//MASTER PRACTICA 2

#include <Wire.h>
#include <DHT.h>

DHT dht(8, DHT11);
byte HUME, TEMP;

void setup() {
  
  //INICIALIZAMOS BUS COMO MASTER SIN DIRECCION
  Wire.begin(); 
  //INICIALIZA SERIAL
  Serial.begin(9600);
  //INICIALIZAMOS LOS COMPONTES
  dht.begin();
  
}

void loop() {

  HUME = dht.readHumidity();
  TEMP = dht.readTemperature();
  Serial.println(HUME);
  Serial.println(TEMP);
  
  //INICIAMOS TRANMISION 
  Wire.beginTransmission(9);
  //LEEMOS TEMPERATURA
  Wire.write(TEMP); 
  //LEEMOS HUMEDAD
  Wire.write(HUME);

  //TERMINAMOS TRANMISION 
  Wire.endTransmission(); 
  
  delay(500);
  
}
