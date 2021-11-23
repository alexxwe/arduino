//PRACTICA5 SALIDA PWM

const int analogPin=A0;//entrada analógica 0-1023
const int analogOutPin=3;//salida de señal PWM

int potValor=0;//guarda valor del potenciómetro
int outputValor=0;//valor de señal de salida pwm


void setup() {
  Serial.begin(9600);//monitor plotter

}

void loop() {
  //leer el valor del potenciómetro 0-1023 0-5Vcc
  potValor=analogRead(analogPin);//lectura pin AO

  //mapeo para obtener la señal de salida PWM 0-0 5Vc-1023

  outputValor=map(potValor,0,1023,0,255);

  //asignamos el valor cambiado a pin3 PWM

  analogWrite(analogOutPin,outputValor);//escribe en la salida Pin3 el valor PWM

  //estos valores los escribe en el monitor

  Serial.print("Potenciómetro = ");
  Serial.println(potValor);
  Serial.print("mapeo PWM");
  Serial.println(outputValor);

  delay(100);

}
