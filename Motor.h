
#ifndef Motor_h
#define Motor_h

#include<Arduino.h>

class Motor {
	public:
		explicit Motor(int pin_motor);
		void begin();
	private:
		int pin_motor;
};

#endif




