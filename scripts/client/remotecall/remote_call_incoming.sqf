if ( isDedicated ) exitWith {};

params [ "_attack_destination" ];

if ( isNil "FCLIB_last_incoming_notif_time" ) then { FCLIB_last_incoming_notif_time = -9999 };

if ( time > FCLIB_last_incoming_notif_time + 60 ) then {

	FCLIB_last_incoming_notif_time = time;

	private [ "_attack_location_name" ];
	_attack_location_name = [ _attack_destination ] call F_getLocationName;

	[ "lib_incoming", [ _attack_location_name ] ] call BIS_fnc_showNotification;

	private [ "_mrk" ];
	_mrk = createMarkerLocal [ "opfor_incoming_marker", _attack_destination];
	"opfor_incoming_marker" setMarkerTypeLocal "selector_selectedMission";
	"opfor_incoming_marker" setMarkerColorLocal FCLIB_color_enemy_bright;

	sleep 250;
	deleteMarkerLocal _mrk;
};