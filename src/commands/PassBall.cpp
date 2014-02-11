#include "../subsystems/Catapult.h"
#include "../Robotmap.h"
#include "PassBall.h"


PassBall::PassBall():CommandBase("PassBall"){
	Requires(catapult);
}

void PassBall::Initialize(){	
}

void PassBall::Execute(){
	catapult->passBall();
}

bool PassBall::IsFinished(){
	return false;
}

void PassBall::End(){
}

void PassBall::Interrupted(){
}	
