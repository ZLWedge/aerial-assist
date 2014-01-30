#include "Chopsticks.h"
#include "../Robotmap.h"

Chopsticks::Chopsticks():Subsystem("Chopsticks"){
    motor = new Victor (CHOPSTICK_MOTOR_PWM);

}

Chopsticks::~Chopsticks() {
	delete motor;
}

void Chopsticks::spin(double speed) {
	motor->Set(speed); 
	
}


    

