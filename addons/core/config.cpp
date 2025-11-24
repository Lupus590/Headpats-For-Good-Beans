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
