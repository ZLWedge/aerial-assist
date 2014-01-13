#include "WPILib.h"
#include "CommandBase.h"

class Davros : public IterativeRobot {
private:
	Command *autonomousCommand;
	LiveWindow *lw;
	
	void RobotInit() {
		CommandBase::init();
		autonomousCommand = NULL;
		lw = LiveWindow::GetInstance();
		
		lw->AddActuator("Chassis", "Motor A", CommandBase::chassis->driveMotorA);
		lw->AddActuator("Chassis", "Motor B", CommandBase::chassis->driveMotorB);
		lw->AddActuator("Chassis", "Motor C", CommandBase::chassis->driveMotorC);
		lw->AddActuator("Chassis", "Motor D", CommandBase::chassis->driveMotorD);
	}
	
	void AutonomousInit() {
		//autonomousCommand->Start();
	}
	
	void AutonomousPeriodic() {
		Scheduler::GetInstance()->Run();
	}
	
	void TeleopInit() {
		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to 
		// continue until interrupted by another command, remove
		// this line or comment it out.
		autonomousCommand->Cancel();
	}
	
	void TeleopPeriodic() {
		Scheduler::GetInstance()->Run();
	}
	
	void TestPeriodic() {
		lw->Run();
	}
};

START_ROBOT_CLASS(Davros);

