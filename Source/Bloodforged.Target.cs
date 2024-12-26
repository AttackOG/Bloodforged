// Bloodforged Unreal Engine 5 game created by AttackOG.

using UnrealBuildTool;
using System.Collections.Generic;

public class BloodforgedTarget : TargetRules
{
	public BloodforgedTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V5;

		ExtraModuleNames.AddRange( new string[] { "Bloodforged" } );
	}
}
