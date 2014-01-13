#include <math.h>

#include "Chassis.h"
#include "../Robotmap.h"

Chassis::Chassis():Subsystem("Chassis"){
    driveMotorA = new Victor(MOTOR_A_PWM);
    driveMotorB = new Victor(MOTOR_B_PWM);
    driveMotorC = new Victor(MOTOR_C_PWM);
    driveMotorD = new Victor(MOTOR_D_PWM);

}

Chassis::~Chassis() {
	delete driveMotorA;
	delete driveMotorB;
	delete driveMotorC;
	delete driveMotorD;
}

void Chassis::drive(double vX, double vY, double vZ, double throttle) {
	double vMotor[4];
	
	vMotor[0] = vX + vY + vZ;
	vMotor[1] = vX - vY + vZ;
	vMotor[2] = -vX - vY + vZ;
	vMotor[3] = -vX + vY + vZ;
	
	double vmax = 1.0;
	for(int i = 0; i < 4; ++i){
		if(abs(vMotor[i]) >vmax ) {
			vmax =abs (vMotor [i]);
		}
	}
	for (int i = 0; i < 4; ++i){
		vMotor[i] = vMotor[i]/vmax*throttle; 
	}
	driveMotorA->Set(vMotor[MOTOR_A_PWM]);
    driveMotorB->Set(vMotor[MOTOR_B_PWM]);
    driveMotorC->Set(vMotor[MOTOR_C_PWM]);
    driveMotorD->Set(vMotor[MOTOR_D_PWM]);
}



