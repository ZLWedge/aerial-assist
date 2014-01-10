#include <math.h>

#include "Chassis.h"

Chassis::Chassis():Subsystem("Chassis"){
    driveMotorA = new Victor(1);
    driveMotorB = new Victor(2);
    driveMotorC = new Victor(3);
    driveMotorD = new Victor(4);

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
	driveMotorA->Set(vMotor[0]);
    driveMotorB->Set(vMotor[1]);
    driveMotorC->Set(vMotor[2]);
    driveMotorD->Set(vMotor[3]);
}



