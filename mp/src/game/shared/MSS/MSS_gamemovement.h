
#include "gamemovement.h"
#include "func_ladder.h"
//#include "MSS_playerlocaldata.h"

#if defined( CLIENT_DLL )

#include "c_baseplayer.h"
#include "c_hl2mp_player.h"
#define CHL2MP_Player C_HL2MP_Player
#else

#include "hl2mp_player.h"

#endif

struct LadderMove_t;
class CInfoLadderDismount;

struct NearbyDismount_t
{
	CInfoLadderDismount		*dismount;
	float					distSqr;
};

//-----------------------------------------------------------------------------
// Purpose: MSS specific movement code
//-----------------------------------------------------------------------------
class CMSSGameMovement : public CGameMovement
{
	typedef CGameMovement BaseClass;
public:

	CMSSGameMovement();

// Overrides
	virtual void FullLadderMove();
	virtual bool LadderMove( void );
	virtual bool OnLadder( trace_t &trace );
	virtual int GetCheckInterval( IntervalType_t type );
	virtual void	SetGroundEntity( trace_t *pm );
	virtual bool CanAccelerate( void );

private:

	// See if we are pressing use near a ladder "mount" point and if so, latch us onto the ladder
	bool		CheckLadderAutoMount( CFuncLadder *ladder, const Vector& bestOrigin );

	bool		CheckLadderAutoMountCone( CFuncLadder *ladder, const Vector& bestOrigin, float maxAngleDelta, float maxDistToLadder );
	bool		CheckLadderAutoMountEndPoint(CFuncLadder *ladder, const Vector& bestOrigin );


	bool		LookingAtLadder( CFuncLadder *ladder );

	// Are we forcing the user's position to a new spot
	bool		IsForceMoveActive();
	// Start forcing player position
	void		StartForcedMove( bool mounting, float transit_speed, const Vector& goalpos, CFuncLadder *ladder );
	// Returns false when finished
	bool		ContinueForcedMove();

	// Given a list of nearby ladders, find the best ladder and the "mount" origin
	void		Findladder( float maxdist, CFuncLadder **ppLadder, Vector& ladderOrigin, const CFuncLadder *skipLadder );

	// Debounce the +USE key
	void		SwallowUseKey();

	// Returns true if the player will auto-exit the ladder via a dismount node
	bool		ExitLadderViaDismountNode( CFuncLadder *ladder, bool strict, bool useAlternate = false );
	void		GetSortedDismountNodeList( const Vector &org, float radius, CFuncLadder *ladder, CUtlRBTree< NearbyDismount_t, int >& list );

	LadderMove_t	*GetLadderMove();
	CHL2MP_Player	*GetMSSPlayer();

	void		SetLadder( CFuncLadder *ladder );
	CFuncLadder *GetLadder();
};


//-----------------------------------------------------------------------------
// Purpose: 
//-----------------------------------------------------------------------------
inline CHL2MP_Player	*CMSSGameMovement::GetMSSPlayer()
{
	return static_cast< CHL2MP_Player * >(player);
}

//-----------------------------------------------------------------------------
// Purpose: 
// Output : inline LadderMove*
//-----------------------------------------------------------------------------
inline LadderMove_t *CMSSGameMovement::GetLadderMove()
{
	CHL2MP_Player *p = GetMSSPlayer();
	if ( !p )
	{
		return NULL;
	}
	return p->GetLadderMove();
}

//-----------------------------------------------------------------------------
// Purpose: 
// Input  : *ladder - 
//-----------------------------------------------------------------------------
inline void CMSSGameMovement::SetLadder( CFuncLadder *ladder )
{
	CFuncLadder* oldLadder = GetLadder();

	if ( !ladder && oldLadder )
	{
		oldLadder->PlayerGotOff( GetMSSPlayer() );
	}


	GetMSSPlayer()->m_MSSLocal.m_hLadder.Set( ladder );
}

//-----------------------------------------------------------------------------
// Purpose: 
// Output : CFuncLadder
//-----------------------------------------------------------------------------
inline CFuncLadder *CMSSGameMovement::GetLadder()
{
	return static_cast<CFuncLadder*>( static_cast<CBaseEntity *>( GetMSSPlayer()->m_MSSLocal.m_hLadder.Get() ) );
}
