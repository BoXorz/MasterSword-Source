
#include "cbase.h"
#include "kbutton.h"
#include "input.h"

// memdbgon must be the last include file in a .cpp file!!!
#include "tier0/memdbgon.h"


class CMSSInput : public CInput
{
public:
};

static CMSSInput g_Input;

// Expose this interface
IInput *input = ( IInput * )&g_Input;
