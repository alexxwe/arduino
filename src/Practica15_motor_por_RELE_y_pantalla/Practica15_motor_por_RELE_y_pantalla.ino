//Practica15 motor por RELE y panatalla
//Motor  en ON cuando S1y S2 esten activos
//libreria y datos pantalla LCD I2P

#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

#define I2C_ADDR 0x27
LiquidCrystal_I2C lcd(I2C_ADDR,2,1,0,4,5,6,7);

int pulsa1=8;
int pulsa2=12;
int salida=4;

int motor=0;  //Pin motor

int valor1=0;  //creamos 2 variables para guardar
int valor2=0;  //los valores de los pulsadores

void setup() {
  Serial.begin(9600);
  pinMode(pulsa1,INPUT);  //definimos pin de entrada
  pinMode(pulsa2,INPUT);

  pinMode(4,OUTPUT);  //definimos pin de salida

  //pantalla LCD
  lcd.begin(16,2);  //inicializamos el display, 16 caracteres en 2 lineas
  
  lcd.setBacklightPin(3,POSITIVE);  //encender luz
  lcd.setBacklight(HIGH);
}

void loop() {
  valor1=digitalRead(pulsa1);  //lectura de entradas digitales
  valor2=digitalRead(pulsa2);
  motor=digitalRead(salida);
  if(valor1 && valor2 == 1){
    digitalWrite(salida,HIGH);
  }
  else{
    digitalWrite(salida, LOW);
  }

  Serial.print("Pulsador 1= ");
  Serial.println(valor1);
  
  Serial.print("Pulsador 2= ");
  Serial.println(valor2);
  
  Serial.print("Motor= ");
  Serial.println(motor);
    delay(1000);

  //Texto para LCD
  
  lcd.home();
  lcd.setCursor(0,0);  //posición 0 linea 0
  lcd.print("Pulsa1=");
  lcd.print(valor1);

  lcd.print("Pulsa2=");
  lcd.print(valor2);

  lcd.setCursor(0,1); //posicion 0 de la linea 1
  lcd.print("motor=");
  lcd.print(motor);
}
