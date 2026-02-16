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
	class ACE_Actions
		{
			class ACE_TapShoulderRight;
			class ACE_Head
			{
				class ACE_PatHead : ACE_TapShoulderRight
				{
					displayName = "Pat Head";
					selection = "";
					condition = "[_player, _target] call ace_interaction_fnc_canTapShoulder && tsp_cba_animate_tap";
					statement = "[_player,_target] spawn hfgb_fnc_patHead";
				};
			};
		};
	};
};
