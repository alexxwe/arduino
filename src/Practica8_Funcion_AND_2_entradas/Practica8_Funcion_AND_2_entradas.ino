//Practica8 Funcion AND 2 entradas

int A=7;  //variable de entrada del pin de la placa
int B=2;
int led=5; //variable de entrada para el pin de salida hacia el Led

int valorA=0;  //variable para guardar el valor de a
int valorB=0; 
int resultado=0;  //variable para guardar el valor del resultado del LED

void setup() {
  //definir pin de entrada y de salida
   pinMode(A,INPUT);  //entrada
   pinMode(B,INPUT);  //entrada
   pinMode(led,OUTPUT);  //salida

    serial.begin(9600);  //activar Monitor Serial
}

void loop() {
  valorA= digitalRead(A);  //lectura de la entrada A y guardamos su valor
  valorB= digitalRead(B);  //lectura de la entrada B y guardamos su valor

 resultado= (valorA && valorB);  //funcion logica AND y guardamos el resultado

digitalWrite(led,resultado);  //escribe el valor de resultado en el pin led

//mostrar variables y resultado en el Monitor Serial

 Serial.print("valorA = ");
 serial.println(valorA);
}
