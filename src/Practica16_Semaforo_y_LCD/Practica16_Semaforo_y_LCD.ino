//Práctica16 Semaforo y LCD

#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>


#define I2C_ADDR 0x27  //ese 0x significa que es hexadecimal, no decimal

LiquidCrystal_I2C lcd(I2C_ADDR,2,1,0,4,5,6,7);

int verde=3;
int amarillo=4; 
int rojo=5;  

void setup() {
  
  pinMode(verde,OUTPUT);
  pinMode(amarillo,OUTPUT);
  pinMode(rojo,OUTPUT);
  Serial.begin(9600);
  
  lcd.begin(16,2);  //inicializamos el display, 16 caracteres en 2 lineas
  
  lcd.setBacklightPin(3,POSITIVE);  //encender luz
  lcd.setBacklight(HIGH);
  lcd.clear();
}

void loop() {

  Serial.println("Semaforo - Inicio");//Escribe el texto en puerto serie
  digitalWrite(verde,HIGH); //Led verde on
  Serial.println("Semaforo-Verde"); //Escribe texto Serial
  lcd.home();
  lcd.setCursor(0,0);  //posición 0 linea 0
  lcd.print("Semaforo Verde");
  lcd.setCursor(0,1);
  lcd.print("PASE");
  delay(5000);
  digitalWrite(verde,LOW);  //Led verde off
  lcd.clear();
  
  digitalWrite(amarillo,HIGH); //Led amarillo on
  Serial.println("Semaforo-Amarillo"); //Escribe texto Serial
  lcd.home();
  lcd.setCursor(0,0);  //posición 0 linea 0
  lcd.print("ATENCION");
  lcd.setCursor(0,1);
  lcd.print("CAMBIO");
  delay(2000);
  digitalWrite(amarillo,LOW);  //Led amarillo off
  lcd.clear();
  
  digitalWrite(rojo,HIGH);
  Serial.println("Semaforo-Rojo"); 
  lcd.home();
  lcd.setCursor(0,0);  //posición 0 linea 0
  lcd.print("Semaforo Rojo");
  lcd.setCursor(0,1);
  lcd.print("STOP"); 
  delay(4000);
  digitalWrite(rojo,LOW);
  lcd.clear();
}
