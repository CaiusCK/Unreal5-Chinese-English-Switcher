using UnrealBuildTool;

public class ChineseEnglishSwitcher : ModuleRules
{
	public ChineseEnglishSwitcher(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"CoreUObject",
				"Engine",
				"InputCore",
				"Slate",
				"SlateCore",
				"ToolMenus"
			});

		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"LevelEditor",
				"Projects",
				"UnrealEd"
			});
	}
}
