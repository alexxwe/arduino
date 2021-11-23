
//Libreria servomotor
#include <Servo.h> // include Servo library 

//libreria LCD
#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

#define I2C_ADDR 0x27
LiquidCrystal_I2C lcd(I2C_ADDR,2,1,0,4,5,6,7);

// 180 horizontal MAX
Servo horizontal; // horizontal servo
int servoh = 180;   // 90;     // stand horizontal servo

int servohLimitHigh = 145;
int servohLimitLow = 65;

// 65 degrees MAX
Servo vertical;   // vertical servo 
int servov = 90;    //   45;     // stand vertical servo

int servovLimitHigh = 80;
int servovLimitLow = 25;


// LDR pin connections
//  name  = analogpin;
int ldrlt = 0; //LDR top left - BOTTOM LEFT    <--- BDG
int ldrrt = 1; //LDR top rigt - BOTTOM RIGHT 
int ldrld = 2; //LDR down left - TOP LEFT
int ldrrd = 3; //ldr down rigt - TOP RIGHT

void setup()
{
  Serial.begin(9600);
// servo connections
// name.attacht(pin);
  horizontal.attach(9);  //pin9 para motor horizontal 
  vertical.attach(10);  //pin 10 para control motor vertical
  horizontal.write(145);  
  vertical.write(45);
  delay(3000);

  //pantalla
  lcd.begin(16,2);  //inicializamos el display, 16 caracteres en 2 lineas
  
  lcd.setBacklightPin(3,POSITIVE);  //encender luz
  lcd.setBacklight(HIGH);
  lcd.clear();
  
  //delay(3000);
  //lcd.clear();
}

void loop() 
{
  int lt = analogRead(ldrlt); // top left
  int rt = analogRead(ldrrt); // top right
  int ld = analogRead(ldrld); // down left
  int rd = analogRead(ldrrd); // down rigt
  
  // int dtime = analogRead(4)/20; // read potentiometers  
  // int tol = analogRead(5)/4;
  int dtime = 10;
  int tol = 50;
  
  int avt = (lt + rt) / 2; // average value top
  int avd = (ld + rd) / 2; // average value down
  int avl = (lt + ld) / 2; // average value left
  int avr = (rt + rd) / 2; // average value right

  int dvert = avt - avd; // check the diffirence of up and down
  int dhoriz = avl - avr;// check the diffirence og left and rigt
  
  
  Serial.print(avt);
  Serial.print(" ");
  Serial.print(avd);
  Serial.print(" ");
  Serial.print(avl);
  Serial.print(" ");
  Serial.print(avr);
  Serial.print("   ");
  Serial.print(dtime);
  Serial.print("   ");
  Serial.print(tol);
  Serial.println(" ");
  
    
  if (-1*tol > dvert || dvert > tol) // check if the diffirence 
               //is in the tolerance else change vertical angle
  {
  if (avt > avd)
  {
    servov = ++servov;
     if (servov > servovLimitHigh) 
     { 
      servov = servovLimitHigh;
     }
  }
  else if (avt < avd)
  {
    servov= --servov;
    if (servov < servovLimitLow)
  {
    servov = servovLimitLow;
  }
  }
  vertical.write(servov);
  }
  
  if (-1*tol > dhoriz || dhoriz > tol) // check if the diffirence 
               //is in the tolerance else change horizontal angle
  {
  if (avl > avr)
  {
    servoh = --servoh;
    if (servoh < servohLimitLow)
    {
    servoh = servohLimitLow;
    }
  }
  else if (avl < avr)
  {
    servoh = ++servoh;
     if (servoh > servohLimitHigh)
     {
     servoh = servohLimitHigh;
     }
  }
  else if (avl = avr)
  {
    // nothing
  }
  horizontal.write(servoh);
  }
 
   delay(dtime);

   //PANTALLA
   
   // lcd.home();
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Horizontal= ");
    lcd.print(servoh);

    lcd.setCursor(0,1);
    lcd.print("Vertical= ");
    lcd.print(servov);
}
/*
  lcd.home();
  lcd.setCursor(0,0);  //posición 0 linea 0
  lcd.print("Vertical=");
  lcd.print(servov);

  lcd.setCursor(0,1); //posicion 0 de la linea 1
  lcd.print("Horizontal="); 
  lcd.print(servoh);
 */

/*   lcd.clear();
     lcd.setCursor(0,0);
     lcd.print("Horizontal: ");
     lcd.print(servoh);
     lcd.setCursor(0,1);
     lcd.print("Vertical: ");
     lcd.print(servov); */
