#ifndef Catapult_h
#define Catapult_h

#include <WPILib.h>

class Catapult: public Subsystem {
	public:
		Catapult();
		~Catapult();
		void release ();
		void winchReset ();
		void cableSet ();
		
	private:
		Victor* releaseMotor;
		Victor* winchMotor;
		DigitalInput* qrLimitSwitch;
		DigitalInput* cataLimitSwitch;
};
#endif
