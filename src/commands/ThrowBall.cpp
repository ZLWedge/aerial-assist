#include "../subsystems/Catapult.h"
#include "../Robotmap.h"
#include "ThrowBall.h"


ThrowBall::ThrowBall():CommandBase("ThrowBall"){
	Requires(catapult);
}

void ThrowBall::Initialize(){	
}

void ThrowBall::Execute(){
	catapult->release();	
}

bool ThrowBall::IsFinished(){
	return false;
}

void ThrowBall::End(){
}

void ThrowBall::Interrupted(){
}	
