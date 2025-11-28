
/*

ARDUINO.INO
PROYECTO: Alimentador en X
DESARROLADORES: Gabriel Lopez & Ismael San Bartolomé

*/

//Definimos los pines de los elementos a utilizar de forma que si luego se conecta a otro pin solo haría falta realizar el cambio en el apartado siguiente.
//Definimos los etados de estos que tomaran valores 0 o 1.
#include <arduino.h>

void loop()
{
    
}

int pin_alimentador_delante=2, pin_alimentador_atras=3, pin_marcha=4, pin_pieza_entrada=5, pin_pieza_salida=6, pin_motor_delante=11, pin_motor_detras=12, pin_electroiman=13;
bool estado_alimentador_delante, estado_alimentador_atras, estado_marcha,estado_pieza_entrada, estado_pieza_salida, estado_motor_delante, esatdo_motor_detras, estado_electroiman;
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
  
  if (posicion_inicial_trabajo(pin_alimentador_atras)==1){
    Serial.println("Arranque seguro: Activado:");
  }
}

int posicion_inicial_trabajo(int pin_alimentador_atras){
    estado_alimentador_atras=digitalRead(pin_alimentador_atras);
    if (estado_alimentador_atras==0){
        Serial.println("Arranque seguro: Desactivado");
        Serial.println("Preparando motor");
    while(estado_alimentador_atras==0){
        digitalWrite(11,1);
        digitalWrite(13,0);
        estado_alimentador_atras=digitalRead(pin_alimentador_atras);
    }
    digitalWrite(11,0);
    digitalWrite(13,1);
    delay(500);
    digitalWrite(13,0);
    return 1;
    }
    else{
        return 1;
    }
;
}

void lecturas_estados_pines(int pin_alimentador_delante,int pin_alimentador_atras,int pin_marcha,int pin_pieza_entrada,int pin_pieza_salida){
  estado_alimentador_delante=digitalRead(pin_alimentador_delante); 
  estado_alimentador_atras=digitalRead(pin_alimentador_atras); 
  estado_marcha=digitalRead(pin_marcha); 
  estado_pieza_entrada=digitalRead(pin_pieza_entrada);
  estado_pieza_salida=digitalRead(pin_pieza_salida);
}

void movimiento_adelante_motor(){
   //Suponemos las conciciones iniciales
    digitalWrite(pin_motor_delante,1);
    while (estado_alimentador_delante==0){
      digitalRead(pin_alimentador_delante);
    }
    digitalWrite(pin_motor_delante,0);
    
}
void movimiento_atras_motor(){
   //Suponemos las conciciones iniciales
    digitalWrite(pin_motor_atras,1);
    while (estado_alimentador_atras==0){
      digitalRead(pin_alimentador_atras);
    }
    digitalWrite(pin_motor_atras,0);
    
}
void electroiman(int estado){
  digitalWrite(pin_electroiman,estado);
}

void loop()
{
  //Lecturas de los estados de los botones (Valores toman 0 o 1)
  void lecturas_pines(pin_alimentador_delante,pin_alimentador_atras,pin_marcha,pin_pieza_entrada,pin_pieza_salida);
  
  electroiman(0);

  if(estado_alimentador_atras==true&&estado_marcha==true&&estado_electroiman==true){
    movimiento_adelante_motor();
  }

  electroiman(1);
  
  if(estado_alimentador_delante==true&&estado_marcha==true&&estado_electroiman==true){
    movimiento_atras_motor();
  }

  }