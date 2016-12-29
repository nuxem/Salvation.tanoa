if ( !(isNil "FCLIB_param_wipe_savegame_1") && !(isNil "FCLIB_param_wipe_savegame_2") ) then {
	if ( FCLIB_param_wipe_savegame_1 == 1 && FCLIB_param_wipe_savegame_2 == 1 ) then {
		profileNamespace setVariable [ FCLIB_save_key,nil ];
		saveProfileNamespace;
	};
};

date_year = date select 0;
date_month = date select 1;
date_day = date select 2;
blufor_sectors = [];
FCLIB_all_fobs = [];
buildings_to_save= [];
combat_readiness = 0;
saved_ammo_res = 0;
stats_opfor_soldiers_killed = 0;
stats_opfor_killed_by_players = 0;
stats_blufor_soldiers_killed = 0;
stats_player_deaths = 0;
stats_opfor_vehicles_killed = 0;
stats_opfor_vehicles_killed_by_players = 0;
stats_blufor_vehicles_killed = 0;
stats_blufor_soldiers_recruited = 0;
stats_blufor_vehicles_built = 0;
stats_civilians_killed = 0;
stats_civilians_killed_by_players = 0;
stats_sectors_liberated = 0;
stats_playtime = 0;
stats_spartan_respawns = 0;
stats_secondary_objectives = 0;
stats_hostile_battlegroups = 0;
stats_ieds_detonated = 0; publicVariable "stats_ieds_detonated";
stats_saves_performed = 0;
stats_saves_loaded = 0;
stats_reinforcements_called = 0;
stats_prisonners_captured = 0;
stats_blufor_teamkills = 0;
stats_vehicles_recycled = 0;
stats_ammo_spent = 0;
stats_sectors_lost = 0;
stats_fobs_built = 0;
stats_fobs_lost = 0;
stats_readiness_earned = 0;
infantry_weight = 33;
armor_weight = 33;
air_weight = 33;
FCLIB_vehicle_to_military_base_links = [];
FCLIB_permissions = [];
ai_groups = [];
saved_intel_res = 0;
FCLIB_player_scores = [];

no_kill_handler_classnames = [FOB_typename, huron_typename];
_classnames_to_save = [FOB_typename, huron_typename];
_classnames_to_save_blu = [];
_building_classnames = [FOB_typename];
{
	no_kill_handler_classnames pushback (_x select 0);
	_classnames_to_save pushback (_x select 0);
	_building_classnames pushback (_x select 0);
} foreach buildings;

{
	_classnames_to_save_blu pushback (_x select 0);
} foreach (static_vehicles + air_vehicles + heavy_vehicles + light_vehicles + support_vehicles);

_classnames_to_save = _classnames_to_save + _classnames_to_save_blu + all_hostile_classnames;

trigger_server_save = false;
FCFramework_salvation_savegame = profileNamespace getVariable FCLIB_save_key;

