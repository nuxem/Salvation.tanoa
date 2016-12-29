if ( isNil "FCLIB_arsenal_weapons" ) then { FCLIB_arsenal_weapons = [] };
if ( count FCLIB_arsenal_weapons == 0 ) then {
	[ missionNamespace, true ] call BIS_fnc_addVirtualWeaponCargo;
} else {
	[ missionNamespace, FCLIB_arsenal_weapons ] call BIS_fnc_addVirtualWeaponCargo;
};

if ( isNil "FCLIB_arsenal_magazines" ) then { FCLIB_arsenal_magazines = [] };
if ( count FCLIB_arsenal_magazines == 0 ) then {
	[ missionNamespace, true ] call BIS_fnc_addVirtualMagazineCargo;
} else {
	[ missionNamespace, FCLIB_arsenal_magazines ] call BIS_fnc_addVirtualMagazineCargo;
};

if ( isNil "FCLIB_arsenal_items" ) then { FCLIB_arsenal_items = [] };
if ( count FCLIB_arsenal_items == 0 ) then {
	[ missionNamespace, true ] call BIS_fnc_addVirtualItemCargo;
} else {
	[ missionNamespace, FCLIB_arsenal_items ] call BIS_fnc_addVirtualItemCargo;
};

if ( isNil "FCLIB_arsenal_backpacks" ) then { FCLIB_arsenal_backpacks = [] };
if ( count FCLIB_arsenal_backpacks == 0 ) then {
	private _virtualStuff = [] call LARs_fnc_addAllVirtualCargo;
	private _virtualBackpacks = [];
	{ if ( !(_x in FCLIB_blacklisted_from_arsenal) ) then { _virtualBackpacks pushback _x } } foreach (_virtualStuff);

	[ missionNamespace, _virtualBackpacks ] call BIS_fnc_addVirtualBackpackCargo;
} else {
	[ missionNamespace, FCLIB_arsenal_backpacks ] call BIS_fnc_addVirtualBackpackCargo;
};