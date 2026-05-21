#include "ChineseEnglishSwitcherCommands.h"

#define LOCTEXT_NAMESPACE "FChineseEnglishSwitcherCommands"

void FChineseEnglishSwitcherCommands::RegisterCommands()
{
	UI_COMMAND(
		ToggleLanguage,
		"Toggle Chinese / English",
		"Switch the editor language between Simplified Chinese and English.",
		EUserInterfaceActionType::Button,
		FInputChord());

	UI_COMMAND(
		SwitchToEnglish,
		"Switch to English",
		"Set the editor language to English.",
		EUserInterfaceActionType::Button,
		FInputChord());

	UI_COMMAND(
		SwitchToChinese,
		"Switch to Chinese",
		"Set the editor language to Simplified Chinese.",
		EUserInterfaceActionType::Button,
		FInputChord());
}

#undef LOCTEXT_NAMESPACE
