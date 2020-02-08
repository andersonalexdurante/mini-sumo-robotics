#include<math.h>

//DEFINE OS MOTORES
#define ENA 6//esquerda
#define ENB 5//direita
#define IN1 11//esquerda
#define IN2 10//esquerda
#define IN3 9//direita
#define IN4 8//direita

//DEFINE OS SENSORES DE MOVIMENTO
#define sensor_central 2 
#define sensor_direita 4
#define sensor_esquerda 3

//DEFINE OS SENSORES DE LINHA
#define sensor_l1 A0
#define sensor_l2 A1

int estado_l1;
int estado_l2;

int aleat;

void setup() {
  Serial.begin(9600);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT); 
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(sensor_central, INPUT);
  pinMode(sensor_direita, INPUT);
  pinMode(sensor_esquerda, INPUT);
  pinMode(sensor_l1, INPUT);
  pinMode(sensor_l2, INPUT);
}

void loop(){
 
  //ENCONTROU A LINHA BRANCA
  if(analogRead(sensor_l1 < 900) || analogRead(sensor_l2 < 900)){
    avancarRe();
    paraMotores(IN1, IN2);
    paraMotores(IN3, IN4);
    aleat = random(1,2);
    if(aleat == 1){
      for(int i=0; i<1000; i++){
        giraDireita();
        if(digitalRead(sensor_central) == 0){
          avancar();
          break;
        }
        delay(1);
      }
    }
    else if(aleat == 2){
      for(int i=0; i<1000; i++){
        giraEsquerda();
        if(digitalRead(sensor_central) == 0){
          avancar();
          break;
        }
        delay(1);
      }
    }
    
  }
  
  
  if(digitalRead(sensor_central) == 0){
    avancarTurbo();
  }
  
  if(digitalRead(sensor_direita) == 1){
    giraEsquerda();
  }
  
  if(digitalRead(sensor_esquerda) == 1){
    giraDireita();
  }
}

void avancarTurbo(){
  controlarMotores(ENA, 150, 1, IN1, IN2);
  controlarMotores(ENB, 150, 1, IN3, IN4);
}

void avancar(){
  controlarMotores(ENA, 150, 1, IN1, IN2);
  controlarMotores(ENB, 150, 1, IN3, IN4);
}

void avancarRe(){
  controlarMotores(ENA, 250, 2, IN1, IN2);
  controlarMotores(ENB, 250, 2, IN3, IN4);
}

void giraEsquerda(){
  paraMotores(IN3, IN4);
  controlarMotores(ENA, 150, 1, IN1, IN2);
}
    
void giraDireita(){
  paraMotores(IN1, IN2);
  controlarMotores(ENB, 150, 1, IN3, IN4);
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

void paraMotores(int In1, int In2){
     digitalWrite(In1, LOW);
     digitalWrite(In2, LOW);
}
