private [ "_minfobdist", "_minsectordist", "_distfob", "_clearedtobuildfob", "_distsector", "_clearedtobuildsector", "_idx" ];

if ( count FCLIB_all_fobs >= FCLIB_maximum_fobs ) exitWith {
	hint format [ localize "STR_HINT_FOBS_EXCEEDED", FCLIB_maximum_fobs ];
};

_minfobdist = 1000;
_minsectordist = FCLIB_capture_size + FCLIB_fob_range;
_distfob = 1;
_clearedtobuildfob = true;
_distsector = 1;
_clearedtobuildsector = true;

_idx = 0;
while { (_idx < (count FCLIB_all_fobs)) && _clearedtobuildfob } do {
	if ( player distance (FCLIB_all_fobs select _idx) < _minfobdist ) then {
		_clearedtobuildfob = false;
		_distfob = player distance (FCLIB_all_fobs select _idx);
	};
	_idx = _idx + 1;
};

_idx = 0;
if(_clearedtobuildfob) then {
	while { (_idx < (count sectors_allSectors)) && _clearedtobuildsector } do {
		if ( player distance (getmarkerpos (sectors_allSectors select _idx)) < _minsectordist ) then {
			_clearedtobuildsector = false;
			_distsector = player distance (getmarkerpos (sectors_allSectors select _idx));
		};
		_idx = _idx + 1;
	};
};

if (!_clearedtobuildfob) then {
	hint format [localize "STR_FOB_BUILDING_IMPOSSIBLE",floor _minfobdist,floor _distfob];
} else {
	if ( !_clearedtobuildsector ) then {
		hint format [localize "STR_FOB_BUILDING_IMPOSSIBLE_SECTOR",floor _minsectordist,floor _distsector];
	} else {
		buildtype = 99;
		dobuild = 1;
	};
};
