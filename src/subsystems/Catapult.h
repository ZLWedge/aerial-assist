#ifndef Catapult_h
#define Catapult_h

#include <WPILib.h>

class Catapult: public Subsystem {
	public:
		Catapult();
		~Catapult();
		void release ();
		void passBall();
		
		
	private:
		Victor* releaseMotor;
		Victor* winchMotor;
		DigitalInput* qrFiringLimitSwitch;
		DigitalInput* qrPassingLimitSwitch;
		DigitalInput* cataLimitSwitch;
		
		void winchReset ();
		void cableSet ();
		void qrOpen ();
		void qrClose ();
};
#endif