if ( !isNil "FCFramework_salvation_savegame" ) then {

	blufor_sectors = FCFramework_salvation_savegame select 0;
	FCLIB_all_fobs = FCFramework_salvation_savegame select 1;
	buildings_to_save = FCFramework_salvation_savegame select 2;
	time_of_day = FCFramework_salvation_savegame select 3;
	combat_readiness = FCFramework_salvation_savegame select 4;
	saved_ammo_res = FCFramework_salvation_savegame select 8;

	if ( "capture_13_1_2_26_25" in blufor_sectors ) then { // Patching Molos Airfield which was a town instead of a factory
		blufor_sectors = blufor_sectors - [ "capture_13_1_2_26_25" ];
		blufor_sectors = blufor_sectors + [ "factory666" ];
	};

	if ( count FCFramework_salvation_savegame > 9 ) then {
		_stats = FCFramework_salvation_savegame select 9;
		stats_opfor_soldiers_killed = _stats select 0;
		stats_opfor_killed_by_players = _stats select 1;
		stats_blufor_soldiers_killed = _stats select 2;
		stats_player_deaths = _stats select 3;
		stats_opfor_vehicles_killed = _stats select 4;
		stats_opfor_vehicles_killed_by_players = _stats select 5;
		stats_blufor_vehicles_killed = _stats select 6;
		stats_blufor_soldiers_recruited = _stats select 7;
		stats_blufor_vehicles_built = _stats select 8;
		stats_civilians_killed = _stats select 9;
		stats_civilians_killed_by_players = _stats select 10;
		stats_sectors_liberated = _stats select 11;
		stats_playtime = _stats select 12;
		stats_spartan_respawns = _stats select 13;
		stats_secondary_objectives = _stats select 14;
		stats_hostile_battlegroups = _stats select 15;
		stats_ieds_detonated = _stats select 16; publicVariable "stats_ieds_detonated";
		stats_saves_performed = _stats select 17;
		stats_saves_loaded = _stats select 18;
		stats_reinforcements_called = _stats select 19;
		stats_prisonners_captured = _stats select 20;
		stats_blufor_teamkills = _stats select 21;
		stats_vehicles_recycled = _stats select 22;
		stats_ammo_spent = _stats select 23;
		stats_sectors_lost = _stats select 24;
		stats_fobs_built = _stats select 25;
		stats_fobs_lost = _stats select 26;
		stats_readiness_earned = _stats select 27;
	};

	if ( count FCFramework_salvation_savegame > 10 ) then {
		_weights = FCFramework_salvation_savegame select 10;
		infantry_weight = _weights select 0;
		armor_weight = _weights select 1;
		air_weight = _weights select 2;
	};

	if ( count FCFramework_salvation_savegame > 11 ) then {
		FCLIB_vehicle_to_military_base_links = FCFramework_salvation_savegame select 11;
	};

	if ( count FCFramework_salvation_savegame > 12 ) then {
		FCLIB_permissions = FCFramework_salvation_savegame select 12;
	};

	if ( count FCFramework_salvation_savegame > 13 ) then {
		ai_groups = FCFramework_salvation_savegame select 13;
	};

	if ( count FCFramework_salvation_savegame > 14 ) then {
		saved_intel_res = FCFramework_salvation_savegame select 14;
	};

	if ( count FCFramework_salvation_savegame > 15 ) then {
		FCLIB_player_scores = FCFramework_salvation_savegame select 15;
	};

	setDate [ 2045, 6, 6, time_of_day, 0];

	_correct_fobs = [];
	{
		_next_fob = _x;
		_keep_fob = true;
		{
			if ( _next_fob distance (markerpos _x) < 50 ) exitWith { _keep_fob = false };
		} foreach sectors_allSectors;
		if ( _keep_fob ) then { _correct_fobs pushback _next_fob };
	} foreach FCLIB_all_fobs;
	FCLIB_all_fobs = _correct_fobs;

	stats_saves_loaded = stats_saves_loaded + 1;

	{
		_nextclass = _x select 0;

		if ( _nextclass in _classnames_to_save ) then {

			_nextpos = _x select 1;
			_nextdir = _x select 2;
			_hascrew = false;
			if ( count _x > 3 ) then {
				_hascrew = _x select 3;
			};
			_nextbuilding = _nextclass createVehicle _nextpos;
			_nextbuilding setVectorUp [0,0,1];
			_nextbuilding setPosATL _nextpos;
			_nextbuilding setdir _nextdir;
			_nextbuilding setdamage 0;

			if ( _nextclass in _building_classnames ) then {
				_nextbuilding setVariable [ "FCLIB_saved_pos", _nextpos, false ];
			};

			if ( _hascrew ) then {
				[ _nextbuilding ] call F_forceBluforCrew;
			};

			if ( !(_nextclass in no_kill_handler_classnames ) ) then {
				_nextbuilding addMPEventHandler ["MPKilled", {_this spawn kill_manager}];
			};

			if ( _nextclass in all_hostile_classnames ) then {
				_nextbuilding setVariable [ "FCLIB_captured", 1, true ];
			};

			if ( _nextclass == FOB_typename ) then {
				_nextbuilding addEventHandler ["HandleDamage", { 0 }];
			};
		};

	} foreach buildings_to_save;

	{
		private [ "_nextgroup", "_grp" ];
		_nextgroup = _x;
		_grp = createGroup FCLIB_side_friendly;

		{
			private [ "_nextunit", "_nextpos", "_nextdir", "_nextobj"];
			_nextunit = _x;
			_nextpos = [(_nextunit select 1) select 0, (_nextunit select 1) select 1, ((_nextunit select 1) select 2) + 0.2];
			_nextdir = _nextunit select 2;
			(_nextunit select 0) createUnit [ _nextpos, _grp, 'this addMPEventHandler ["MPKilled", {_this spawn kill_manager}] '];
			_nextobj = ((units _grp) select ((count (units _grp)) - 1));
			_nextobj setPosATL _nextpos;
			_nextobj setDir _nextdir;
		} foreach _nextgroup;
	} foreach ai_groups;
};

