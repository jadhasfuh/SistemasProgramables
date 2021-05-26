#include <rgb_lcd.h>
#include <LiquidCrystal.h>
#include <VirtualWire.h>
//CEJA RENTERIA ADRIAN 17420533
//IXTA ZAMUDIO LUIS JOSE 17420565
//MENDIOLA CORREA CESAR PAULINO 17420579
#include <Wire.h>

rgb_lcd lcd;

const int colorR = 255;
const int colorG = 0;
const int colorB = 0;

//VARIABLES DEL LCD

int columna2=0;
String msj = "Escribe caracter";
//SLAVE PRACTICA 4
void setup() {
  //CARGAMOS
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.setRGB(colorR, colorG, colorB);
  lcd.clear();
  vw_set_ptt_inverted(true);
  vw_set_rx_pin(8);
  vw_setup(4000);
  vw_rx_start();//INICIA
  //MENSAJE DE PRUEBA  
  lcd.setCursor(0,1);
  lcd.print(msj);
}

void loop() {

  
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen =VW_MAX_MESSAGE_LEN;
  if (vw_get_message(buf,&buflen))
  {
     if (columna2>=16){
      int columna3=columna2-16;
      lcd.setCursor(columna3,1);
    }else{
      lcd.setCursor(columna2,0);
    }
    //VEMOS EL MENSAJE
    Serial.print((char)buf[0]);
    lcd.print((char)buf[0]);
    //incrementa
    columna2++;

        if (columna2==16){
      //BORRADO
      lcd.setCursor(0,1);
      lcd.print("               _");  
    }
    //Si llego al final de la linea
    if (columna2>32 || buf[0]==';'){
      Serial.println();
      Serial.print("limpia");
      Serial.println();
      lcd.clear();
      columna2=0;
      lcd.setCursor(0,1);
      lcd.print(msj);
      delay(100);
    }
  }
}
