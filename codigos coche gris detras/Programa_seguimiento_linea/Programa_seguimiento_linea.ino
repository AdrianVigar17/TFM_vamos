#include <Servo.h>
#define SensorIzq A2
#define SensorMed A1
#define SensorDer A0
#define UmbralInf 400
#define velocidad 200
#define ENA 5
#define INA 8
#define ENB 6
#define INB 7
#define pinservodireccion 10
Servo servo2;

int estado, estadoanterior;
float lecturaIzq;
float lecturaMed;
float lecturaDer;
float vectordatos[3] = {0, 0, 0};
int pulsomin = 1000;
int pulsomax = 2000;

void setup() {
  pinMode(SensorIzq, INPUT);
  pinMode(SensorMed, INPUT);
  pinMode(SensorDer, INPUT);
  pinMode(INA, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(INB, OUTPUT);
  pinMode(ENB, OUTPUT);
  servo2.attach(pinservodireccion, pulsomin, pulsomax);
  servo2.write(90);
  estado=1;
 
  
}


void loop() {
  delante();
  lectura();
  switch(estado){
    case 1:{
      servo2.write(90);
      delay(30);
      break;
  }
  case 2:{
      servo2.write(45);
      delay(30);
      break;
  }
  case 3:{
      servo2.write(135);
      delay(30);
      break;
  }
}
}

void lectura(){
  if(estado!=1){
 estadoanterior=estado;
  }
 lecturaIzq = analogRead(SensorIzq);
 lecturaMed = analogRead(SensorMed);
 lecturaDer = analogRead(SensorDer);
 
 if (lecturaMed>=UmbralInf){                         /*sensor central detecta linea*/    
  estado = 1; 
}
 if(lecturaMed<UmbralInf&&lecturaIzq>=UmbralInf){    /*sensor izq detecta linea*/ 
  estado = 2;
 }
  if(lecturaMed<UmbralInf&&lecturaDer>=UmbralInf){   /*sensor der detecta linea*/ 
  estado = 3;
 }
 if(lecturaMed<UmbralInf&&lecturaIzq<UmbralInf&&lecturaDer<UmbralInf){
   estado=estadoanterior;
 }
 
}

void delante(){
  analogWrite(ENA, velocidad);
  digitalWrite(INA, LOW);
  analogWrite(ENB, velocidad);
  digitalWrite(INB, HIGH);
}
