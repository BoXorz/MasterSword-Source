
#include "cbase.h"
#include "ivmodemanager.h"
#include "clientmode_hl2mpnormal.h" // BOXBOX TODO change to MSS
#include "panelmetaclassmgr.h"

// memdbgon must be the last include file in a .cpp file!!!
#include "tier0/memdbgon.h"

// default FOV for HL2
ConVar default_fov( "default_fov", "75", FCVAR_CHEAT );

// The current client mode. Always ClientModeNormal in HL.
IClientMode *g_pClientMode = NULL;

#define SCREEN_FILE		"scripts/vgui_screens.txt"

class CMSSModeManager : public IVModeManager
{
public:
				CMSSModeManager( void );
	virtual		~CMSSModeManager( void );

	virtual void	Init( void );
	virtual void	SwitchMode( bool commander, bool force );
	virtual void	OverrideView( CViewSetup *pSetup );
	virtual void	CreateMove( float flInputSampleTime, CUserCmd *cmd );
	virtual void	LevelInit( const char *newmap );
	virtual void	LevelShutdown( void );
};

CMSSModeManager::CMSSModeManager( void )
{
}

CMSSModeManager::~CMSSModeManager( void )
{
}

void CMSSModeManager::Init( void )
{
	g_pClientMode = GetClientModeNormal();
	PanelMetaClassMgr()->LoadMetaClassDefinitionFile( SCREEN_FILE );
}

void CMSSModeManager::SwitchMode( bool commander, bool force )
{
}

void CMSSModeManager::OverrideView( CViewSetup *pSetup )
{
}

void CMSSModeManager::CreateMove( float flInputSampleTime, CUserCmd *cmd )
{
}

void CMSSModeManager::LevelInit( const char *newmap )
{
	g_pClientMode->LevelInit( newmap );
}

void CMSSModeManager::LevelShutdown( void )
{
	g_pClientMode->LevelShutdown();
}


static CMSSModeManager g_MSSModeManager;
IVModeManager *modemanager = &g_MSSModeManager;

