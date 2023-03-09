#define echoPin 0
#define trigPin 1
#define ENA 5
#define INA 8
#define ENB 6
#define INB 7
#define velocidad 350
long duration;
int distance = 20;
int detect;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(INA, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(INB, OUTPUT);
  pinMode(ENB, OUTPUT);
  
  
}

void loop() {      
    ultradelante(); 
  /*Serial.print("Distance: ");*/
  /*Serial.println(distance);*/
  /*delay(1000);*/
}
/*mueve los motores hacia delante*/
void delante(){ 
  analogWrite(ENA, velocidad);
  digitalWrite(INA, LOW);
  analogWrite(ENB, velocidad);
  digitalWrite(INB, HIGH);
}
/*detiene los motores*/
void parar() {
  analogWrite(ENA, 0);
  digitalWrite(INA, HIGH);
  analogWrite(ENB, 0);
  digitalWrite(INB, LOW);
}
int ultradelante(){
    digitalWrite(trigPin, HIGH);      
    delayMicroseconds(5);
    digitalWrite(trigPin, LOW);   
    duration = pulseIn(echoPin, HIGH);  
    distance = (duration/2) / 29.1;
    Serial.print("Distance: ");
    Serial.println(distance);
    delay(100);
    if (distance > 30){
      delante();         
    }else{
      parar();
    }
}
