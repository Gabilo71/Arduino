void moverAdelante(){
  digitalWrite(Motor_RetroA, HIGH);
  digitalWrite(Motor_RetroB, LOW);
  digitalWrite(Motor_AvanceA, HIGH);
  digitalWrite(Motor_AvanceB, LOW);
}

void moverAtras(){
  digitalWrite(Motor_AvanceA, LOW);
  digitalWrite(Motor_AvanceB, HIGH);
  digitalWrite(Motor_RetroA, LOW);
  digitalWrite(Motor_RetroB, HIGH);
}

void detenerMotor(){
  digitalWrite(Motor_AvanceA, LOW);
  digitalWrite(Motor_AvanceB, HIGH);
  digitalWrite(Motor_RetroA, HIGH);
  digitalWrite(Motor_RetroB, LOW);
}
