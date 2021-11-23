//Practica 2 Semaforo
/* 3 Leds conectados a los pines 3(verde), 4(amarillo), 5(rojo).
*/
int verde=3;  //inicializacion variables y relacion con pines
int amarillo=4; 
int rojo=5;       

void setup() {
  //definimos funcion de pin
  pinMode(verde,OUTPUT);   //pin como salida
  pinMode(amarillo,OUTPUT);
  pinMode(rojo,OUTPUT);
Serial.begin(9600);  //inicializamos a comunicación Serial.
}

void loop() {
  Serial.println("Semaforo - Inicio");//Escribe el texto en puerto serie
  digitalWrite(verde,HIGH); //Led verde on
  Serial.println("Semaforo-Verde"); //Escribe texto Serial
  delay(30000); //duracion luz verde encendida, 30 segundos
  digitalWrite(verde,LOW);  //Led verde off

  digitalWrite(amarillo,HIGH); //Led amarillo on
  Serial.println("Semaforo-Amarillo"); //Escribe texto Serial
  delay(18000); //duracion luz amarilla encendida, 8 segundos
  digitalWrite(amarillo,LOW);  //Led amarillo off

  digitalWrite(rojo,HIGH); //Led rojo on
  Serial.println("Semaforo-Rojo"); //Escribe texto Serial
  delay(20000); //duracion luz roja encendida, 20 segundos
  digitalWrite(rojo,LOW);  //Led amarillo off
 
}
