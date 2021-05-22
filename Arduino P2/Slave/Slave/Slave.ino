//CEJA RENTERIA ADRIAN 17420533
//IXTA ZAMUDIO LUIS JOSE 17420533
//MEDIOLA CORREA CESAR PAULINO 17420533

//SLAVE PRACTICA 2

#include <Wire.h>
#include <LiquidCrystal.h>

//INICIALIZAMOS LCD
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
char temp[] = "TEMP = 00.0 C  ";
char hume[] = "HUME = 00.0 %  ";
int data[2];

void setup() {

  //INICIALIZA SERIAL
  Serial.begin(9600);
  //INICIALIZAMOS BUS COMO ESCLAVO
  Wire.begin(9); 
  //FUNCION QUE SE ACTIVA CUANDO ALGO SE RECIVE
  Wire.onReceive(solicitud);
  //INICIALIZAMOS LOS COMPONTES
  lcd.begin(16, 2);
  
}

void solicitud() {

  for(int i=0; i<2; i++){
    data[i] = Wire.read();
    Serial.println(data[i]);
  }

  if (isnan(data[0]) || isnan(data[1])) {
    lcd.clear();
    lcd.setCursor(5, 0);
    lcd.print("Error");
    return;
  }

  //IMPRIMIMOS EN LA LCD
  temp[7]  = data[0] / 10 + 48;
  temp[8]  = data[0] % 10 + 48;
  temp[11] = 223;
  hume[7]  = data[1] / 10 + 48;
  hume[8]  = data[1] % 10 + 48;
 
  lcd.setCursor(0, 0);
  lcd.print(temp);
  lcd.setCursor(0, 1);
  lcd.print(hume);

}

void loop() {
  
  delay(100);
  
}
