#include "Catapult.h"
#include "../Robotmap.h"

Catapult::Catapult():Subsystem("Catapult"){
	releaseMotor = new Victor (RELEASE_MOTOR_PWM);
	winchMotor = new Victor (WINCH_MOTOR_PWM);
}

Catapult::~Catapult() {
	delete winchMotor;
	delete releaseMotor;
}

void Catapult::Release() {
	releaseMotor->Set(1.0);
}

void Catapult::Winch (double speed) {
	winchMotor->Set(speed);
}
