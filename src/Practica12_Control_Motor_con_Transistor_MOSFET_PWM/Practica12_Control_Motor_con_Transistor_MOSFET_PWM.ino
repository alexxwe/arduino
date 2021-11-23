//Practica2 Control Motor con transistor MOSFET PWM

const int analogPin=A0;  //Entrada analogica del potenciometro
const int controlOutPin=3;  //pin de control de motor

int potValor=0;  //guarda valor

int outputValor=0;  //valor salida PWM

void setup() {
  Serial.begin(9600);  //monitor
}

void loop() {
  //leer valor
  potValor=analogRead(analogPin);

  //mapeo

  outputValor=map(potValor,0  ,1023,0,255);  //correlacion de escalas

  analogWrite(controlOutPin,outputValor);  //escribimos valor de salida

  //monitor

  Serial.print("Potenciometro = ");
  Serial.println(potValor);
  Serial.print("Mapeo PWM = ");
  Serial.println(outputValor);
}
