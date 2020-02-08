#define ENA 6//esquerda
#define ENB 5//direita
#define IN1 11//esquerda
#define IN2 10//esquerda
#define IN3 9//direita
#define IN4 8//direita

void setup() {
  Serial.begin(9600);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT); 
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop(){
  avancar();
}

void controlarMotores(int EnMotor, int velocidade, int rotacao, int In1, int In2){//rotacao = 1 eh para frente, rotacao = 2 eh para tras
  if(rotacao == 1){//frente
     analogWrite(EnMotor, velocidade);// ENA OU ENB
     digitalWrite(In1, HIGH);
     digitalWrite(In2, LOW);
  }
  if(rotacao == 2){//tras
     analogWrite(EnMotor, velocidade);// ENA OU ENB
     digitalWrite(In1, LOW);
     digitalWrite(In2, HIGH);
  }
}

void avancar(){
  controlarMotores(ENA, 150, 1, IN1, IN2);
  controlarMotores(ENB, 150, 1, IN3, IN4);
}
