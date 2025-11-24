
#include<Motor.h>

Motor::Motor(pin_motor) : _pin (pin_motor);

void Motor::begin(){
  pinMode(_pin, OUTPUT);
}
