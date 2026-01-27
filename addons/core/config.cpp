#include "script_version.hpp"

class CfgPatches
{
	class HFGB_Core
	{
		name = "Headpats For Good Beans - Core";
		author = "Lupus590";
		units[] = {};
		weapons[] = {};
		requiredAddons[] =
		{
			"CBA_Main",
			"tsp_animate_ace",
		};
		VERSION_CONFIG;
	};
};

class CfgSettings
{
	class CBA
	{
		class Versioning // https://github.com/CBATeam/CBA_A3/wiki/Versioning-System
		{
			class HFGB_Core
			{
				main_addon = "HFGB_Core";
			};
		};
	};
};

class CfgUnitInsignia
{
	class HFGB_Patch
	{
		displayName = "Headpats For Good Beans Unit Patch";
		author = "Lupus590";
		texture = "\z\HFGB\addons\core\HFGB_patch.paa";
		material = "\A3\Ui_f\data\GUI\Cfg\UnitInsignia\default_insignia.rvmat";
	};
};

class Extended_PreInit_EventHandlers
{
	class hfgb_functions
	{
		init = "[] call compileScript ['z\HFGB\addons\core\functions.sqf']";
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
				class ACE_BonkHead : ACE_PatHead
				{
					displayName = "Bonk Head";
					selection = "";
					condition = "hfgb_bonk_enable && [_player, _target] call ace_interaction_fnc_canTapShoulder && tsp_cba_animate_tap";
					statement = "[_player,_target] spawn hfgb_fnc_bonkHead";
				};
			};
		};
	};
};

class CfgSounds
{
	class hfgb_bonk
	{
		name = "Bonk Sound";
		sound[] = { "HFGB_Core\bonk.ogg", 1, 1, 100 };	// file, volume, pitch, maxDistance
		titles[] = { 0, "*bonk*" };

		titlesFont = "LCD14";
		titlesSize = 0.1;

		forceTitles = 0;			// display titles even if global show titles option is off (1) or not (0)
		titlesStructured = 1;		// treat titles as Structured Text (1) or not (0)
	};
};
