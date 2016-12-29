params [ "_thispos" ];
private [ "_attacktime", "_ownership", "_grp" ];

sleep 5;

_ownership = [ _thispos ] call F_sectorOwnership;
if ( _ownership != FCLIB_side_enemy ) exitWith {};

if ( FCLIB_blufor_defenders ) then {
	_grp = creategroup FCLIB_side_friendly;
	{ _x createUnit [ _thispos, _grp,'this addMPEventHandler ["MPKilled", {_this spawn kill_manager}]']; } foreach blufor_squad_inf;
};

sleep 3;

_grp setCombatMode "GREEN";
_grp setBehaviour "COMBAT";

sleep 60;

_ownership = [ _thispos ] call F_sectorOwnership;
if ( _ownership == FCLIB_side_friendly ) exitWith {
	if ( FCLIB_blufor_defenders ) then {
		{
			if ( alive _x ) then { deleteVehicle _x };
		} foreach units _grp;
	};
};

[ [ _thispos , 1 ] , "remote_call_fob" ] call BIS_fnc_MP;
_attacktime = FCLIB_vulnerability_timer;

while { _attacktime > 0 && ( _ownership == FCLIB_side_enemy || _ownership == FCLIB_side_resistance ) } do {
	_ownership = [ _thispos ] call F_sectorOwnership;
	_attacktime = _attacktime - 1;
	sleep 1;
};

waitUntil {
	sleep 1;
	[ _thispos ] call F_sectorOwnership != FCLIB_side_resistance;
};

if ( FCLIB_endgame == 0 ) then {
	if ( _attacktime <= 1 && ( [ _thispos ] call F_sectorOwnership == FCLIB_side_enemy ) ) then {
		[ [ _thispos , 2 ] , "remote_call_fob" ] call BIS_fnc_MP;
		sleep 3;
		FCLIB_all_fobs = FCLIB_all_fobs - [_thispos];
		publicVariable "FCLIB_all_fobs";
		reset_battlegroups_ai = true;
		[_thispos] call destroy_fob;
		trigger_server_save = true;
		[] call recalculate_caps;
		stats_fobs_lost = stats_fobs_lost + 1;
	} else {
		[ [ _thispos , 3 ] , "remote_call_fob" ] call BIS_fnc_MP;
		{ [_x] spawn prisonner_ai; } foreach ( [ _thispos nearEntities [ "Man", FCLIB_capture_size * 0.8], { side group _x == FCLIB_side_enemy } ] call BIS_fnc_conditionalSelect );
	};
};

sleep 60;

if ( FCLIB_blufor_defenders ) then {
	{
		if ( alive _x ) then { deleteVehicle _x };
	} foreach units _grp;
};