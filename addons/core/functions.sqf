["hfgb_bonk_enable", "CHECKBOX", ["STR_HFGB_Core_HeadBonking" call BIS_fnc_localize, "STR_HFGB_Core_EnableDisableHeadBonking" call BIS_fnc_localize], "Headpats For Good Beans", false] call CBA_fnc_addSetting;
["hfgb_sound_bonk_enable", "CHECKBOX", ["STR_HFGB_Core_PlaySoundWhenBonking" call BIS_fnc_localize, "STR_HFGB_Core_EnableDisableSoundForHeadBonking" call BIS_fnc_localize], "Headpats For Good Beans", false] call CBA_fnc_addSetting;
["hfgb_sound_bonk_volume", "SLIDER", ["STR_HFGB_Core_BonkSoundVolume" call BIS_fnc_localize, "STR_HFGB_Core_SoundEffectVolumeForHeadBonking" call BIS_fnc_localize], "Headpats For Good Beans", [0, 10, 5], 2, false] call CBA_fnc_addSetting;

["Headpats For Good Beans", "hfgb__keybind_patHead", "STR_HFGB_Core_PatHead" call BIS_fnc_localize, {if (tsp_cba_animate_tap) then {[playa,objNull] spawn hfgb_fnc_patHead}}, {}, [0, [false, false, false]]] call CBA_fnc_addKeybind;
["Headpats For Good Beans", "hfgb__keybind_bonkHead", "STR_HFGB_Core_BonkHead" call BIS_fnc_localize, {if (hfgb_bonk_enable && tsp_cba_animate_tap) then {[playa,objNull] spawn hfgb_fnc_bonkHead}}, {}, [0, [false, false, false]]] call CBA_fnc_addKeybind;

// copy edit of tsp_fnc_animate_tap from https://github.com/TheSpeshalPlatoon/A3-Animate/blob/5347df999b60c51e7ad556f092345ef745e43edf/tsp_animate/functions.sqf#L164
hfgb_fnc_patHead = {
    params ["_unit", "_target"];
    _targets = [_unit, eyePos _unit, [0,15,30,45,60,-15,-30,-45,-60], 3, getCameraViewDirection _unit] call tsp_fnc_obstruction select {alive (_x#0) && _x#0 isKindOf "CAManBase"};
    if (_target isEqualTo objNull && _targets isNotEqualTo []) then {_target = _targets#0#0};
    if (_target isEqualTo objNull || "leg" in gestureState _unit || "shoulder" in gestureState _unit) exitWith {};
    [_unit, "", "tsp_animate_shoulder_wnon_laut", "", "tsp" in gestureState _unit, true, true] spawn tsp_fnc_gesture_play;
    [[name _unit, "STR_HFGB_Core_PattedYourHead" call BIS_fnc_localize], tsp_fnc_hint] remoteExec ["call", _target]; // TODO: receiver side translate
    [_unit, 5, "", 0] call tsp_fnc_animate_effect;
    sleep 0.3; 
    [_target, 5, "A3\Sounds_F\characters\footsteps\int_carpet\carpet_int_sprint_HPF_"+str(round random 8 max 1)+".wss", 1] call tsp_fnc_animate_effect;
};

// copy edit of tsp_fnc_animate_tap from https://github.com/TheSpeshalPlatoon/A3-Animate/blob/5347df999b60c51e7ad556f092345ef745e43edf/tsp_animate/functions.sqf#L164
hfgb_fnc_bonkHead = {
    params ["_unit", "_target"];
    _targets = [_unit, eyePos _unit, [0,15,30,45,60,-15,-30,-45,-60], 3, getCameraViewDirection _unit] call tsp_fnc_obstruction select {alive (_x#0) && _x#0 isKindOf "CAManBase"};
    if (_target isEqualTo objNull && _targets isNotEqualTo []) then {_target = _targets#0#0};
    if (_target isEqualTo objNull || "leg" in gestureState _unit || "shoulder" in gestureState _unit) exitWith {};
    if (!hfgb_bonk_enable) exitWith {};
    [_unit, "", "tsp_animate_shoulder_wnon_laut", "", "tsp" in gestureState _unit, true, true] spawn tsp_fnc_gesture_play;
    [[name _unit, "STR_HFGB_Core_BonkedYourHead" call BIS_fnc_localize], tsp_fnc_hint] remoteExec ["call", _target]; // TODO: receiver side translate
    [_unit, 5, "", 0] call tsp_fnc_animate_effect;
    sleep 0.3; 
    if(hfgb_sound_bonk_enable) then
    {   
        [_target, 5, "z\HFGB\addons\core\bonk.wss", hfgb_sound_bonk_volume] call tsp_fnc_animate_effect;
    }
    else
    {
        [_target, 5, "A3\Sounds_F\characters\footsteps\int_carpet\carpet_int_sprint_HPF_"+str(round random 8 max 1)+".wss", 1] call tsp_fnc_animate_effect;
    };
};
