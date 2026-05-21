#include "ChineseEnglishSwitcher.h"

#include "ChineseEnglishSwitcherCommands.h"
#include "Framework/Commands/UICommandList.h"
#include "Internationalization/Culture.h"
#include "Internationalization/Internationalization.h"
#include "Kismet/KismetInternationalizationLibrary.h"
#include "Misc/MessageDialog.h"
#include "Styling/AppStyle.h"
#include "ToolMenus.h"

#define LOCTEXT_NAMESPACE "FChineseEnglishSwitcherModule"

namespace ChineseEnglishSwitcher
{
	constexpr const TCHAR* EnglishCulture = TEXT("en");
	constexpr const TCHAR* ChineseCulture = TEXT("zh-Hans");
}

void FChineseEnglishSwitcherModule::StartupModule()
{
	FChineseEnglishSwitcherCommands::Register();

	CommandList = MakeShared<FUICommandList>();
	const FChineseEnglishSwitcherCommands& Commands = FChineseEnglishSwitcherCommands::Get();

	CommandList->MapAction(
		Commands.ToggleLanguage,
		FExecuteAction::CreateRaw(this, &FChineseEnglishSwitcherModule::ToggleLanguage));

	CommandList->MapAction(
		Commands.SwitchToEnglish,
		FExecuteAction::CreateRaw(this, &FChineseEnglishSwitcherModule::SwitchToEnglish));

	CommandList->MapAction(
		Commands.SwitchToChinese,
		FExecuteAction::CreateRaw(this, &FChineseEnglishSwitcherModule::SwitchToChinese));

	UToolMenus::RegisterStartupCallback(
		FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FChineseEnglishSwitcherModule::RegisterMenus));
}

void FChineseEnglishSwitcherModule::ShutdownModule()
{
	UToolMenus::UnRegisterStartupCallback(this);
	UToolMenus::UnregisterOwner(this);

	FChineseEnglishSwitcherCommands::Unregister();
	CommandList.Reset();
}

void FChineseEnglishSwitcherModule::RegisterMenus()
{
	FToolMenuOwnerScoped OwnerScoped(this);
	const FChineseEnglishSwitcherCommands& Commands = FChineseEnglishSwitcherCommands::Get();

	if (UToolMenu* ToolsMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.Tools"))
	{
		FToolMenuSection& Section = ToolsMenu->FindOrAddSection("ChineseEnglishSwitcher");
		Section.Label = LOCTEXT("ChineseEnglishSwitcherSection", "Language");
		Section.AddMenuEntryWithCommandList(Commands.ToggleLanguage, CommandList);
		Section.AddMenuEntryWithCommandList(Commands.SwitchToEnglish, CommandList);
		Section.AddMenuEntryWithCommandList(Commands.SwitchToChinese, CommandList);
	}

	if (UToolMenu* ToolbarMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar.PlayToolBar"))
	{
		FToolMenuSection& Section = ToolbarMenu->FindOrAddSection("ChineseEnglishSwitcher");
		FToolMenuEntry& Entry = Section.AddEntry(FToolMenuEntry::InitToolBarButton(
			Commands.ToggleLanguage,
			TAttribute<FText>(),
			TAttribute<FText>(),
			FSlateIcon(FAppStyle::GetAppStyleSetName(), "Icons.World")));
		Entry.SetCommandList(CommandList);
	}
}

void FChineseEnglishSwitcherModule::SwitchToEnglish()
{
	ApplyCulture(ChineseEnglishSwitcher::EnglishCulture);
}

void FChineseEnglishSwitcherModule::SwitchToChinese()
{
	ApplyCulture(ChineseEnglishSwitcher::ChineseCulture);
}

void FChineseEnglishSwitcherModule::ToggleLanguage()
{
	ApplyCulture(IsCurrentCultureChinese() ? ChineseEnglishSwitcher::EnglishCulture : ChineseEnglishSwitcher::ChineseCulture);
}

void FChineseEnglishSwitcherModule::ApplyCulture(const FString& CultureName)
{
	const FString CurrentCultureName = FInternationalization::Get().GetCurrentCulture()->GetName();
	if (CurrentCultureName.Equals(CultureName, ESearchCase::IgnoreCase))
	{
		return;
	}

	UKismetInternationalizationLibrary::SetCurrentLanguageAndLocale(CultureName, true);

	FMessageDialog::Open(
		EAppMsgType::Ok,
		FText::Format(
			LOCTEXT("RestartEditorMessage", "Editor language has been set to {0}.\nRestart Unreal Editor if some text does not update immediately."),
			FText::FromString(CultureName)));
}

bool FChineseEnglishSwitcherModule::IsCurrentCultureChinese() const
{
	const FString CurrentCultureName = FInternationalization::Get().GetCurrentCulture()->GetName();
	return CurrentCultureName.StartsWith(TEXT("zh"), ESearchCase::IgnoreCase);
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FChineseEnglishSwitcherModule, ChineseEnglishSwitcher)
