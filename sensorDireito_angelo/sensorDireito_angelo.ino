#define sensor_direita 4

void setup() {
  Serial.begin(9600);
  pinMode(sensor_direita, INPUT);
}

void loop(){
  int valor = digitalRead(sensor_direita);
  if(valor == 0){
    Serial.println("Sem Movimento");
  }
  if(valor == 1){
    Serial.println("Com Movimento");
  }
}

