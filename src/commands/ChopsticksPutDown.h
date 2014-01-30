#ifndef ChopsticksPutDown_h
#define ChopsticksPutDown_h

#include "../CommandBase.h"

class ChopsticksPutDown: public CommandBase{
	public:
		ChopsticksPutDown();
		virtual void Initialize();
		virtual void Execute();
		virtual bool IsFinished();
		virtual void End();
		virtual void Interrupted();
};

#endif
