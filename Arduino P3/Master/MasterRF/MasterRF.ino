#include <VirtualWire.h>
//CEJA RENTERIA ADRIAN 17420533
//IXTA ZAMUDIO LUIS JOSE 17420565
//MENDIOLA CORREA CESAR PAULINO 17420579

//MASTER PRACTICA 3
char *controlador;
char entrada;

void setup() {
  //INICIALIZAMOS
  Serial.begin(9600);
  //COMUNICACION WIRELESS
  vw_set_ptt_inverted(true);
  vw_set_tx_pin(2);
  vw_setup(4000);
  delay(100);
}

void loop() {
  //ENTRADA DE DATOS 
  if(Serial.available()> 0){
    entrada = Serial.read();
    Serial.println(entrada);
    Opciones();
  }
  delay(1000);
}
void Opciones(){
  Serial.println();
  Serial.print("La entrada fue -->  ");
  Serial.print(entrada);
  Serial.println();
  //COMPARACIONES
  if (entrada=='a' || entrada=='A'){
    //APAGADO OFF
    controlador="0";
    Serial.println(controlador);
  //PASAMOS LOS DATOS AL WR
  vw_send((uint8_t *)controlador, strlen(controlador));
  vw_wait_tx();//ACE LA ESPERA
  }
  if (entrada=='e' || entrada =='E'){
    //ENCENDIDO On
    controlador="1";
    Serial.println(controlador);
  //PASAMOS LOS DATOS AL WR
  vw_send((uint8_t *)controlador, strlen(controlador));
  vw_wait_tx();//ACE LA ESPERA
  }

}
