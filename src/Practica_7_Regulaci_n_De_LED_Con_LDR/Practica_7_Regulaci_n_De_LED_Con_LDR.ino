//PRÁCTICA7 REGULACIÓN DE LED CON LDR

int ledPin=11;//salida de PWM led
int LDRPin=A0;//entrada analógica

int intensity;
int bajo_LDR=50;//modificar según luminosidad(máx/min)
int alto_LDR=1024;
int LDR_value=0;

void setup() {
  pinMode(ledPin,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  LDR_value=analogRead(LDRPin);//Lectura del sensor

  intensity=map(LDR_value,bajo_LDR, alto_LDR,255,0);
  //Si sobre el LDR oscurece el led aumenta su luz

  analogWrite(ledPin,intensity);//7señal PWM al LED Pin11
  Serial.print("Valor analógico escrito= ");
  Serial.println(intensity);
/*Observar la lectura analógica para comprobar el fondo de escala (0->1024)*/

  Serial.print("Valor analógico leido= ");
  Serial.println(analogRead(LDRPin));
  delay(1000);//retardo 1 segundo

}
