void EstadoPush(){

int buton=digitalRead(15);  //lectura pin 15 pulsador(A1)
Serial.print(buton);  //escribe valor al puerto serial

//condicional
if(buton == HIGH){  // condional si esta pulsado ...

  digitalWrite(salida,HIGH);  //escribe en variable de salida
  //escribe en LCD
  lcd.setCursor(0,1);  //posicion, linea 1 posicion 0
  lcd.print("ON");
}
else{
  digitalWrite(salida,LOW);  //escribe en variable de salida
  //escribe en LCD
  lcd.setCursor(0,1);  //posicion
  lcd.print("OFF");  //texto
}


  
}
