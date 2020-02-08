#define sensor_central 2

void setup() {
  Serial.begin(9600);
  pinMode(sensor_central, INPUT);
}

void loop() {
  int valor = digitalRead(sensor_central);
  if(valor == 1){
    Serial.println("Sem Movimento");
  }
  if(valor == 0){
    Serial.println("Com Movimento");
  }
}
