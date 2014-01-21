#include "CommandBase.h"

#include "Davros.h"
#include "Robotmap.h"

Davros::Davros(): gyro(new Gyro(GYRO_PORT)) {
}

void Davros::RobotInit() {
    CommandBase::init();
    autonomousCommand = NULL;
    //gyro = new Gyro(GYRO_PORT);
    lw = LiveWindow::GetInstance();
    
    SmartDashboard::PutData(Scheduler::GetInstance());
    SmartDashboard::PutData(CommandBase::chassis);
}

void Davros::AutonomousInit() {
    //autonomousCommand->Start();
    gyro->Reset();
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
    gyro->Reset();
}

void Davros::TeleopPeriodic() {
    Scheduler::GetInstance()->Run();
    SmartDashboard::PutNumber("Gyro(deg)", gyro->GetAngle());
}

void Davros::TestPeriodic() {
    lw->Run();
}

START_ROBOT_CLASS(Davros);

