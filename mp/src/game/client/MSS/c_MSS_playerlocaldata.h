

#if !defined( C_MSS_PLAYERLOCALDATA_H )
#define C_MSS_PLAYERLOCALDATA_H
#ifdef _WIN32
#pragma once
#endif


#include "dt_recv.h"

#include "MSS_movedata.h"

EXTERN_RECV_TABLE( DT_MSSLocal );


class C_MSSPlayerLocalData
{
public:
	DECLARE_PREDICTABLE();
	DECLARE_CLASS_NOBASE( C_MSSPlayerLocalData );
	DECLARE_EMBEDDED_NETWORKVAR();

	C_MSSPlayerLocalData();

//	float	m_flSuitPower;
	bool	m_bZooming;
//	int		m_bitsActiveDevices;
//	int		m_iSquadMemberCount;
//	int		m_iSquadMedicCount;
//	bool	m_fSquadInFollowMode;
//	bool	m_bWeaponLowered;
//	EHANDLE m_hAutoAimTarget;
//	Vector	m_vecAutoAimPoint;
//	bool	m_bDisplayReticle;
//	bool	m_bStickyAutoAim;
//	bool	m_bAutoAimTarget;
//#ifdef HL2_EPISODIC
//	float	m_flFlashBattery;
//	Vector	m_vecLocatorOrigin;
//#endif

	// Ladder related data
	EHANDLE			m_hLadder;
	LadderMove_t	m_LadderMove;
};


#endif
