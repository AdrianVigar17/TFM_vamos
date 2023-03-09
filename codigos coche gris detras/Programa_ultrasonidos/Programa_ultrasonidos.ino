
#include <Servo.h>
#define Echodetras 0
#define Trigdetras 1
/* #define Echodelante 12 -> ya no tenemos ultrasonidos trasero, en su lugar aqui iran los pines de bluetooth ( mas adelante) */
/* #define Trigdelante 13 -> ya no tenemos ultrasonidos trasero, en su lugar aqui iran los pines de bluetooth ( mas adelante) */
#define ENA 5
#define INA 8
#define ENB 6
#define INB 7
#define velocidad 150
#define pinservoultra 11
#define pinservodireccion 10
Servo servo1;
Servo servo2;
int pulsomin = 500;
int pulsomax = 2400;
int i = 0;
int tiempo;				
float distancia = 30;			
int contador = 0;	
float distanciamin = 30;	
int detecta;
int barrido = 0;

void delante();
void detras();
void parar();
void giroderecha();
void giroizquierda();
void centradoderecha();
void centradoizquierda();
int ultradelante();
/*int ultradetras(); */
int ultrabarrido();
void setup() {

  pinMode(INA, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(INB, OUTPUT);
  pinMode(ENB, OUTPUT);
  servo1.attach(pinservoultra, pulsomin, pulsomax);
  servo1.write(90);
  servo2.attach(pinservodireccion, pulsomin, pulsomax);
  servo2.write(90);
//  pinMode(Echodetras, INPUT);    	
//  pinMode(Trigdetras, OUTPUT);
  pinMode(Echodelante, INPUT);    
  pinMode(Trigdelante, OUTPUT);
}



void loop() {
  delante();
    detecta = ultradelante();
  if (detecta==1){
    parar();
    barrido = ultrabarrido();
  }
  switch(barrido){
    case 0:{
      detras();
      detecta = ultradetras();
      if (detecta==0){
        parar();
        giroizquierda();
        delante();
        delay(500);
        centradoizquierda();
        delay(250);
        giroderecha();
        delay(250);
        centradoderecha();
      }else if (detecta==1){
        parar();
        giroizquierda();
        delante();
        delay(500);
        centradoizquierda();
        delay(250);
        giroderecha();
        delay(250);
        centradoderecha();
    } break;
  }
    case 1:{
      giroizquierda();
        delante();
        delay(500);
        centradoizquierda();
        delay(250);
        giroderecha();
        delay(250);
        centradoderecha();
    }break;
    case 2:{
      giroderecha();
        delante();
        delay(500);
        centradoderecha();
        delay(250);
        giroizquierda();
        delay(250);
        centradoizquierda();
    }break;
}
}

/*mueve los motores hacia delante*/
void delante(){
  analogWrite(ENA, velocidad);
  digitalWrite(INA, LOW);
  analogWrite(ENB, velocidad);
  digitalWrite(INB, HIGH);
}
/*mueve los motores hacia detras*/
void detras() {
  analogWrite(ENA, velocidad);
  digitalWrite(INA, HIGH);
  analogWrite(ENB, velocidad);
  digitalWrite(INB, LOW);
}
/*detiene los motores*/
void parar() {
  analogWrite(ENA, 0);
  digitalWrite(INA, HIGH);
  analogWrite(ENB, 0);
  digitalWrite(INB, LOW);
}


/*Control del servo de direccion*/

/*se mueve el eje de direccion 45 grados hacia la izquierda*/
void giroizquierda() {
  for (i = 90; i >= 45; i--) {
    servo2.write(i);                    
    delay(20);
  }
}
   /*se mueve el eje de direccion 45 grados hacia la derecha*/
  void giroderecha() {		          
    for (i = 90; i <= 135; i++) { 
    servo2.write(i);
    delay(20);
    }
  } 
  /*el servo vuelve a la posicion de centro desde la posicion izquierda*/
  void centradoizquierda() {
    for (i = 45; i <= 90; i++) {		  
    servo2.write(i);
    delay(20);
    }
  }
  /*el servo vuelve a la posicion de centro desde la posicion derecha*/
  void centradoderecha() {
    for (i = 135; i >= 90; i--) {		
    servo2.write(i);
    delay(20);
    }
  }
        
/* Control del sensor cuando el coche se encuentra en marcha hacia delante*/

int ultradelante(){
  while(distancia>40){			
    digitalWrite(Trigdelante, HIGH);  		
    delayMicroseconds(5);
    digitalWrite(Trigdelante, LOW);   
    tiempo = pulseIn(Echodelante, HIGH);  
    distancia = tiempo*0.017;
    delay(100);					
}
  distancia = 1000;		
  return 1;				
}

/* Control del sensor cuando el coche se encuentra en marcha hacia detras*/

// int ultradetras(){
//  for(i=0; i<=10;i++){
//    digitalWrite(Trigdetras, HIGH);  
//    delayMicroseconds(5);                  
//    digitalWrite(Trigdetras, LOW);   
//    tiempo = pulseIn(Echodetras, HIGH);  
//    distancia = tiempo*0.017;
//    delay(300);
//   if (distancia<40){			/*Si encuentra un obstáculo, la función devuelve un 1*/
//      distancia = 1000;			
//      return 1;
//    }
//  }
//      return 0;				/*Si no encuentra un obstáculo, la función devuelve un 0*/
// }


/*Control del sensor cuando el vehiculo ha encontrado un obstáculo y se detiene para realizar un barrido*/

int ultrabarrido(){ /*Nos hará falta para pruebas del ultrasonido pero no creo , valorarlo */
  servo1.write(90);				    /*se posiciona el servo del sensor en posicion 0*/
  distanciamin = 1000;
  for(i=3; i<=6; i++){
    servo1.write(30*i);
    delay(200);
    digitalWrite(Trigdelante, HIGH);  
    delayMicroseconds(5);
    digitalWrite(Trigdelante, LOW);   
    tiempo = pulseIn(Echodelante, HIGH);  
    distancia = tiempo*0.017;
    delay(500);
    /*Almacenamos en la memoria de la variable	distanciamin el valor mas bajo*/
  	  if (distancia<distanciamin){	   
      distanciamin=distancia;	
    }
  }
   /*Si no hay obstaculos a menos de 19 cm, la funcion devuelve un 1 (girar a la izquierda)*/
  if (distanciamin>29){	
    servo1.write(90);                  
    return 1;				                 	
  } 
  if(distanciamin<29){
    servo1.write(90);
    distanciamin = 1000;
  for(i=6; i>=0; i--){	
    servo1.write(30*i);
    delay(200);
    digitalWrite(Trigdelante, HIGH);  
    delayMicroseconds(5);
    digitalWrite(Trigdelante, LOW);   
    tiempo = pulseIn(Echodelante, HIGH);  
    distancia = tiempo*0.017;
    delay(500);
    if (distancia<distanciamin){
      distanciamin=distancia;
    }
  }
  }
  if (distanciamin>29){
    servo1.write(90);
    return 2;				/*Si no hay obstaculos a menos de 19 cm, la funcion devuelve un 2 (girar a la derecha)*/
  }
 if	(distanciamin<29){			
      servo1.write(90);
    return 0;				/*Si hay obstaculos a menos de 19 cm, a ambos lados la	funcion devuelve un 0 (dar marcha atras)*/
        }				
      }
