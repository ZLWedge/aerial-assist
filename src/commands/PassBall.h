#ifndef PassBall_h
#define PassBall_h

#include "../CommandBase.h"

class PassBall: public CommandBase{
	public:
		PassBall();
		virtual void Initialize();
		virtual void Execute();
		virtual bool IsFinished();
		virtual void End();
		virtual void Interrupted();
};

#endif
