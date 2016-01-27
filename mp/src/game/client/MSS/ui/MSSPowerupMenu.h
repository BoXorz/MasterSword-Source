
#ifndef MSSPOWERUPMENU_H
#define MSSPOWERUPMENU_H
#ifdef _WIN32
#pragma once
#endif

#include <vgui_controls/Frame.h>
#include <vgui_controls/Button.h>
//#include <vgui_controls/HTML.h>

#include <game/client/iviewport.h>
#include "shareddefs.h"

class CMSPowerupMenu : public vgui::Frame, public IViewPortPanel
{
private:
	DECLARE_CLASS_SIMPLE( CMSPowerupMenu, vgui::Frame );

//	Color					 m_bgColor;
//	Color					 m_borderColor;

public:
	CMSPowerupMenu(IViewPort *pViewPort);
	virtual ~CMSPowerupMenu();

	virtual const char *GetName( void ) { return PANEL_POWERUPMENU; }
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

//	virtual void ShowFile( const char *filename);
//	virtual void ShowText( const char *text);
//	virtual void ShowURL( const char *URL);
//	virtual void ShowIndex( const char *entry);

	virtual void ApplySchemeSettings( vgui::IScheme *pScheme );

protected:	

	virtual void OnCommand( const char *command);

	void PlayPageTurnSound( void );
//	void HideAllChildControls( void );

	IViewPort	*m_pViewPort;

//	vgui::Label			*m_pLeftPageNumLabel;
//	vgui::Label			*m_pRightPageNumLabel;

//	vgui::Label			*m_pLeftPageTitleLabel;
	vgui::Label			*m_pRightPageTitleLabel;
/*
	vgui::Label			*m_pSexLabel;
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
*/

};


#endif // MSSPOWERUPMENU_H
