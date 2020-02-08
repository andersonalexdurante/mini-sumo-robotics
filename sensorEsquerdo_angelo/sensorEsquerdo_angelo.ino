#define sensor_esquerda 3

void setup() {
  Serial.begin(9600);
  pinMode(sensor_esquerda, INPUT);
}

void loop(){
  int valor = digitalRead(sensor_esquerda);
  if(valor == 0){
    Serial.println("Sem Movimento");
  }
  if(valor == 1){
    Serial.println("Com Movimento");
  }
}

