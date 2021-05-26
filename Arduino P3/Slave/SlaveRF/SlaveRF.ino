#include <VirtualWire.h>
//CEJA RENTERIA ADRIAN 17420533
//IXTA ZAMUDIO LUIS JOSE 17420565
//MENDIOLA CORREA CESAR PAULINO 17420579

//SLAVE PRACTICA 3
void setup() {
  //CARGAMOS
  vw_set_ptt_inverted(true);
  vw_set_rx_pin(12);
  vw_setup(4000);
  Serial.begin(9600);
  pinMode(8,OUTPUT);
  digitalWrite(8,LOW);
  vw_rx_start();//INICIA
}

void loop() {
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen =VW_MAX_MESSAGE_LEN;
  if (vw_get_message(buf,&buflen))
  {
  if (buf[0]=='1'){
    //ENCIENDE
    Serial.println('E');
    digitalWrite(8,HIGH);
    delay(500);
  }else{
    //APAGA
    Serial.println('A');
    digitalWrite(8,LOW);
    delay(500);
  }
  }
}
