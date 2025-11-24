// copy edit of tsp_fnc_animate_tap from https://github.com/TheSpeshalPlatoon/A3-Animate/blob/5347df999b60c51e7ad556f092345ef745e43edf/tsp_animate/functions.sqf#L164
hfgb_fnc_patHead = {
    params ["_unit", ["_target", objNull]];
    _targets = [_unit, eyePos _unit, [0,15,30,45,60,-15,-30,-45,-60], 3, getCameraViewDirection _unit] call tsp_fnc_obstruction select {alive (_x#0) && _x#0 isKindOf "CAManBase"};
    if (_target isEqualTo objNull && _targets isNotEqualTo []) then {_target = _targets#0#0};
    if (_target isEqualTo objNull || "leg" in gestureState _unit || "shoulder" in gestureState _unit) exitWith {};
    [_unit, "", "tsp_animate_shoulder_wnon_laut", "", "tsp" in gestureState _unit, true, true] spawn tsp_fnc_gesture_play;
    [[name _unit, "Patted your head"], tsp_fnc_hint] remoteExec ["call", _target];
    [_unit, 5, "", 0] call tsp_fnc_animate_effect; sleep 0.3; 
    [_target, 5, "A3\Sounds_F\characters\footsteps\int_carpet\carpet_int_sprint_HPF_"+str(round random 8 max 1)+".wss", 1] call tsp_fnc_animate_effect;
};
