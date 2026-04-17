// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ProyectoClase3 : ModuleRules
{
	public ProyectoClase3(ReadOnlyTargetRules Target) : base(Target)
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
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"ProyectoClase3",
			"ProyectoClase3/Variant_Platforming",
			"ProyectoClase3/Variant_Platforming/Animation",
			"ProyectoClase3/Variant_Combat",
			"ProyectoClase3/Variant_Combat/AI",
			"ProyectoClase3/Variant_Combat/Animation",
			"ProyectoClase3/Variant_Combat/Gameplay",
			"ProyectoClase3/Variant_Combat/Interfaces",
			"ProyectoClase3/Variant_Combat/UI",
			"ProyectoClase3/Variant_SideScrolling",
			"ProyectoClase3/Variant_SideScrolling/AI",
			"ProyectoClase3/Variant_SideScrolling/Gameplay",
			"ProyectoClase3/Variant_SideScrolling/Interfaces",
			"ProyectoClase3/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
