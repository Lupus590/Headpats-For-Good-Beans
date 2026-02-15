class CfgPatches
{
	class HFGB_Insignia_Patches
	{
		name = "Headpats For Good Beans - Insignia Patches";
		author = "Lupus590";
		units[] = {};
		weapons[] = {};
		requiredAddons[] =
		{
			"HFGB_Core",
		};
	};
};


class CfgUnitInsignia
{
	class HFGB_Patch
	{
		displayName = "Headpats For Good Beans Unit Patch";
		author = "Lupus590";
		texture = "\z\HFGB\addons\insignia_patches\HFGB_patch.paa";
		material = "\A3\Ui_f\data\GUI\Cfg\UnitInsignia\default_insignia.rvmat"; // TODO: where is this from so that it can be in required addons
	};
};
