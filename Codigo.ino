int ali_delante, ali_atras, marcha, entrada, salida, motor_delante, motor_detras, electroiman;
bool estado;
void setup()
{
  //Entradas del sisitema
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(4,INPUT);
  pinMode(5,INPUT);
  pinMode(6,INPUT);

  //Salidas del sistema
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
}

void loop()
{
  ali_delante=digitalRead(2); // Alimentador en posición delantera
  ali_atras=digitalRead(3); // Alimentador en posición trasera
  marcha=digitalRead(4); // Marcha del proceso
  entrada=digitalRead(5); // Piezas en la entrada
  salida=digitalRead(6); // Piezas en la salida
  if (entrada==1 && marcha==1 && ali_delante==0){
    digitalWrite(12,0);
    digitalWrite(13,0);
    digitalWrite(11,1);
    while (ali_delante==0);
    digitalWrite(11,0);
  }
    else if (entrada==1 && salida==0 && ali_delante==1) {  
    digitalWrite(13,1);
    digitalWrite(11,0);
    delay(1000);
    digitalWrite(12,1);
    while (ali_atras==0);
    digitalWrite(12,0);
    }
  }

