#include "Catapult.h"
#include "../Robotmap.h"

Catapult::Catapult():Subsystem("Catapult"){
	releaseMotor = new Victor (RELEASE_MOTOR_PWM);
	winchMotor = new Victor (WINCH_MOTOR_PWM);
	qrFiringLimitSwitch = new DigitalInput (QR_FIRING_LIMIT_SWITCH);
	qrPassingLimitSwitch = new DigitalInput (QR_PASSING_LIMIT_SWITCH);
	cataLimitSwitch = new DigitalInput (CATA_LIMIT_SWITCH);
}

Catapult::~Catapult() {
	delete winchMotor;
	delete releaseMotor;
	delete qrFiringLimitSwitch;
	delete qrPassingLimitSwitch;
	delete cataLimitSwitch;
}

void Catapult::release() {
	cableSet();
	qrOpen();
	Wait (2.0);
	qrClose();
	winchReset();
}

void Catapult::passBall() {
	qrOpen();
	cableSet();
	Wait (2.0);
	qrClose();
	winchReset();
}

void Catapult::winchReset() {
	winchMotor->Set(WINCH_SPEED);
	while(cataLimitSwitch->Get()==1){
		//Do nothing
	}
	winchMotor->Set(0.0);
}

void Catapult::cableSet() {
	winchMotor->Set(-WINCH_SPEED);
	Wait (0.5);
	winchMotor->Set(0.0);
}

void Catapult::qrOpen() {
	releaseMotor->Set(-1.0);
    while(qrPassingLimitSwitch->Get()==1){
    	//Do nothing.
    }
    releaseMotor->Set(0.0);
}

 void Catapult::qrClose() {
	releaseMotor->Set(-1.0);
    while(qrFiringLimitSwitch->Get()==1){
    	//Do nothing.
    }
    releaseMotor->Set(0.0);
}   
