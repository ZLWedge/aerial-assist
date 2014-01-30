#include "ChopsticksPutDown.h"
#include "../Robotmap.h"

ChopsticksPutDown::ChopsticksPutDown():CommandBase("ChopsticksPutDown"){
	Requires(chopsticks);
}

void ChopsticksPutDown::Initialize(){	
}

void ChopsticksPutDown::Execute(){
	chopsticks->spin(-CHOPSTICKS_SPEED);
}

bool ChopsticksPutDown::IsFinished(){
	return false;
}

void ChopsticksPutDown::End(){
}

void ChopsticksPutDown::Interrupted(){
	chopsticks->spin (0.0);
}	
