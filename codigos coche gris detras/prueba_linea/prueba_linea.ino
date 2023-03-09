#define SensorIzq A2
#define SensorMed A1
#define SensorDer A0

float lecturaIzq;
float lecturaMed;
float lecturaDer;

void setup() {
  Serial.begin(9600);
  pinMode(SensorIzq, INPUT);
  pinMode(SensorMed, INPUT);
  pinMode(SensorDer, INPUT);
}

void loop() {
  lecturaIzq = analogRead(SensorIzq);
  lecturaMed = analogRead(SensorMed);
  lecturaDer = analogRead(SensorDer);
  Serial.print(lecturaIzq);
  Serial.print("\t");
  Serial.print(lecturaMed);
  Serial.print("\t");
  Serial.print(lecturaDer);
  Serial.print("\t");
  Serial.print("\r\n");
  delay(100);
}
