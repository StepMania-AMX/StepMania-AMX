#include "global.h"

#include "ScreenClearMachineStats.h"
#include "ProfileManager.h"
#include "ScreenManager.h"
#include "ThemeManager.h"

#define NEXT_SCREEN			THEME->GetMetric(m_sName,"NextScreen")

ScreenClearMachineStats::ScreenClearMachineStats( CString sName ): Screen( sName )
{
	PROFILEMAN->GetMachineProfile()->InitAll();
	PROFILEMAN->SaveMachineProfile();

	SCREENMAN->SystemMessage( "Machine stats cleared." );

	SCREENMAN->SetNewScreen( NEXT_SCREEN );
}
