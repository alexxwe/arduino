//pRACTICA 3 PULSADOR LED

const int boton=2;  //pin del pulsador
const int led=4;    //pin del led
  int valorpulsador;
  
void setup() {
  //inicializacion de los pin
  valorpulsador=0;
  pinMode(boton,INPUT); //pin 2 entrada
  pinMode(led,OUTPUT);  //pin 4 salida
  Serial.begin(9600);
}

void loop() {
  //if, condicional, si el pulsador esta HIGH, pulsado led en on
  valorpulsador=digitalRead(boton);
  Serial.print("El pulsador vale ");  //mostrar en pantalla(monitor serial)
  Serial.println(valorpulsador);
  delay(1000);
  if(valorpulsador==HIGH){
    
     digitalWrite(led,HIGH);
  }

  else{ //si no se cumple led en off
    
    digitalWrite(led,LOW);
  }
}
