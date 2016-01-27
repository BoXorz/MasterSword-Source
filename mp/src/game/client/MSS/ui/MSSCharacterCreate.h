
// BOXBOX Header file for the character creation menu

#ifdef _WIN32
#pragma once
#endif

#include <vgui_controls/Frame.h>
#include <game/client/iviewport.h>
#include "MSSClient3DModel.h"
#include "ienginevgui.h"
#include "basemodelpanel.h"

//-----------------------------------------------------------------------------
// Purpose: Character menu
//-----------------------------------------------------------------------------
class CMSCharCreateMenu : public vgui::Frame, public IViewPortPanel
{
private:
	DECLARE_CLASS_SIMPLE( CMSCharCreateMenu, vgui::Frame );

public:
	CMSCharCreateMenu( IViewPort *pViewPort );
	virtual ~CMSCharCreateMenu();

	virtual void ApplySchemeSettings( vgui::IScheme *pScheme ); // BOXBOX added this

	virtual void OnCommand(const char *command);

	virtual const char *GetName( void ) { return PANEL_CHARCREATE; }
	virtual void SetData(KeyValues *data) {};
	virtual void Reset();
	virtual void Update();
	virtual bool NeedsUpdate( void );
	virtual bool HasInputElements( void ) { return true; }
	virtual void ShowPanel( bool bShow );
//	virtual void Remove3DCharacters();
	virtual void OnClose( ) override;

	// both vgui::Frame and IViewPortPanel define these, so explicitly define them here as passthroughs to vgui
	vgui::VPANEL GetVPanel( void ) { return BaseClass::GetVPanel(); }
  	virtual bool IsVisible() { return BaseClass::IsVisible(); }
  	virtual void SetParent( vgui::VPANEL parent ) { BaseClass::SetParent( parent ); }		
	vgui::Panel *CMSCharCreateMenu::CreateControlByName(const char *controlName);

	//Camera view position
	static Vector g_ViewPos;
	static QAngle g_ViewAng;

//	bool m_CharsFollowCam;
	static CMSCharCreateMenu *static_pCurrentMenu;

	//Character positions
/*	struct char_selection_spawnpoint_info_s
	{
		Vector Pos;
		QAngle Rot;
	};
*/
//	void GetCharPos( int charIdx, char_selection_spawnpoint_info_s &out_Pos );	//Get position of a ghost character

//	static CUtlVector<char_selection_spawnpoint_info_s> m_CharSelectSpots;
//	CUtlVector<CHandle<CClientSidePlayerModel>> m_SelectionCharacters;

	CPanelAnimationVar( float, m_DistFromCamera, "3dchar_dist_forward", "float" );
	CPanelAnimationVar( float, m_DistFromCamera_Side, "3dchar_dist_side", "float" );
	CPanelAnimationVar( float, m_DistFromCamera_Up, "3dchar_dist_up", "float" );
	CPanelAnimationVar( float, m_DistFromCamera_SideSpacing, "3dchar_dist_side_spacing", "float" );
	CPanelAnimationVar( float, m_SlotTitleY, "SlotTitle_Y", "float" );
	CPanelAnimationVar( float, m_SlotY, "Slot_Y", "float" );
	CPanelAnimationVar( float, m_SlotW, "Slot_W", "float" );
	CPanelAnimationVar( float, m_SlotH, "Slot_H", "float" );

protected:

	vgui::Label		*m_pMightLabel;
	vgui::Label		*m_pAgilityLabel;
	vgui::Label		*m_pStaminaLabel;
	vgui::Label		*m_pIntellectLabel;
	vgui::Label		*m_pWitLabel;
	vgui::Label		*m_pFortitudeLabel;
	vgui::Label		*m_pLuckLabel;
	vgui::Label		*m_pBonusLabel;


	int m_nSelectedGender;
	int m_nSelectedRace;

	void ResetModel( void );
	void ResetStats( void );

	int m_nBaseMightValue;
	int m_nBaseAgilityValue;
	int m_nBaseStaminaValue;
	int m_nBaseIntellectValue;
	int m_nBaseWitValue;
	int m_nBaseFortitudeValue;
	int m_nBaseLuckValue;

	int m_nMightValue;
	int m_nAgilityValue;
	int m_nStaminaValue;
	int m_nIntellectValue;
	int m_nWitValue;
	int m_nFortitudeValue;
	int m_nLuckValue;

	int m_nPointsToSpread;

	CModelPanel			*m_pCharModel;
};
