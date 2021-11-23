#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>


#define I2C_ADDR 0x27  //ese 0x significa que es hexadecimal, no decimal

LiquidCrystal_I2C lcd(I2C_ADDR,2,1,0,4,5,6,7);

void setup() {
  lcd.begin(16,2);  //inicializamos el display, 16 caracteres en 2 lineas
  
  lcd.setBacklightPin(3,POSITIVE);  //encender luz
  lcd.setBacklight(HIGH);
  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("Alex Paz");  //texto que va a escribirse en la pantalla
  lcd.setCursor(0,1);  //donde queremos que empiece a escribir, "(linea 1, posicion 0)"
  lcd.print("Estas buenisimo, que guapo eres madre mia");
  delay(500);  //medio segundo
}

void loop() {
  //ciclo principal de recorrido del mensaje de un ladoa otro
  int i;  //variable para conteo del ciclo

  //por si quiero hacer un desplazamiento en pantalla hacia la derecha
  /* for(int i=0;i++){
     lcd.scrollDisplayRight();
     delay(500);
     }
     */
     
     //desplazamiento en pantalla hacia la izquierda
     for(int i=0;i<5;i++){
     lcd.scrollDisplayLeft();
     delay(500);    
     }
 
}
