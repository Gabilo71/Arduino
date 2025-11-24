
#include<Motor.h>

Motor::Motor(pin_alimentador_delante) : _pin (pin_alimentador_delante);

void Motor::begin(){
  pinMode(_pin, OUTPUT);
}
