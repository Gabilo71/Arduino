int alimentador_delante=2, alimentador_atras=3, marcha=4, entrada=5, salida=6, motor_delante=11, motor_detras=12, electroiman=13;
bool estado;
void setup()
{
  //Entradas del sistema
  pinMode(alimentador_delante,INPUT);
  pinMode(alimentador_atras,INPUT);
  pinMode(marcha,INPUT);
  pinMode(entrada,INPUT);
  pinMode(salida,INPUT);

  //Salidas del sistema
  pinMode(motor_delante,OUTPUT);
  pinMode(motor_detras,OUTPUT);
  pinMode(electroiman,OUTPUT);
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

