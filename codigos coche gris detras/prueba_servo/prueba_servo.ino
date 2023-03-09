/*
  Creado: Luis del Valle (ldelvalleh@programarfacil.com)
  https://programarfacil.com
*/
 
// Incluímos la librería para poder controlar el servo
#include <Servo.h>
#define pinservodireccion 11
// Declaramos la variable para controlar el servo
Servo servoMotor;
int pulsomin = 1000;
int pulsomax = 2000;
 
void setup() {
  // Iniciamos el monitor serie para mostrar el resultado
  Serial.begin(9600);
 
  // Iniciamos el servo para que empiece a trabajar con el pin 9
  servoMotor.attach(pinservodireccion);
}
 
void loop() {
  
  // Vamos a tener dos bucles uno para mover en sentido positivo y otro en sentido negativo
  // Para el sentido positivo
  
  for (int i = 179; i > 0; i--)
  {
    // Desplazamos al ángulo correspondiente
    servoMotor.write(i);
    Serial.print(i);
    Serial.print("\r\n");
    // Hacemos una pausa de 25ms
    delay(5);
  }
  for (int i = 0; i <= 180; i++)
  {
    // Desplazamos al ángulo correspondiente
    servoMotor.write(i);
    Serial.print(i);
    Serial.print("\r\n");
    // Hacemos una pausa de 25ms
    delay(5);
  }
 

}
