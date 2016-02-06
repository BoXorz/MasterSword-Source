
#include "cbase.h"
#include "../EventLog.h"
#include "KeyValues.h"

// memdbgon must be the last include file in a .cpp file!!!
#include "tier0/memdbgon.h"

class CMSSEventLog : public CEventLog
{
private:
	typedef CEventLog BaseClass;

public:
	virtual char const *Name() { return "CMSSEventLog"; }

	virtual ~CMSSEventLog() {};

public:
	bool PrintEvent( IGameEvent * event )	// override virtual function
	{
		if ( BaseClass::PrintEvent( event ) )
		{
			return true;
		}
	
		if ( Q_strcmp(event->GetName(), "hl2_") == 0 )
		{
			return PrintMSSEvent( event );
		}

		return false;
	}

protected:

	bool PrintMSSEvent( IGameEvent * event )	// print Mod specific logs
	{
	//	const char * name = event->GetName() + Q_strlen("hl2_"); // remove prefix

		return false;
	}

};

static CMSSEventLog s_MSSEventLog;

//-----------------------------------------------------------------------------
// Singleton access
//-----------------------------------------------------------------------------
IGameSystem* GameLogSystem()
{
	return &s_MSSEventLog;
}

