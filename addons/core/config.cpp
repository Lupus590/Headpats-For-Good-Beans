#include "define.hpp"

class CfgPatches
{
	class HFGB_Core
	{
		name = "Headpats For Good Beans - Core";
		author = "Lupus590";
		units[] = {};
		weapons[] = {};
		magazines[] = {};
		ammo[] = {};
		requiredAddons[] =
		{
			"CBA_Main",
			"tsp_animate",
		};
		skipWhenMissingDependencies = FALSE;
		skipWhenAnyAddonPresent[] = {};
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
