params [ "_opforcount" ];
private [ "_corrected_sector_size" ];

if ( _opforcount < 0.5 * FCLIB_sector_cap ) then {
	_corrected_sector_size = FCLIB_sector_size;
} else {
	if ( _opforcount <= FCLIB_sector_cap ) then {
		_corrected_sector_size = FCLIB_sector_size - ( FCLIB_sector_size * 0.5 * (( _opforcount / FCLIB_sector_cap ) - 0.5));
	} else {
		_corrected_sector_size = FCLIB_sector_size * 0.75;
	};
};

_corrected_sector_size