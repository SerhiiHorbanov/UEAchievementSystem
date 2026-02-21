using UnrealBuildTool;

public class UEAchievementSystemEditor : ModuleRules
{
	public UEAchievementSystemEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EditorSubsystem", "UnrealEd", "UEAchievementSystem" });

		PrivateDependencyModuleNames.AddRange(new string[] {  });
	}
}
