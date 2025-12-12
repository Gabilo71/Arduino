void posicion_inicial(){
  Serial.println("Homing inicial: buscando posición atrás...");
  moverAtras();
  while (digitalRead(FC_Trasero) == HIGH);  // espera a que llegue al final
  detenerMotor();
  Serial.println("Posicionado en atrás");
}
