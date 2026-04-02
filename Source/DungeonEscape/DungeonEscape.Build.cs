// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class DungeonEscape : ModuleRules
{
	public DungeonEscape(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
		});

		PrivateDependencyModuleNames.AddRange(new string[] {
			"Slate",
			"SlateCore"
		});

		PublicIncludePaths.AddRange(new string[] {
			"DungeonEscape/Public",
			"DungeonEscape/Public/Variant_Horror",
			"DungeonEscape/Public/Variant_Horror/UI",
			"DungeonEscape/Public/Variant_Shooter",
			"DungeonEscape/Public/Variant_Shooter/AI",
			"DungeonEscape/Public/Variant_Shooter/UI",
			"DungeonEscape/Public/Variant_Shooter/Weapons"
		});

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
