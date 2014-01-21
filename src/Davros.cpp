#include "CommandBase.h"

#include "Davros.h"

void Davros::RobotInit() {
    CommandBase::init();
    autonomousCommand = NULL;
    lw = LiveWindow::GetInstance();
    
    lw->AddActuator("Chassis", "Motor A", CommandBase::chassis->driveMotorA);
    lw->AddActuator("Chassis", "Motor B", CommandBase::chassis->driveMotorB);
    lw->AddActuator("Chassis", "Motor C", CommandBase::chassis->driveMotorC);
    lw->AddActuator("Chassis", "Motor D", CommandBase::chassis->driveMotorD);
    
    SmartDashboard::PutData(Scheduler::GetInstance());
    SmartDashboard::PutData(CommandBase::chassis);
}

void Davros::AutonomousInit() {
    //autonomousCommand->Start();
}

void Davros::AutonomousPeriodic() {
    Scheduler::GetInstance()->Run();
}

void Davros::TeleopInit() {
    // This makes sure that the autonomous stops running when
    // teleop starts running. If you want the autonomous to 
    // continue until interrupted by another command, remove
    // this line or comment it out.
    //autonomousCommand->Cancel();
}

void Davros::TeleopPeriodic() {
    Scheduler::GetInstance()->Run();
}

void Davros::TestPeriodic() {
    lw->Run();
}

START_ROBOT_CLASS(Davros);

