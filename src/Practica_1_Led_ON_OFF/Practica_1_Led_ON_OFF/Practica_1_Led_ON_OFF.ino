//Practica Numero 1
/*Encender y apagar un Led en PIN 13 
*/


void setup() {
  // put your setup code here, to run once:
pinMode(13,OUTPUT); //definición de pin 13 como salida

}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(13,HIGH);  //escribir valor en un pin digital HIGH
delay(1000);  //retardo de 1 segundo
digitalWrite(13,LOW);  //escribir valor LOW a 0Vcc
}
