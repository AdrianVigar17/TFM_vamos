#define ENA 5
#define INA 8
#define ENB 6
#define INB 7
#define velocidad 150

void setup() {

  pinMode(INA, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(INB, OUTPUT);
  pinMode(ENB, OUTPUT);
  Serial.begin(9600);

}
void loop(){

  delante();
  Serial.print("estoy en movimiento jurao");
  Serial.println(" pero...");
  delay(5000);
  parar();
  Serial.print("ahora estoy parado");
  Serial.println(" pero...");
  delay(5000);



  
}

void delante(){
  analogWrite(ENA, velocidad);
  digitalWrite(INA, LOW);
  analogWrite(ENB, velocidad);
  digitalWrite(INB, HIGH);
}
void parar() {
  analogWrite(ENA, 0);
  digitalWrite(INA, HIGH);
  analogWrite(ENB, 0);
  digitalWrite(INB, LOW);
}
