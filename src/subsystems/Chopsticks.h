#ifndef Chopsticks_h
#define Chopsticks_h

#include <WPILib.h>

class Chopsticks: public Subsystem {
	public:
		Chopsticks();
		~Chopsticks();
		void spin(double speed);
		
	private:
		Victor* motor;
};

#endif
