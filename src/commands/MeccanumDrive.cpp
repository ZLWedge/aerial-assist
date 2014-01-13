#include "MeccanumDrive.h"
#include "../Robotmap.h"

MeccanumDrive::MeccanumDrive(){
	//Requires(chassis);
}

void MeccanumDrive::Initialize(){	
}

void MeccanumDrive::Execute(){
	//chassis->drive(oi->getJoyDrvX(),oi->getJoyDrvY(),oi->getJoyDrvZ(),oi->getJoyDrvThrottle());
}

bool MeccanumDrive::IsFinished(){
	return false;
}

void MeccanumDrive::End(){
}

void MeccanumDrive::Interrupted(){
}	
