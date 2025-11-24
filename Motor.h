
#ifndef Motor_h
#define Motor_h

#include<Arduino.h>

class Motor {
	public:
		explicit Motor(pin_motor);
		void begin();
	private:
		pin_motor;
};

#endif




