
#include "cbase.h"
#include "vgui_int.h"
#include "ienginevgui.h"

// memdbgon must be the last include file in a .cpp file!!!
#include "tier0/memdbgon.h"

void VGUI_CreateClientDLLRootPanel( void )
{
	// Just using PANEL_ROOT in MSS right now
}

void VGUI_DestroyClientDLLRootPanel( void )
{
}

vgui::VPANEL VGui_GetClientDLLRootPanel( void )
{
	vgui::VPANEL root = enginevgui->GetPanel( PANEL_CLIENTDLL );
	return root;
}