publicVariable "blufor_sectors";
publicVariable "FCLIB_all_fobs";

if ( count FCLIB_vehicle_to_military_base_links == 0 ) then {
	private [ "_assigned_bases", "_assigned_vehicles", "_nextbase", "_nextvehicle" ];
	_assigned_bases = [];
	_assigned_vehicles = [];

	while { count _assigned_bases < count sectors_military && count _assigned_vehicles < count elite_vehicles } do {
		_nextbase =  ( [ sectors_military, { !(_x in _assigned_bases) } ] call BIS_fnc_conditionalSelect ) call BIS_fnc_selectRandom;
		_nextvehicle =  ( [ elite_vehicles, { !(_x in _assigned_vehicles) } ] call BIS_fnc_conditionalSelect ) call BIS_fnc_selectRandom;
		_assigned_bases pushback _nextbase;
		_assigned_vehicles pushback _nextvehicle;
		FCLIB_vehicle_to_military_base_links pushback [_nextvehicle, _nextbase];
	};
} else {
	_classnames_to_check = FCLIB_vehicle_to_military_base_links;
	{
		if ( ! ( [ _x select 0 ] call F_checkClass ) ) then {
			FCLIB_vehicle_to_military_base_links = FCLIB_vehicle_to_military_base_links - [_x];
		};
	} foreach _classnames_to_check;
};
publicVariable "FCLIB_vehicle_to_military_base_links";
publicVariable "FCLIB_permissions";
save_is_loaded = true; publicVariable "save_is_loaded";

