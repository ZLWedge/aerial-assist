#ifndef Catapult_h
#define Catapult_h

#include <WPILib.h>

class Catapult: public Subsystem {
	public:
		Catapult();
		~Catapult();
		void Release ();
		void Winch (double speed);
		
		private:
		Victor* releaseMotor;
		Victor* winchMotor;
		
};
#endif
