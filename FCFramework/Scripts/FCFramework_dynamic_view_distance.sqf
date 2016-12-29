FCFramework_view_distance_factor = 1.0;
FCFramework_force_adjust_view_distance = false;
private _min_view_distance_factor = 0.25;
private _base_increment = 0.075;
private _corrected_increment = -1;
private _consecutive_before_adjust = 3;
private _consecutive_fps_too_low = 0;
private _consecutive_fps_too_fast = 0;
private _smoothing_margin = 0.1;

while { true } do {

	_corrected_increment = _base_increment * FCFramework_view_distance_factor;

	if ( (diag_fps * ( 1 - _smoothing_margin )) < desired_fps ) then {
		_consecutive_fps_too_low = _consecutive_fps_too_low + 1;
		_consecutive_fps_too_fast = 0;
	};

	if ( (diag_fps * ( 1 + _smoothing_margin )) > desired_fps ) then {
		_consecutive_fps_too_fast = _consecutive_fps_too_fast + 1;
		_consecutive_fps_too_low = 0;
	};

	if ( FCFramework_view_distance_factor > _min_view_distance_factor && _consecutive_fps_too_low >= _consecutive_before_adjust ) then {
		_consecutive_fps_too_low = 0;
		FCFramework_view_distance_factor = FCFramework_view_distance_factor - _corrected_increment;
		if ( FCFramework_view_distance_factor < _min_view_distance_factor ) then {
			FCFramework_view_distance_factor = _min_view_distance_factor;
		};
		FCFramework_force_adjust_view_distance = true;
	};

	if ( FCFramework_view_distance_factor < 1.0 && _consecutive_fps_too_fast >= _consecutive_before_adjust ) then {
		_consecutive_fps_too_fast = 0;
		FCFramework_view_distance_factor = FCFramework_view_distance_factor + _corrected_increment;
		if ( FCFramework_view_distance_factor > 1.0 ) then {
			FCFramework_view_distance_factor = 1.0;
		};
		FCFramework_force_adjust_view_distance = true;
	};

	sleep 0.75;
};