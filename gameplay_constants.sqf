FCLIB_save_key = "FCFramework_salvation_SAVEGAME";	// change this value if you want different savegames on different map

FCLIB_side_friendly = WEST;
FCLIB_side_enemy = EAST;
FCLIB_side_resistance = RESISTANCE;
FCLIB_side_civilian = CIVILIAN;
FCLIB_respawn_marker = "respawn_west";
FCLIB_color_friendly = "ColorBLUFOR";
FCLIB_color_enemy = "ColorOPFOR";
FCLIB_color_enemy_bright = "ColorRED";

FCLIB_sector_size = 1000;
FCLIB_capture_size = 175;
FCLIB_radiotower_size = 2500;
FCLIB_recycling_percentage = 0.65;
FCLIB_endgame = 0;
FCLIB_vulnerability_timer = 1200;
FCLIB_defended_buildingpos_part = 0.4;
FCLIB_sector_military_value = 3;
FCLIB_secondary_objective_impact = 0.6;
FCLIB_blufor_cap = 100								* FCLIB_unitcap;
FCLIB_sector_cap = 180								* FCLIB_unitcap;
FCLIB_battlegroup_cap = 150							* FCLIB_unitcap;
FCLIB_patrol_cap = 150								* FCLIB_unitcap;
FCLIB_battlegroup_size = 6							* (sqrt FCLIB_unitcap) * (sqrt FCLIB_csat_aggressivity);
FCLIB_civilians_amount = 10 						* FCLIB_civilian_activity;
FCLIB_fob_range = 125;
FCLIB_cleanup_delay = 1200;
FCLIB_surrender_chance = 80;
FCLIB_secondary_missions_costs = [ 10, 10, 10 ];
FCLIB_halo_altitude = 4000;
FCLIB_civ_killing_penalty = 20;

if ( FCLIB_blufor_cap > 100 ) then { FCLIB_blufor_cap = 100 }; // Don't forget that the human commander manages those, not the server

FCLIB_offload_diag = false;