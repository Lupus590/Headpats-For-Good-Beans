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
