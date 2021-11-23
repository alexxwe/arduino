//Practica9 C servomotor

#include<Servo.h>

Servo myservo;  //crea objeto

int pos=0;

void setup() {
  myservo.attach(7);  //terminal de conexión del servo pin7
}

void loop() {
  pos=0;  //a la derecha

  myservo.write(pos);
  delay(1000);

  pos=90;  //centro

  myservo.write(pos);
  delay(1000);

  pos=180;  //a la izquierda

  myservo.write(pos);
  delay(1000);

}
