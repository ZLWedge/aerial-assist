#include "OI.h"

OI::OI() {
	// Process operator interface input here.
	joyDrv = new Joystick(1);
}

Joystick* OI::getJoyDrv() {
	return joyDrv;
}
