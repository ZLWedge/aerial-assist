#include <math.h>

#include "Chassis.h"
#include "../Robotmap.h"
#include "../commands/MeccanumDrive.h"

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
	
	vMotor[0] = vX - vY - vZ;
	vMotor[1] = vX + vY - vZ;
	vMotor[2] = -vX + vY - vZ;
	vMotor[3] = -vX - vY - vZ;
	
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
    
    // Put the values onto the SmartDashboard
    SmartDashboard::PutNumber("Motor A", vMotor[0]);
    SmartDashboard::PutNumber("Motor B", vMotor[1]);
    SmartDashboard::PutNumber("Motor C", vMotor[2]);
    SmartDashboard::PutNumber("Motor D", vMotor[3]);

}

void Chassis::InitDefaultCommand() {
    SetDefaultCommand(new MeccanumDrive());
}
    

