class CfgPatches
{
	class HFGB_ACE
	{
		name = "Headpats For Good Beans - ACE";
		author = "Lupus590";
		units[] = {};
		weapons[] = {};
		requiredAddons[] =
		{
			"HFGB_Core",
			"HFGB_Insignia",
			"tsp_animate_ace",
			"ace_interaction",
		};
		skipWhenMissingDependencies = 1;
	};
};

class CfgVehicles
{
	class Man;
	class CAManBase: Man
	{
		class ACE_SelfActions {
			class ACE_BonkHeadSelf
			{
				displayName = "$STR_HFGB_Core_BonkHeadSelf";
				condition = "hfgb_bonk_enable && [_player, _player] call ace_interaction_fnc_canTapShoulder && tsp_cba_animate_tap";
				statement = "[_player] spawn hfgb_fnc_bonkHeadSelf";
			};
        };
		class ACE_Actions
		{
			class ACE_TapShoulderRight;
			class ACE_Head
			{
				class ACE_PatHead : ACE_TapShoulderRight
				{
					displayName = "$STR_HFGB_Core_PatHead";
					selection = "";
					condition = "[_player, _target] call ace_interaction_fnc_canTapShoulder && tsp_cba_animate_tap";
					statement = "[_player,_target] spawn hfgb_fnc_patHead";
					icon = "\z\HFGB\addons\insignia\HFGB_patch.paa";
				};
				class ACE_BoopNose : ACE_PatHead
				{
					displayName = "$STR_HFGB_Core_BoopNose";
					statement = "[_player,_target] spawn hfgb_fnc_boopNose";
				};
				class ACE_BonkHead : ACE_PatHead
				{
					displayName = "$STR_HFGB_Core_BonkHead";
					condition = "hfgb_bonk_enable && [_player, _target] call ace_interaction_fnc_canTapShoulder && tsp_cba_animate_tap";
					statement = "[_player,_target] spawn hfgb_fnc_bonkHead";
				};
			};
		};
	};
};
