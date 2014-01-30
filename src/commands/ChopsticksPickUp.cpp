#include "ChopsticksPickUp.h"
#include "../Robotmap.h"

ChopsticksPickUp::ChopsticksPickUp():CommandBase("ChopsticksPickUp"){
	Requires(chopsticks);
}

void ChopsticksPickUp::Initialize(){	
}

void ChopsticksPickUp::Execute(){
	chopsticks->spin(CHOPSTICKS_SPEED);
}

bool ChopsticksPickUp::IsFinished(){
	return false;
}

void ChopsticksPickUp::End(){
}

void ChopsticksPickUp::Interrupted(){
	chopsticks->spin (0.0);
}	
