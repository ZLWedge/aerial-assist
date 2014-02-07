#include <math.h>

#include "Chassis.h"
#include "../Robotmap.h"
#include "../commands/MeccanumDrive.h"
#include "../SpeedEncoder.h"

Chassis::Chassis():Subsystem("Chassis"){
    driveMotorA = new Victor(MOTOR_A_PWM);
    driveMotorB = new Victor(MOTOR_B_PWM);
    driveMotorC = new Victor(MOTOR_C_PWM);
    driveMotorD = new Victor(MOTOR_D_PWM);
    
    encoderA = new SpeedEncoder(ENCODER_A_1, ENCODER_A_2, ENCODER_A_REV);
	encoderB = new SpeedEncoder(ENCODER_B_1, ENCODER_B_2, ENCODER_B_REV); 
	encoderC = new SpeedEncoder(ENCODER_C_1, ENCODER_C_2, ENCODER_C_REV); 
	encoderD = new SpeedEncoder(ENCODER_D_1, ENCODER_D_2, ENCODER_D_REV);
	
	encoderA->Reset();
    encoderB->Reset();
    encoderC->Reset();
    encoderD->Reset();
    
    encoderA->Start();
    encoderB->Start();
    encoderC->Start();
    encoderD->Start();
	
    pidA = new PIDController(KP, KI, KD, KFF, encoderA, driveMotorA);
    pidB = new PIDController(KP, KI, KD, KFF, encoderB, driveMotorB);
    pidC = new PIDController(KP, KI, KD, KFF, encoderC, driveMotorC);
    pidD = new PIDController(KP, KI, KD, KFF, encoderD, driveMotorD);
    

}

Chassis::~Chassis() {
	delete driveMotorA;
	delete driveMotorB;
	delete driveMotorC;
	delete driveMotorD;
	
	delete pidA;
	delete pidB;
	delete pidC;
	delete pidD;
	
	delete encoderA;
	delete encoderB;
	delete encoderC;
	delete encoderD;
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
    SmartDashboard::PutNumber("EncoderA(counts)", encoderA->Get());
	SmartDashboard::PutNumber("EncoderB(counts)", encoderB->Get());
	SmartDashboard::PutNumber("EncoderC(counts)", encoderC->Get());
	SmartDashboard::PutNumber("EncoderD(counts)", encoderD->Get());
	SmartDashboard::PutNumber("EncoderA(speed)", encoderA->GetRate());
	SmartDashboard::PutNumber("EncoderB(speed)", encoderB->GetRate());
	SmartDashboard::PutNumber("EncoderC(speed)", encoderC->GetRate());
	SmartDashboard::PutNumber("EncoderD(speed)", encoderD->GetRate());

}

void Chassis::InitDefaultCommand() {
    SetDefaultCommand(new MeccanumDrive());
}
    
