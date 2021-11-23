//ALEJANDRO PAZ FERREIROS TIPO 2

int puls1=2;
int puls2=4;
int led1=5;
int led2=7;

int valor1=0;
int valor2=0;


void setup() {

  
pinMode(puls1,INPUT);
pinMode(puls2, INPUT);
pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);
Serial.begin(9600);
}

void loop() {
valor1=digitalRead(puls1);
valor2=digitalRead(puls2);

if(valor1==valor2){
  digitalWrite(led1,LOW);
  digitalWrite(led2,LOW);
}
else if(valor1==HIGH, valor2==LOW){
  digitalWrite(led1,HIGH);
  digitalWrite(led2,LOW);
}
  else if(valor1==LOW,valor2==HIGH){
    digitalWrite(led1,LOW);
    digitalWrite(led2,HIGH);
  }

Serial.print("Pulsador 1= ");
  Serial.println(valor1);

  Serial.print("Pulsador 2= ");
  Serial.println(valor2);

  Serial.print("led 1= ");
  Serial.println(led1);
  
  Serial.print("led 2= ");
  Serial.println(led1);
  delay(1000);






}
