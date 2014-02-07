#ifndef SpeedEncoder_h
#define SpeedEncoder_h

#include <WPILib.h>
#include "subsystems/Chassis.h"

class SpeedEncoder: public Encoder{
	public:
		SpeedEncoder(int, int, bool);
		~SpeedEncoder();
		double PIDGet();
};

#endif
