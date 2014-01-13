#ifndef MeccanumDrive_h
#define MeccanumDrive_h

#include "../CommandBase.h"

class MeccanumDrive: public CommandBase{
	public:
		MeccanumDrive();
		virtual void Initialize();
		virtual void Execute();
		virtual bool IsFinished();
		virtual void End();
		virtual void Interrupted();
};

#endif
