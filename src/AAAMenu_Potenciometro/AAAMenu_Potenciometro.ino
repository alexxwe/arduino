//Menu Potenciometro

#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>


#define I2C_ADDR 0x27  //ese 0x significa que es hexadecimal, no decimal

LiquidCrystal_I2C lcd(I2C_ADDR,2,1,0,4,5,6,7);

//Incluir las rutinas de las pestañas

int puntero;  //puntero para el menu de switch
int salida;  //conexion del LED y buzzer
int fotocelula;  //conexion fotocelula
String TextoCase;  //cadena de caracteres del texto que vamos a poner en pantalla

//salida
const int LED= 2;  //pin de conexion del interruptor
//interruptor
const int push= 3;  //pin del pulsador

//inicialización de variables
int push_lee=0;  //almaceno el valor de la lectura del pulsador
int estadoLED=0;  //almaceno estado del LED
int estadoAnterior=0;  //almaceno el estado anterior del interruptor

//llamada a las rutinas
void AnuncioFinal();
void EstadoPush();
void Interruptor();
void Posicion();

void setup() {
//activar el modulo LCD y encendido de la luz
lcd.begin(16,2);
lcd.setBacklightPin(3,POSITIVE);
lcd.setBacklight(HIGH);

//inicializamos las variables
//LED Verde
pinMode(LED,OUTPUT);  //salida
//interruptor
pinMode(push,INPUT);  //entrada

//LED Rojo
pinMode(13,OUTPUT);  
//buzzer
pinMode(6,OUTPUT);

digitalWrite(15,HIGH);

Serial.begin(9600);  //monitor serial
}
//------Función ciclica

void loop() {
//puntero por mapeo, Potenciómetro
puntero=analogRead(0);  //lee A0 y guarda valor
puntero=map(puntero,0,1023,0,4);  //relacionamos las tensiones con el 0,1,2,3 y 4


//-----SWITCH-----
switch(puntero){
  case 0:  //LED Rojo Pulsador
  TextoCase="LED Verde";  //Texto LCD
  Posicion();  //llamada a la rutina
  Interruptor();  //llamada a la rutina, submenu

  break;
  case 1:
  TextoCase=("Buzzer"); //texto en la primera linea
  Posicion();
  salida=6;  //pin de conexion del buzzer
  EstadoPush();  //llamada a la rutina, submenu
  break;
  case 2:
  TextoCase="Fotocelula";  //texto1 linea LCD
  Posicion();
  fotocelula=analogRead(2);  //lectura del pin A2
  //valor en pantalla LCD
  lcd.setCursor(0,1);  //asignamos la posicion
  
  lcd.print(fotocelula);  //valor de la fotocelula
  break;
  case 3:
  TextoCase="Menu en Arbol";  //Texto 1 linea LCD
  Posicion();
  AnuncioFinal();  //lamada a la rutina
  break;
}
delay(300);
lcd.clear();
}
