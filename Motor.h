
#ifndef Motor_h
#define Motor_h

#include<Arduino.h>

class Motor {
	public:
		explicit Motor(pin_alimentador_delante);
		void begin();
	private:
		pin_alimentador_delante;
};

#endif




