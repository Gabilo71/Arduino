
/*

ARDUINO.INO
PROYECTO: Alimentador en X
DESARROLADORES: Gabriel Lopez & Ismael San Bartolomé

*/

//Definimos los pines de los elementos a utilizar de forma que si luego se conecta a otro pin solo haría falta realizar el cambio en el apartado siguiente.
//Definimos los etados de estos que tomaran valores 0 o 1.
//#include <arduino.h>

int pin_alimentador_delante=2, pin_alimentador_atras=3, pin_marcha=4, pin_pieza_entrada=5, pin_pieza_salida=6, pin_motor_delante=11, pin_motor_detras=12, pin_electroiman=13;
bool estado_alimentador_delante, estado_alimentador_atras, estado_marcha,estado_pieza_entrada, estado_pieza_salida, estado_motor_delante, esatdo_motor_detras, estado_electroiman;
int electroiman_con_pieza;
bool estado;

void setup()
{
  Serial.begin(9600);

  //Entradas del sistema
  pinMode(pin_alimentador_delante,INPUT);
  pinMode(pin_alimentador_atras,INPUT);
  pinMode(pin_marcha,INPUT);
  pinMode(pin_pieza_entrada,INPUT);
  pinMode(pin_pieza_salida,INPUT);

  //Salidas del sistema
  pinMode(pin_motor_delante,OUTPUT);
  pinMode(pin_motor_detras,OUTPUT);
  pinMode(pin_electroiman,OUTPUT);
  
  if (posicion_inicial_trabajo(pin_alimentador_atras)==1){
    Serial.println("Arranque seguro: Activado");
  }
}

int posicion_inicial_trabajo(int pin_alimentador_atras){
    lecturas_estados_pines();
    if (estado_alimentador_atras==0){
        Serial.println("Arranque seguro: Desactivado");
        Serial.println("Preparando motor");
    while(estado_alimentador_delante==0){
      lecturas_estados_pines();
        digitalWrite(pin_motor_delante,1);
        electroiman(0);
        
    }
    digitalWrite(pin_motor_delante,0);
    /*electroiman(1); //Esto de aqui hay que verlo
    delay(5000);
    electroiman(0);
    */
    return 1;
    }
    else{
        return 1;
    }

}

void lecturas_estados_pines(){
  estado_alimentador_delante=digitalRead(pin_alimentador_delante); 
  estado_alimentador_atras=digitalRead(pin_alimentador_atras); 
  estado_marcha=digitalRead(pin_marcha); 
  estado_pieza_entrada=digitalRead(pin_pieza_entrada);
  estado_pieza_salida=digitalRead(pin_pieza_salida);
}

void movimiento_adelante_motor(){
    Serial.println("Descargando pieza");
    electroiman(0);
    delay(5000);
    Serial.println("Apilador descargado");

    Serial.println("Volviendo a posicion de carga");

    while (estado_alimentador_delante==0){
      lecturas_estados_pines();
      digitalWrite(pin_motor_delante,1);
    }
    digitalWrite(pin_motor_delante,0);
    Serial.println("Preparado para carga");
}
void movimiento_atras_motor(){
    
    Serial.println("Cargando pieza");
    electroiman(1);
    delay(5000);
    Serial.println("Apilador cargado");

    Serial.println("Transportando");

    while (estado_alimentador_atras==0){
      lecturas_estados_pines();
      digitalWrite(pin_motor_detras,1);
    }
    digitalWrite(pin_motor_detras,0);
    Serial.println("Preparado para descarga");
}

void electroiman(int estado){
  digitalWrite(pin_electroiman,estado);
}

void loop()
{
  //Lecturas de los estados de los botones (Valores toman 0 o 1)
  lecturas_estados_pines();
  
  movimiento_atras_motor();

  movimiento_adelante_motor();

  /*if(estado_alimentador_atras==true&&estado_marcha==true&&estado_electroiman==true){
    movimiento_adelante_motor();
  }


  
  if(estado_alimentador_delante==true&&estado_marcha==true&&estado_electroiman==true){
    movimiento_atras_motor();
  }
*/
  }
