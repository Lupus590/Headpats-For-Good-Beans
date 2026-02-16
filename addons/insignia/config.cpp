class CfgPatches
{
	class HFGB_Insignia
	{
		name = "Headpats For Good Beans - Insignia";
		author = "Lupus590";
		units[] = {};
		weapons[] = {};
		requiredAddons[] =
		{
			"HFGB_Core",
			"A3_Ui_F",
		};
	};
};

class CfgUnitInsignia
{
	class HFGB_Patch
	{
		displayName = "Headpats For Good Beans Unit Patch";
		author = "Lupus590";
		texture = "\z\HFGB\addons\insignia\HFGB_patch.paa";
		material = "\A3\Ui_f\data\GUI\Cfg\UnitInsignia\default_insignia.rvmat";
	};
};
