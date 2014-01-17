#include "CatchBall.h"
#include "../subsystems/Chassis.h"
#include "../Robotmap.h"

#include <cstdlib>


CatchBall::CatchBall(): CommandBase("CatchBall"){
	Requires(chassis);
}

void CatchBall::Initialize(){
}

void CatchBall::Execute(){
	//this section opens a TCP connection to the beagle bone
	TCPConnector* connector = new TCPConnector();
	TCPStream* stream = connector->connect(BALL_VISION_IP,BALL_VISION_PORT);
	
	if(stream){
		SmartDashboard::PutString("Ball Vision IP", BALL_VISION_IP);
		SmartDashboard::PutNumber("Ball Vision Port", BALL_VISION_PORT);
		
		char line[256];
		char* lastChar = NULL;
		
		stream->send("L", 1);
		stream->receive(line, sizeof(line));
		//this code gets the data from the beagle bone and converts into the following 
		// values so that the robot tracks and follows the ball
		double x = strtod(line, &lastChar);
		if (x <= 1.0 && x >= -1.0) {
			double y = strtod(lastChar, &lastChar);
			double width = strtod(lastChar, NULL);
			double throttle =1.0-0.5*width;
			chassis->drive(-y,-x,0.0,throttle);
		}
		delete stream;
	}
	if (connector) {
		delete connector;
	}
}

bool CatchBall::IsFinished(){
	return false; 
}

void CatchBall::End(){
	
}

void CatchBall::Interrupted(){
	
}


