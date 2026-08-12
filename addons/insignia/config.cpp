#include "\z\HFGB\addons\core\define.hpp"

class CfgPatches
{
	class HFGB_Insignia
	{
		name = "Headpats For Good Beans - Insignia";
		author = "Lupus590";
		units[] = {};
		weapons[] = {};
		magazines[] = {};
		ammo[] = {};
		requiredAddons[] =
		{
			"HFGB_Core",
			"A3_Ui_F",
		};
		skipWhenMissingDependencies = FALSE;
		skipWhenAnyAddonPresent[] = {};
	};
};

class CfgUnitInsignia
{
	class HFGB_Patch
	{
		displayName = "Headpats For Good Beans Patch";
		author = "Lupus590";
		texture = "\z\HFGB\addons\insignia\HFGB_patch.paa";
		material = "\A3\Ui_f\data\GUI\Cfg\UnitInsignia\default_insignia.rvmat";
	};
};
