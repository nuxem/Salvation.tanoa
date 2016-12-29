if ( !isServer ) exitWith {};
if ( isNil "FCLIB_secondary_starting" ) then { FCLIB_secondary_starting = false; };
if ( FCLIB_secondary_starting ) exitWith { diag_log "Multiple calls to start secondary mission : shouldn't be possible, isn't allowed"; };
if ( isNil "used_positions" ) then { used_positions = []; };

FCLIB_secondary_starting = true; publicVariable "FCLIB_secondary_starting";
params [ "_mission_index" ];

resources_intel = resources_intel - ( FCLIB_secondary_missions_costs select _mission_index );

if ( _mission_index == 0 ) then { [] call fob_hunting; };
if ( _mission_index == 1 ) then { [] call convoy_hijack; };
if ( _mission_index == 2 ) then { [] call search_and_rescue; };

FCLIB_secondary_starting = false; publicVariable "FCLIB_secondary_starting";