//Aplicación1 LED RGB LDR

const int greenLEDPin=9;  //color verde Led
const int redLEDPin=10;  //color rojo Led
const int blueLEDPin=11;  //color azul Led

const int redSensorPin=A0;  //entrada LDR rojo
const int greenSensorPin=A1;  //entrada LDR verde
const int blueSensorPin=A2;  //entrada LDR azul

int redValue=0;  //
int greenValue=0;  //
int blueValue=0;  //

int redSensorValue=0;  //guarda valor LDR rojo
int greenSensorValue=0;  //guarda valor LDR verde
int blueSensorValue=0;  //guarda valor LDR azul

void setup() {
  Serial.begin(9600);  //monitor serie

  pinMode(greenLEDPin,OUTPUT);
  pinMode(redLEDPin,OUTPUT);
  pinMode(blueLEDPin,OUTPUT);
}

void loop() {

  //lecturas entradas analogicas LDR
  redSensorValue=analogRead(redSensorPin);
  delay(5);
  greenSensorValue=analogRead(greenSensorPin);
  delay(5);
  blueSensorValue=analogRead(blueSensorPin);

  //monitor serial

  Serial.print("Valor LDR color Rojo = ");
  Serial.println(redSensorValue);
  Serial.print("Valor LDR color Verde = ");
  Serial.println(greenSensorValue);
  Serial.print("Valor LDR color Azul = ");
  Serial.println(blueSensorValue);

  //mapeamos el valor por 4 y guardamos el resultado
  
  redValue=redSensorValue/4;
  greenValue=greenSensorValue/4;
  blueValue=blueSensorValue;

  //monitor serial
  Serial.print("Mapeo valores /t tojo");
  Serial.println(redValue);
  Serial.print("Mapeo valores /t verde");
  Serial.println(greenValue);
  Serial.print("Mapeo valores /t azul");
  Serial.println(blueValue);

  //escribimos el valor en las salidas digitales

  analogWrite(greenLEDPin,greenValue);
  analogWrite(redLEDPin,redValue);
  analogWrite(blueLEDPin,blueValue);  
}
