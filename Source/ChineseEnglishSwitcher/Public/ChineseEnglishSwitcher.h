#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FChineseEnglishSwitcherModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

private:
	void RegisterMenus();
	void SwitchToEnglish();
	void SwitchToChinese();
	void ToggleLanguage();
	void ApplyCulture(const FString& CultureName);
	bool IsCurrentCultureChinese() const;

private:
	TSharedPtr<class FUICommandList> CommandList;
};
