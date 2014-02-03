#ifndef ThrowBall_h
#define ThrowBall_h

#include "../CommandBase.h"

class ThrowBall: public CommandBase{
	public:
		ThrowBall();
		virtual void Initialize();
		virtual void Execute();
		virtual bool IsFinished();
		virtual void End();
		virtual void Interrupted();
};

#endif

