//Practica10 Servomotor y potenciometro

#include <Servo.h>

Servo myservo;  //creamos el objeto de motor de servo

int potpin=A0;  //pin A0 analogico para control de motor
int val;  //variable para la lectura de valor analogico

void setup() {
  myservo.attach(9);  //Pin9 control servomotor
  Serial.begin(9600);  //monitor Serial
}

void loop() {
  val=analogRead(potpin);  //lectura del valor del potenciometro(valores 90 and 1023)
  val=map(val, 0, 1023, 0, 180);  //correlacion de escalas(valores entre 0 and 180)

  myservo.write(val);  //escribimos el valor en el servomotor
  delay(150);  //delay de retraso

  //texto monitor serial
  Serial.print("Servomotor= ");
  Serial.println(val);
  
}
