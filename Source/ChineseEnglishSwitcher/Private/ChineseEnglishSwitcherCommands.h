#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "Styling/AppStyle.h"

class FChineseEnglishSwitcherCommands final : public TCommands<FChineseEnglishSwitcherCommands>
{
public:
	FChineseEnglishSwitcherCommands()
		: TCommands<FChineseEnglishSwitcherCommands>(
			TEXT("ChineseEnglishSwitcher"),
			NSLOCTEXT("Contexts", "ChineseEnglishSwitcher", "Chinese English Switcher"),
			NAME_None,
			FAppStyle::GetAppStyleSetName())
	{
	}

	virtual void RegisterCommands() override;

public:
	TSharedPtr<FUICommandInfo> ToggleLanguage;
	TSharedPtr<FUICommandInfo> SwitchToEnglish;
	TSharedPtr<FUICommandInfo> SwitchToChinese;
};
