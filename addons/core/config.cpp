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
			"tsp_animate",
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

class Extended_PreInit_EventHandlers
{
	class hfgb_functions
	{
		init = "[] call compileScript ['z\HFGB\addons\core\functions.sqf']";
	};
};

class CfgSounds
{
	class hfgb_bonk
	{
		name = "Bonk Sound";
		sound[] = { "\HFGB_Core\bonk.ogg", 5, 1, 100 };	// file, volume, pitch, maxDistance
		titles[] = { 0, "*bonk*" };

		titlesFont = "LCD14";
		titlesSize = 0.1;

		forceTitles = 0;			// display titles even if global show titles option is off (1) or not (0)
		titlesStructured = 1;		// treat titles as Structured Text (1) or not (0)
	};
};
