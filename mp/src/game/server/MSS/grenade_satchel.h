//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose:		Satchel Charge
//
// $Workfile:     $
// $Date:         $
// $NoKeywords: $
//=============================================================================//

#ifndef	SATCHEL_H
#define	SATCHEL_H

#ifdef _WIN32
#pragma once
#endif

#include "basegrenade_shared.h"
<<<<<<< HEAD:mp/src/game/server/MSS/grenade_satchel.h
#include "MSS/weapon_slam.h"
=======

// BOXBOX removing
//#include "hl2mp/weapon_slam.h"
>>>>>>> parent of 2371c5c... Revert "hl strip":mp/src/game/server/MSS/grenade_satchel.h

class CSoundPatch;
class CSprite;

class CSatchelCharge : public CBaseGrenade
{
public:
	DECLARE_CLASS( CSatchelCharge, CBaseGrenade );

	void			Spawn( void );
	void			Precache( void );
	void			BounceSound( void );
	void			SatchelTouch( CBaseEntity *pOther );
	void			SatchelThink( void );
	
	// Input handlers
	void			InputExplode( inputdata_t &inputdata );

	float			m_flNextBounceSoundTime;
	bool			m_bInAir;
	Vector			m_vLastPosition;

public:
//	CWeapon_SLAM*	m_pMyWeaponSLAM;	// BOXBOX removing
	bool			m_bIsAttached;
	void			Deactivate( void );

	CSatchelCharge();
	~CSatchelCharge();

	DECLARE_DATADESC();

private:
	void				CreateEffects( void );
	CHandle<CSprite>	m_hGlowSprite;
};

#endif	//SATCHEL_H
