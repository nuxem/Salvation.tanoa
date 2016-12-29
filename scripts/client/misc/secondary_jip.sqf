waitUntil {
	time > 20;
};

if ( isNil "FCLIB_secondary_in_progress" ) exitWith {};
if ( FCLIB_secondary_in_progress < 0 ) exitWith {};

if ( FCLIB_secondary_in_progress == 0 ) then {
	[ 2 ] call remote_call_intel;
};