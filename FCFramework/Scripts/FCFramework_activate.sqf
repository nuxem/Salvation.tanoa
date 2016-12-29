if (isDedicated) then { exit };

waitUntil { alive player };

desiredviewdistance_inf = viewDistance;
desiredviewdistance_veh = viewDistance;
desiredviewdistance_obj = 75;
desired_fps = 0;
show_teammates = false;
show_nametags = false;
show_platoon = false;
desired_vehvolume = 100;

FCFramework_options_profile = profileNamespace getVariable "FCFramework_OPTIONS_PROFILE";
if ( !isNil "FCFramework_options_profile" ) then {
	desiredviewdistance_inf = FCFramework_options_profile select 0;
	desiredviewdistance_veh = FCFramework_options_profile select 1;
	desiredviewdistance_obj = FCFramework_options_profile select 2;
	show_teammates = FCFramework_options_profile select 3;
	show_platoon = FCFramework_options_profile select 4;
	if ( count FCFramework_options_profile > 5 ) then {
		desired_vehvolume = FCFramework_options_profile select 5;
		if ( isNil "desired_vehvolume" ) then {
			desired_vehvolume = 100;
		};
	};
	if ( count FCFramework_options_profile > 6 ) then {
		show_nametags = FCFramework_options_profile select 6;
		if ( isNil "show_nametags" ) then {
			show_nametags = false;
		};
	};
	if ( count FCFramework_options_profile > 7) then {
		desired_fps = FCFramework_options_profile select 7;
		if ( isNil "desired_fps" ) then {
			desired_fps = 0;
		};
	};
};

[] call compile preprocessFileLineNumbers "FCFramework\FCFramework_config.sqf";
[] call compile preprocessFileLineNumbers "FCFramework\scripts\FCFramework_version.sqf";
[] spawn compile preprocessFileLineNumbers "FCFramework\scripts\FCFramework_actionmanager.sqf";
[] spawn compile preprocessFileLineNumbers "FCFramework\scripts\FCFramework_revive_camera.sqf";
[] spawn compile preprocessFileLineNumbers "FCFramework\scripts\FCFramework_medic_listener.sqf";
if ( FCFramework_allow_mapmarkers ) then { [] spawn compile preprocessFileLineNumbers "FCFramework\scripts\FCFramework_playermarkers.sqf"; };
if ( FCFramework_allow_platoonview ) then { [] spawn compile preprocessFileLineNumbers "FCFramework\scripts\FCFramework_platoonoverlay.sqf"; };
if ( FCFramework_allow_platoonview ) then { [] spawn compile preprocessFileLineNumbers "FCFramework\scripts\FCFramework_cache_units.sqf"; };
if ( FCFramework_allow_customsquads ) then { [] spawn compile preprocessFileLineNumbers "FCFramework\scripts\FCFramework_squadmanagement.sqf"; };
if ( FCFramework_allow_viewdistance ) then { [] spawn compile preprocessFileLineNumbers "FCFramework\scripts\FCFramework_view_distance_management.sqf"; };
[] spawn compile preprocessFileLineNumbers "FCFramework\scripts\FCFramework_dynamic_view_distance.sqf";
