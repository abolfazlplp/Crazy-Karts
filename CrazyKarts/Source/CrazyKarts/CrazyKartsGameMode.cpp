// Copyright Epic Games, Inc. All Rights Reserved.

#include "CrazyKartsGameMode.h"
#include "CrazyKartsPawn.h"
#include "CrazyKartsHud.h"

ACrazyKartsGameMode::ACrazyKartsGameMode()
{
	DefaultPawnClass = ACrazyKartsPawn::StaticClass();
	HUDClass = ACrazyKartsHud::StaticClass();
}
