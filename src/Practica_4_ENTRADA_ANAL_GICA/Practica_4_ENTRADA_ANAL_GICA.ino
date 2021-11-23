//PRACTICA4 ENTRADA ANALÓGICA carga descarga de condensador

int sensorPin=A5;//entrada analógica
int sensorValue=0;//variable para gaurdar el valor de la entrada A5


void setup() {

  Serial.begin(9600);//consola-monitor serie y serial plotter

}

void loop() {

  sensorValue= analogRead(sensorPin);
  Serial.println(sensorValue);
  delay(1000);

}
