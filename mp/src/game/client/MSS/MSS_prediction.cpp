
#include "cbase.h"
#include "prediction.h"
#include "MSS_movedata.h"
#include "c_baseplayer.h"

// memdbgon must be the last include file in a .cpp file!!!
#include "tier0/memdbgon.h"

static CMSSMoveData g_MSSMoveData;
CMoveData *g_pMoveData = &g_MSSMoveData;

// Expose interface to engine
static CPrediction g_Prediction;

EXPOSE_SINGLE_INTERFACE_GLOBALVAR( CPrediction, IPrediction, VCLIENT_PREDICTION_INTERFACE_VERSION, g_Prediction );

CPrediction *prediction = &g_Prediction;

