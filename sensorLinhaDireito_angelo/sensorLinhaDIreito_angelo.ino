#define sensor_l1 A0

void setup() {
  Serial.begin(9600);
  pinMode(sensor_l1, INPUT);
}

void loop() {
  int valor = analogRead(sensor_l1);
  if(valor >= 900){
    Serial.println("Preto");
  }
  if(valor < 900){
    Serial.println("Branco");
  }
}
