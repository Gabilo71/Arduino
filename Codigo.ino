
/*

ARDUINO.INO
PROYECTO: Alimentador en X
DESARROLADORES: Gabriel Lopez & Ismael San Bartolomé

*/

//Definimos los pines de los elementos a utilizar de forma que si luego se conecta a otro pin solo haría falta realizar el cambio en el apartado siguiente.
//Definimos los etados de estos que tomaran valores 0 o 1.

int pin_alimentador_delante=2, pin_alimentador_atras=3, pin_marcha=4, pin_pieza_entrada=5, pin_pieza_salida=6, pin_motor_delante=11, pin_motor_detras=12, pin_electroiman=13;
int estado_alimentador_delante, estado_alimentador_atras, estado_marcha,estado_pieza_entrada, estado_pieza_salida, estado_motor_delante, esatdo_motor_detras, estado_electroiman;
int electroiman_con_pieza;
bool estado;
void setup()
{
  //Entradas del sistema
  pinMode(pin_alimentador_delante,INPUT);
  pinMode(pin_alimentador_atras,INPUT);
  pinMode(pin_pieza_marcha,INPUT);
  pinMode(pin_pieza_entrada,INPUT);
  pinMode(pin_salida,INPUT);

  //Salidas del sistema
  pinMode(pin_motor_delante,OUTPUT);
  pinMode(pin_motor_detras,OUTPUT);
  pinMode(pin_electroiman,OUTPUT);
}

void loop()
{
  //Lecturas de los estados de los botones (Valores toman 0 o 1)
  estado_alimentador_delante=digitalRead(pin_alimentador_delante); 
  estado_alimentador_atras=digitalRead(3); 
  estado_marcha=digitalRead(4); 
  estado_pieza_entrada=digitalRead(5);
  estado_pieza_salida=digitalRead(6);

  //Condición para que el motor viaje hacia delante. Interruptores encendidos: entrada, marcha, 
  
  if (estado_marcha==1 && estado_pieza_entrada==1 && estado_alimentador_delante==0){
    //Suponemos las conciciones iniciales
    digitalWrite(pin_motor_detras,0);
    digitalWrite(pin_electroiman,0);

    //Enecendemos el motor
    digitalWrite(pin_motor_delante,1);
    while (estado_alimentador_delante==0){
    }
    digitalWrite(pin_motor_delante,0);
    digitalWrite(pin_electroiman,1);
    electroiman_con_pieza=1;
  }
    else if (estado_pieza_salida==0 && electroiman_con_pieza==1 && estado_alimentador_atras==0) {  
      //Condiciones iniciales
    digitalWrite(pin_electroiman,1);
    digitalWrite(pin_motor_delante,0);
      //Delay para segurasrse que el electroimán coge la pieza
    delay(1000);

      
    digitalWrite(pin_motor_detras,1);
    while (estado_alimentador_atras==0){
    }
    digitalWrite(pin_motor_detras,0);
    digitalWrite(pin_electroiman,0):
    }
  }

