// Bloodforged Unreal Engine 5 game created by AttackOG.

using UnrealBuildTool;
using System.Collections.Generic;

public class BloodforgedEditorTarget : TargetRules
{
	public BloodforgedEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V5;

		ExtraModuleNames.AddRange( new string[] { "Bloodforged" } );
	}
}
