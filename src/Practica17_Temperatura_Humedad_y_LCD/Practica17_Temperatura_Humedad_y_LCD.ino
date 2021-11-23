//Practica17 Temperatura Humedad y Lcd
#include <DHT11.h>
int pin=2;  //variable
DHT11 dht11(pin);

//PANTALLA LCD
#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal.h>
#include <LiquidCrystal_I2C.h>
#define I2C_ADDR 0x27  //identifica LCD 0x27
LiquidCrystal_I2C lcd(I2C_ADDR,2,1,0,4,5,6,7);
//LiquidCrystal_I2C lcd(I2C_ADDR,16,2);

void setup() {
  lcd.begin(16,2);
  lcd.setBacklightPin(3,POSITIVE);
  lcd.setBacklight(HIGH);
  lcd.clear();
  Serial.begin(9600);
}

void loop() {
  int error;
  float temp, hum;

   if((error=dht11.read(hum,temp))==0){  //si devuelve 0 es que ha leido bien
     Serial.print("Temperatura: ");
     Serial.print(temp);
     Serial.print("Humedad: ");
     Serial.print(hum);
     Serial.println();

     //PANTALLA

     lcd.setCursor(0,0);
     lcd.print("TEMP: ");
     lcd.print(temp);
     lcd.setCursor(0,1);
     lcd.print("Humedad: ");
     lcd.print(hum);
    }

  else{
    Serial.println();
    Serial.print("Error Num: ");
    Serial.print(error);
    Serial.println();

    //PANTALLA
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Error Num: ");
    lcd.print(error);
  }
  delay(1000);
}
