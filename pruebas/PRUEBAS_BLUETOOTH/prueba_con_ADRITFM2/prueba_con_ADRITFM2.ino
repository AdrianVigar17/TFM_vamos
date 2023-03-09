//PROBANDO CON LA PLACA PRUEBA Y EL MODULO BLUETOOTH ADRITFM2 -> ES EL QUE SE SUPONE QUE ES MAESTRO

#include <SoftwareSerial.h> // Incluimos la librería SoftwareSerial
SoftwareSerial BT(11,10); // Definimos los pines RX y TX del Arduino conectados al Blue

void setup() {
  BT.begin(38400); // Inicializamos el puerto serie BT (Para Modo AT 2)
  Serial.begin(38400); // Inicializamos el puerto serie
  Serial.println("Bluetooth Test");
  // put your setup code here, to run once:

}

void loop() {
  if(BT.available()) // Si llega un dato por el puerto BT se envía al monitor serial
{
Serial.write(BT.read());
}
if(Serial.available()) // Si llega un dato por el monitor serial se envía al puerto BT
{
BT.write(Serial.read());
}
  

}
