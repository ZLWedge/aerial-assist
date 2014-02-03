#include "Catapult.h"
#include "../Robotmap.h"

Catapult::Catapult():Subsystem("Catapult"){
	releaseMotor = new Victor (RELEASE_MOTOR_PWM);
	winchMotor = new Victor (WINCH_MOTOR_PWM);
	qrLimitSwitch = new DigitalInput (QR_LIMIT_SWITCH);
	cataLimitSwitch = new DigitalInput (CATA_LIMIT_SWITCH);
}

Catapult::~Catapult() {
	delete winchMotor;
	delete releaseMotor;
	delete qrLimitSwitch;
	delete cataLimitSwitch;
}

void Catapult::release() {
	releaseMotor->Set(1.0);
	Wait(RELEASE_RELOAD);
	while(qrLimitSwitch->Get()==0){
		//Do nothing.
	}
	releaseMotor->Set(0.0);
}

void Catapult::winchReset() {
	winchMotor->Set(1.0);
	while(cataLimitSwitch->Get()==0){
		//Do nothing
	}
	winchMotor->Set(0.0);
}

void Catapult::cableSet() {
	winchMotor->Set(-1.0);
	Wait (0.5);
	winchMotor->Set(0.0);
}
