if ( isNil "FCLIB_respawn_loadout" ) then {
	removeAllWeapons player;
	player linkItem "NVGoggles";
} else {
	sleep 4;
	[ player, FCLIB_respawn_loadout ] call F_setLoadout;
};