while { true } do {
	waitUntil {
		sleep 0.3;
		trigger_server_save || FCLIB_endgame == 1;
	};

	if ( FCLIB_endgame == 1 ) then {
		profileNamespace setVariable [ FCLIB_save_key, nil ];
		saveProfileNamespace;
		while { true } do { sleep 300; };
	} else {

		trigger_server_save = false;
		buildings_to_save = [];
		ai_groups = [];

		_all_buildings = [];
		{
			_fobpos = _x;
			_nextbuildings = [ _fobpos nearobjects (FCLIB_fob_range * 2), {
				((typeof _x) in _classnames_to_save ) &&
				( alive _x) &&
				( speed _x < 5 ) &&
				( isNull  attachedTo _x ) &&
				(((getpos _x) select 2) < 10 ) &&
				( getObjectType _x >= 8 )
 				} ] call BIS_fnc_conditionalSelect;

			_all_buildings = _all_buildings + _nextbuildings;

			{
				_nextgroup = _x;
				if (  side _nextgroup == FCLIB_side_friendly ) then {
					if ( { isPlayer _x } count ( units _nextgroup ) == 0 ) then {
						if ( { alive _x } count ( units _nextgroup ) > 0  ) then {
							if ( _fobpos distance (leader _nextgroup) < FCLIB_fob_range * 2 ) then {
								private [ "_grouparray" ];
								_grouparray = [];
								{
									if ( alive _x && (vehicle _x == _x ) ) then {
										_grouparray pushback [ typeof _x, getPosATL _x, getDir _x ];
									};
								} foreach (units _nextgroup);

								ai_groups pushback _grouparray;
							};
						};
					};
				};
			} foreach allGroups;
		} foreach FCLIB_all_fobs;

		{
			private _savedpos = [];

			if ( (typeof _x) in _building_classnames ) then {
				_savedpos = _x getVariable [ "FCLIB_saved_pos", [] ];
				if ( count _savedpos == 0 ) then {
					_x setVariable [ "FCLIB_saved_pos", getposATL _x, false ];
					_savedpos = getposATL _x;
				};
			} else {
				_savedpos = getposATL _x;
			};

			private _nextclass = typeof _x;
			private _nextdir = getdir _x;
			private _hascrew = false;
			if ( _nextclass in _classnames_to_save_blu ) then {
				if ( ( { !isPlayer _x } count (crew _x) ) > 0 ) then {
					_hascrew = true;
				};
			};
			buildings_to_save pushback [ _nextclass,_savedpos,_nextdir,_hascrew ];
		} foreach _all_buildings;

		time_of_day = date select 3;

		stats_saves_performed = stats_saves_performed + 1;

		private [ "_newscores", "_knownplayers", "_playerindex", "_nextplayer" ];
		_knownplayers = [];
		_newscores = [] + FCLIB_player_scores;
		{ _knownplayers pushback (_x select 0) } foreach FCLIB_player_scores;

		{
			_nextplayer = _x;

			if ( score _nextplayer >= 20 ) then {
				_playerindex = _knownplayers find (getPlayerUID _nextplayer);
				if ( _playerindex >= 0 ) then {
					_newscores set [ _playerindex, [ getPlayerUID _x, score _x] ];
				} else {
					_newscores pushback [ getPlayerUID _x, score _x ];
				};
			};
		} foreach allPlayers;
		FCLIB_player_scores = _newscores;

		_stats = [];
		_stats pushback stats_opfor_soldiers_killed;
		_stats pushback stats_opfor_killed_by_players;
		_stats pushback stats_blufor_soldiers_killed;
		_stats pushback stats_player_deaths;
		_stats pushback stats_opfor_vehicles_killed;
		_stats pushback stats_opfor_vehicles_killed_by_players;
		_stats pushback stats_blufor_vehicles_killed;
		_stats pushback stats_blufor_soldiers_recruited;
		_stats pushback stats_blufor_vehicles_built;
		_stats pushback stats_civilians_killed;
		_stats pushback stats_civilians_killed_by_players;
		_stats pushback stats_sectors_liberated;
		_stats pushback stats_playtime;
		_stats pushback stats_spartan_respawns;
		_stats pushback stats_secondary_objectives;
		_stats pushback stats_hostile_battlegroups;
		_stats pushback stats_ieds_detonated;
		_stats pushback stats_saves_performed;
		_stats pushback stats_saves_loaded;
		_stats pushback stats_reinforcements_called;
		_stats pushback stats_prisonners_captured;
		_stats pushback stats_blufor_teamkills;
		_stats pushback stats_vehicles_recycled;
		_stats pushback stats_ammo_spent;
		_stats pushback stats_sectors_lost;
		_stats pushback stats_fobs_built;
		_stats pushback stats_fobs_lost;
		_stats pushback stats_readiness_earned;

		FCFramework_salvation_savegame = [ blufor_sectors, FCLIB_all_fobs, buildings_to_save, time_of_day, round combat_readiness,0,0,0, round resources_ammo, _stats,
		[ round infantry_weight, round armor_weight, round air_weight ], FCLIB_vehicle_to_military_base_links, FCLIB_permissions, ai_groups, resources_intel, FCLIB_player_scores ];

		profileNamespace setVariable [ FCLIB_save_key, FCFramework_salvation_savegame ];
		saveProfileNamespace;

	};
};