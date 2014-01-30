#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI {
private:
	Joystick* joyDrv;
	Button* catchButton;
	Button* chopsticksUpButton;
	Button* chopsticksDownButton;
	double applyDeadZone(double,double);

public:
	OI();
	
	Joystick* getJoyDrv();
	double getJoyDrvX();
	double getJoyDrvY();
	double getJoyDrvZ();
	double getJoyDrvThrottle();
};

#endif
