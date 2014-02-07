#include "SpeedEncoder.h"


SpeedEncoder::SpeedEncoder(int channelA, int channelB, bool reverse)
	:Encoder(channelA, channelB, reverse){
}

SpeedEncoder::~SpeedEncoder(){
}

double SpeedEncoder:: PIDGet(){
	return GetRate();
}
