
#ifndef MSSSTATSMENU_H
#define MSSSTATSMENU_H
#ifdef _WIN32
#pragma once
#endif

#include <vgui_controls/Frame.h>
#include <vgui_controls/Button.h>
//#include <vgui_controls/HTML.h>

#include <game/client/iviewport.h>
#include "shareddefs.h"
#include "basemodelpanel.h"

class CMSStatsMenu : public vgui::Frame, public IViewPortPanel
{
private:
	DECLARE_CLASS_SIMPLE( CMSStatsMenu, vgui::Frame );

public:
	CMSStatsMenu(IViewPort *pViewPort);
	virtual ~CMSStatsMenu();

	virtual const char *GetName( void ) { return PANEL_STATSMENU; }
	virtual void SetData(KeyValues *data) { return; }
//	virtual void SetData( int type, const char *title, const char *message, const char *command);
	virtual void Reset();
	virtual void Update();
//	virtual void MoveToCenterOfScreen();

	virtual bool NeedsUpdate( void ) { return false; }
	virtual bool HasInputElements( void ) { return false; }	// BOXBOX someof the child panels will though
	virtual void ShowPanel( bool bShow );

	// both vgui::Frame and IViewPortPanel define these, so explicitly define them here as passthroughs to vgui
	vgui::VPANEL GetVPanel( void ) { return BaseClass::GetVPanel(); }
  	virtual bool IsVisible() { return BaseClass::IsVisible(); }
  	virtual void SetParent( vgui::VPANEL parent ) { BaseClass::SetParent( parent ); }

	virtual void ApplySchemeSettings( vgui::IScheme *pScheme );

protected:	

	virtual void OnCommand( const char *command);

	void PlayPageTurnSound( void );
//	void HideAllChildControls( void );

	IViewPort	*m_pViewPort;
//	int m_nCurPage; // BOXBOX what page are we on now (1-2, 3-4, etc)

//	vgui::Label			*m_pLeftPageNumLabel;
//	vgui::Label			*m_pRightPageNumLabel;

//	vgui::Label			*m_pLeftPageTitleLabel;
	vgui::Label			*m_pRightPageTitleLabel;

	vgui::Label			*m_pGenderLabel;
	vgui::Label			*m_pRaceLabel;
	vgui::Label			*m_pTotalExpText;
	vgui::Label			*m_pTotalExpLabel;

	vgui::Label			*m_pUnarmedLabel;
	vgui::Label			*m_p1HPiercingLabel;
	vgui::Label			*m_p1HSlashingLabel;
	vgui::Label			*m_p1HBashingLabel;
	vgui::Label			*m_p2HPiercingLabel;
	vgui::Label			*m_p2HSlashingLabel;
	vgui::Label			*m_p2HBashingLabel;
	vgui::Label			*m_pArcheryLabel;
	vgui::Label			*m_pThrowWeaponLabel;

	vgui::Label			*m_pMightLabel;
	vgui::Label			*m_pAgilityLabel;
	vgui::Label			*m_pStaminaLabel;
	vgui::Label			*m_pIntellectLabel;
	vgui::Label			*m_pWitLabel;
	vgui::Label			*m_pFortitudeLabel;
	vgui::Label			*m_pLuckLabel;

	vgui::Label			*m_pAlchemyLabel;
	vgui::Label			*m_pClothworkLabel;
	vgui::Label			*m_pWoodworkLabel;
	vgui::Label			*m_pStoneworkLabel;
	vgui::Label			*m_pMetalworkLabel;

	CModelPanel			*m_pCharModel;
};


#endif // MSSSTATSMENU_H
