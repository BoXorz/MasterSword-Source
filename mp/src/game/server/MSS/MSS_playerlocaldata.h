
#ifndef MSS_PLAYERLOCALDATA_H
#define MSS_PLAYERLOCALDATA_H
#ifdef _WIN32
#pragma once
#endif

#include "networkvar.h"

#include "MSS_movedata.h"

//-----------------------------------------------------------------------------
// Purpose: Player specific data for MSS ( sent only to local player, too )
//-----------------------------------------------------------------------------
class CMSSPlayerLocalData
{
public:
	// Save/restore
	DECLARE_SIMPLE_DATADESC();
	DECLARE_CLASS_NOBASE( CMSSPlayerLocalData );
	DECLARE_EMBEDDED_NETWORKVAR();

	CMSSPlayerLocalData();

//	CNetworkVar( float, m_flSuitPower );
	CNetworkVar( bool,	m_bZooming );
//	CNetworkVar( int,	m_bitsActiveDevices );
//	CNetworkVar( int,	m_iSquadMemberCount );
//	CNetworkVar( int,	m_iSquadMedicCount );
//	CNetworkVar( bool,	m_fSquadInFollowMode );
//	CNetworkVar( bool,	m_bWeaponLowered );
//	CNetworkVar( EHANDLE, m_hAutoAimTarget );
//	CNetworkVar( Vector, m_vecAutoAimPoint );
//	CNetworkVar( bool,	m_bDisplayReticle );
//	CNetworkVar( bool,	m_bStickyAutoAim );
//	CNetworkVar( bool,	m_bAutoAimTarget );
//#ifdef HL2_EPISODIC
//	CNetworkVar( float, m_flFlashBattery );
//	CNetworkVar( Vector, m_vecLocatorOrigin );
//#endif

	// Ladder related data
	CNetworkVar( EHANDLE, m_hLadder );
	LadderMove_t			m_LadderMove;
};

EXTERN_SEND_TABLE(DT_MSSLocal);


#endif // MSS_PLAYERLOCALDATA_H
