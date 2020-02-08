#define sensor_l2 A1

void setup() {
  Serial.begin(9600);
  pinMode(sensor_l2, INPUT);
}

void loop() {
  int valor = analogRead(sensor_l2);
  Serial.println(valor);
  /*if(valor >= 900){
    Serial.println("Preto");
  }
  if(valor < 900){
    Serial.println("Branco");
  }*/
}
