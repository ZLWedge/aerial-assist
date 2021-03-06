#include "CommandBase.h"
#include "Commands/Scheduler.h"

CommandBase::CommandBase(const char *name) : Command(name) {
}

CommandBase::CommandBase() : Command() {
}

// Initialize a single static instance of all of your subsystems to NULL
Chassis* CommandBase::chassis = NULL;
Chopsticks* CommandBase::chopsticks = NULL;
OI* CommandBase::oi = NULL;
Catapult* CommandBase::catapult = NULL;

void CommandBase::init() {
    // Create a single static instance of all of your subsystems. The following
	// line should be repeated for each subsystem in the project.
	chassis = new Chassis();
	chopsticks = new Chopsticks();
	oi = new OI();
	catapult = new Catapult();
}
