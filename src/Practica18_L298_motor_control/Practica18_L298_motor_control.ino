//Practica18 L298 motor control

//Motor A pins
int ENA=10;  //PWM
int IN1=9;
int IN2=8;

//Motor B
int ENB=5;  //PWM
int IN3=7;
int IN4=6;

void setup() {
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
}

//Escribimos las diferentes secuencias
void Adelante(){
  //Direccion MotorA
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  analogWrite(ENA,255);  //velocidad 0-255  0-5Vcc

  //Direccion MotorB
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  analogWrite(ENB,255);
}

void Atras(){
  //Direccion MotorA
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  analogWrite(ENA,128);

  //Direccion MotorB
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  analogWrite(ENB,200);
}

void Derecha(){
  //Dirección MotorA
  digitalWrite(IN1,HIGH); //direccion giro
  digitalWrite(IN2,LOW);
  analogWrite(ENA,200);  //velocidad 0-255, 0-5Vcc

  //Direccion MotorB
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  analogWrite(ENB,100);
}

void Izquierda(){
  //Dirección MotorA
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  analogWrite(ENA,50);
  //Dirección MotorB
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  analogWrite(ENB,150);
}

void Parar(){
  //Dirección MotorA
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  analogWrite(ENA,0);
  //Dirección MotorA
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
  analogWrite(ENB,0);
}

void loop() {
//LLamamos a las rutinas anteriores
  Adelante();
  delay(5000);
  Atras();
  delay(5000);
  Derecha();
  delay(2000);
  Izquierda();
  delay(2000);
  Parar();
  delay(4000);

}
