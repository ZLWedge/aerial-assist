#ifndef ChopsticksPickUp_h
#define ChopsticksPickUp_h

#include "../CommandBase.h"

class ChopsticksPickUp: public CommandBase{
	public:
		ChopsticksPickUp();
		virtual void Initialize();
		virtual void Execute();
		virtual bool IsFinished();
		virtual void End();
		virtual void Interrupted();
};

#endif
