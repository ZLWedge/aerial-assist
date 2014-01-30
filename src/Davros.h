#ifndef Davros_h
#define Davros_h

#include "WPILib.h"

class Davros : public IterativeRobot {
    private:
        Command *autonomousCommand;
        LiveWindow *lw;
        Gyro *gyro;
        Encoder *encoderA, *encoderB, *encoderC, *encoderD;
        
        
    public:
		Davros();
        void RobotInit();
        void AutonomousInit();
        void AutonomousPeriodic();
        void TeleopInit();
        void TeleopPeriodic();
        void TestPeriodic();
};

#endif
