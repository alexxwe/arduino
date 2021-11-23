//Practica12B motor por RELE
//Motor  en ON cuando S1y S2 esten activos

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
}
