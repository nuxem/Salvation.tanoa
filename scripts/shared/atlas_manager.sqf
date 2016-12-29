if ( isServer ) then {
	_isAtlas = isClass ( configFile / "cfgVehicles" / "ATLAS_B_LHD_helper" );

	if ( _isAtlas ) then {

		[ lhd, [ 'ATLAS_LHD_1','ATLAS_LHD_2','ATLAS_LHD_3','ATLAS_LHD_4','ATLAS_LHD_5','ATLAS_LHD_5a',
		'ATLAS_LHD_6','ATLAS_LHD_7','ATLAS_LHD_house_1','ATLAS_LHD_house_2','ATLAS_LHD_elev_1',
		'ATLAS_LHD_elev_2','ATLAS_LHD_Light2','ATLAS_LHD_Int_1','ATLAS_LHD_Int_2','ATLAS_LHD_Int_3' ] ]
		execVM "ATLAS_Water\scripts\large_object_attach.sqf";
		[ lhd ] execVM "ATLAS_WAter\LHD\scripts\initlights.sqf";
		lhd hideObject true;
		{ deleteVehicle _x } foreach ( ( getmarkerpos "base_Lindsey" ) nearObjects 500 );
		FCLIB_isAtlasPresent = true; publicVariable "FCLIB_isAtlasPresent";
	} else {
		lhd setpos getmarkerpos "base_Lindsey";
		lhd hideObject true;
		{ deleteVehicle _x } foreach ( ( getmarkerpos "lhd" ) nearObjects 500 );
		FCLIB_isAtlasPresent = false; publicVariable "FCLIB_isAtlasPresent";
	};
} else {
	waitUntil { !isNil "FCLIB_isAtlasPresent" };
};

if ( FCLIB_isAtlasPresent ) then {
	deleteMarkerLocal "base_Lindsey";
} else {
	deleteMarkerLocal "lhd";
};